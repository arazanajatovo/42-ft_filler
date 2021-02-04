/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct_char.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 11:48:56 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/22 08:22:51 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_char_width(t_pars *pars, char **str, char *c)
{
	c = (*pars).opt.zero ? "0" : " ";
	(*pars).width -= 1;
	while ((*pars).width > 0)
	{
		if ((*pars).opt.minus && (!(*str = ft_strjoin_clean(*str, c, 1))))
			return (0);
		else if (!(*pars).opt.minus &&
				(!(*str = ft_strjoin_clean(c, *str, 2))))
			return (0);
		(*pars).width--;
	}
	return (1);
}

int		ft_char(t_func tab, t_pars *pars)
{
	char	*str;

	(void)tab;
	if (!(str = ft_strnew(1)))
		return (0);
	str[0] = (*pars).input.c;
	if ((*pars).b_width && !(ft_char_width(pars, &str, NULL)))
		return (0);
	if ((*pars).input.c == 0 && (*pars).opt.minus)
	{
		write(1, &(*pars).input.c, 1);
		(*pars).ret++;
	}
	(*pars).ret += ft_putstr(str);
	if ((*pars).input.c == 0 && !(*pars).opt.minus)
	{
		write(1, &(*pars).input.c, 1);
		(*pars).ret++;
	}
	free(str);
	return (1);
}

int		ft_str_width(t_pars *pars, char **str, int len, char *c)
{
	c = (*pars).opt.zero ? "0" : " ";
	(*pars).width -= len;
	while ((*pars).width > 0)
	{
		if ((*pars).opt.minus && (!(*str = ft_strjoin_clean(*str, c, 1))))
			return (0);
		else if (!(*pars).opt.minus &&
				(!(*str = ft_strjoin_clean(c, *str, 2))))
			return (0);
		(*pars).width--;
	}
	return (1);
}

int		ft_str(t_func tab, t_pars *pars)
{
	char	*str;
	int		len;

	(void)tab;
	if (!(*pars).input.str)
		(*pars).input.str = "(null)";
	len = ft_strlen((*pars).input.str);
	if ((*pars).b_acc)
		len = len < (*pars).acc ? len : (*pars).acc;
	if (!(str = ft_strnew(len)))
		return (0);
	str = ft_strncpy(str, (*pars).input.str, len);
	if ((*pars).b_width && !(ft_str_width(pars, &str, len, NULL)))
		return (0);
	(*pars).ret += ft_putstr(str);
	free(str);
	return (1);
}
