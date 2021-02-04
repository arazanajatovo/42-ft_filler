/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 07:56:20 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/27 21:37:40 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_special_float(t_pars *pars)
{
	int		ret;

	ret = 1;
	if ((*pars).input.f == 1.0 / 0.0)
		(*pars).input.str = (*pars).opt.plus ? "+inf" : "inf";
	else if ((*pars).input.f == -1.0 / 0.0)
		(*pars).input.str = "-inf";
	else if ((*pars).input.f != (*pars).input.f)
		(*pars).input.str = "nan";
	else if (1 / (*pars).input.f < 0)
	{
		(*pars).neg = 1;
		(*pars).opt.plus = 1;
		option_cancel(pars);
		ret = 0;
	}
	else
		ret = 0;
	return (ret);
}

int		ft_iseven(char c)
{
	if (c == '0' || c == '2' || c == '4' || c == '6' || c == '8')
		return (1);
	return (0);
}

int		ft_check_opt(const char c, t_pars *pars)
{
	if (c == '-')
		(*pars).opt.minus = 1;
	else if (c == '+')
		(*pars).opt.plus = 1;
	else if (c == '#')
		(*pars).opt.hash = 1;
	else if (c == '0')
		(*pars).opt.zero = 1;
	else if (c == ' ')
		(*pars).opt.space = 1;
	else
		return (0);
	return (1);
}

int		ft_check_flag(const char *c, t_pars *pars)
{
	if (*c == 'h')
	{
		if (*(c + 1) == 'h')
			(*pars).flag.hh = 1;
		else
			(*pars).flag.h = 1;
	}
	else if (*c == 'l')
	{
		if (*(c + 1) == 'l')
			(*pars).flag.ll = 1;
		else
			(*pars).flag.l = 1;
	}
	else if (*c == 'L')
		(*pars).flag.gl = 1;
	else
		return (0);
	if (*c == *(c + 1))
		(*pars).b_flag = 2;
	else
		(*pars).b_flag = 1;
	return ((*pars).b_flag);
}

int		ft_check_type(const char c, t_pars *pars)
{
	if (c == 's' || c == 'c' || c == 'd' || c == 'i' || c == 'u' || c == 'o' ||
			c == 'x' || c == 'X' || c == 'b' || c == 'p' || c == 'f' ||
			c == '%')
		(*pars).type = c;
	else
		return (0);
	return (1);
}
