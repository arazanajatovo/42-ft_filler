/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 07:56:11 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/27 21:08:41 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	option_cancel(t_pars *pars)
{
	if ((((*pars).nb == 2 || (*pars).nb == 3) && (*pars).neg)
			|| (*pars).nb == 1 || (*pars).nb == 11
			|| (*pars).opt.plus || ((*pars).nb != 2 && (*pars).nb != 3
				&& (*pars).nb != 10))
		(*pars).opt.space = 0;
	if ((((*pars).b_acc && (((*pars).nb >= 2 && (*pars).nb <= 8)))
				|| (*pars).opt.minus))
		(*pars).opt.zero = 0;
	if ((*pars).nb == 9)
		(*pars).acc = 0;
	if (((*pars).nb == 0 || (*pars).nb == 1 || (*pars).nb == 2
				|| (*pars).nb == 3 || (*pars).nb == 4 || (*pars).nb == 8
				|| (*pars).nb == 9 || (*pars).nb == 11)
				|| ((*pars).input.u == 0 && (*pars).nb != 10))
	{
		if ((*pars).opt.hash && (*pars).nb == 5 &&
				(*pars).b_acc && !(*pars).acc)
			(*pars).opt.hash = 1;
		else
			(*pars).opt.hash = 0;
	}
	if ((*pars).nb != 2 && (*pars).nb != 3 && (*pars).nb != 10)
		(*pars).opt.plus = 0;
}

void	ft_check_acc(const char *c, t_pars *pars, va_list ap)
{
	if (*c == '*')
		(*pars).acc = va_arg(ap, int);
	else if (ft_isdigit(*c))
		(*pars).acc = ft_atoi(c);
	else
		(*pars).acc = 0;
	(*pars).b_acc = 1;
	if ((*pars).acc < 0)
		(*pars).b_acc = 0;
}

int		ft_check_width_acc(const char *c, t_pars *pars, va_list ap, int b)
{
	int		ret;

	ret = 0;
	if (b == 1)
	{
		if (*c == '*')
		{
			if (((*pars).width = va_arg(ap, int)) < 0)
			{
				(*pars).width *= -1;
				(*pars).opt.minus = 1;
			}
		}
		else
			(*pars).width = ft_atoi(c);
		(*pars).b_width = 1;
	}
	else
		ft_check_acc(c, pars, ap);
	if (*c == '*')
		ret = 1;
	else
		while (ft_isdigit(*(c++)))
			ret++;
	return (ret);
}

int		ft_unknown_char(const char *format, t_pars *pars, t_func tab, int i)
{
	(*pars).input.c = *format;
	tab.f[12](tab, pars);
	return (i + 1);
}

int		parse_it(const char *format, t_pars *pars, t_func tab, va_list ap)
{
	int		i;
	int		move;

	i = 0;
	while (!ft_check_type(*format, pars) && *format)
	{
		move = 0;
		if (ft_check_opt(*format, pars))
			move++;
		else if (ft_isdigit(*format) || *format == '*')
			move += ft_check_width_acc(format, pars, ap, 1);
		else if (*format == '.')
			move += ft_check_width_acc(format + 1, pars, ap, 2) + 1;
		else
			move += ft_check_flag(format, pars);
		if (!move)
			return (ft_unknown_char(format, pars, tab, i));
		format += move;
		i += move;
	}
	if ((*pars).type)
		return (i + 1);
	return (i);
}
