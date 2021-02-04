/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct_int.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/24 14:00:30 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/22 09:20:54 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_char_supp(t_pars *pars)
{
	char	*c;
	int		len;

	if ((*pars).nb == 8 || (((*pars).nb == 6 || (*pars).nb == 7
			|| (*pars).nb == 5) && (*pars).opt.hash))
	{
		c = (*pars).nb == 5 ? "0" : "0x";
		len = ft_strlen(c);
		if ((*pars).width - len < 0)
			(*pars).width = 0;
		else
			(*pars).width -= len;
		(*pars).opt.plus = 1;
	}
	else
		c = (*pars).neg ? "-" : "+";
	return (c);
}

char	*ft_width_int(t_pars pars, char *str)
{
	char	c;
	char	*c2;
	char	*width;

	c = pars.opt.zero ? '0' : ' ';
	c2 = ft_char_supp(&pars);
	if (!(width = ft_strnew(pars.width)))
		return (NULL);
	width[pars.width--] = '\0';
	while (pars.width >= 0)
		width[pars.width--] = c;
	if (pars.opt.plus)
	{
		if (pars.opt.zero && (!(width = ft_strjoin_clean(c2, width, 2))))
			return (NULL);
		else if (!pars.opt.zero && (!(str = ft_strjoin_clean(c2, str, 2))))
			return (NULL);
	}
	if (pars.opt.minus && (!(str = ft_strjoin_clean(str, width, 1))))
		return (NULL);
	else if (!pars.opt.minus && (!(str = ft_strjoin_clean(width, str, 2))))
		return (NULL);
	free(width);
	return (str);
}

char	*ft_acc_int(t_pars pars, char *str)
{
	char	*acc;
	char	*tmp;

	tmp = str;
	if (!(acc = ft_strnew(pars.acc)))
		return (NULL);
	acc[pars.acc--] = '\0';
	while (pars.acc >= 0)
		acc[pars.acc--] = '0';
	if (!(str = ft_strjoin(acc, str)))
		return (NULL);
	free(tmp);
	free(acc);
	return (str);
}

int		ft_int_opt(t_pars *pars, char **str, char *c)
{
	if ((*pars).b_width &&
			((*pars).width -= (ft_strlen(*str) +
				(*pars).opt.plus) + (*pars).opt.space) > 0)
	{
		(*pars).b_width = 2;
		if (!(*str = ft_width_int(*pars, *str)))
			return (0);
	}
	c = (*pars).neg ? "-" : "+";
	if ((*pars).b_width != 2 && (*pars).opt.plus
			&& (!(*str = ft_strjoin_clean(c, *str, 2))))
		return (0);
	if ((*pars).opt.space && (!(*str = ft_strjoin_clean(" ", *str, 2))))
		return (0);
	return (1);
}

int		ft_int(t_func tab, t_pars *pars)
{
	char	*str;

	if (!(str = ft_litoa_base((*pars).input.i, tab.base[(*pars).nb], *pars)))
		return (0);
	if ((*pars).input.i == 0 && (*pars).b_acc == 1
			&& (*pars).acc == 0 && !(*pars).opt.hash)
	{
		free(str);
		if (!(str = ft_strnew(0)))
			return (0);
	}
	if ((*pars).b_acc && ((*pars).acc -= ft_strlen(str)) > 0)
		if (!(str = ft_acc_int(*pars, str)))
			return (0);
	if (!(ft_int_opt(pars, &str, NULL)))
		return (0);
	(*pars).ret += ft_putstr(str);
	free(str);
	return (1);
}
