/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct_float.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/21 16:18:35 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/27 21:13:58 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_round(char *str, int i, int b, t_pars *pars)
{
	int		move;

	if (i != 0)
		move = str[i - 1] == '.' ? 2 : 1;
	if (str[i] >= '5' || b == 1)
	{
		if (str[i + 1] || str[i] != '5' || !ft_iseven(str[i - move])
				|| (*pars).input.f != (float)0)
		{
			if (i != 0)
				str[i - move]++;
			else
			{
				if (!(str = ft_strjoin_clean("1", str, 2)))
					return (NULL);
				return (str);
			}
		}
	}
	if (str[i - move] > '9')
	{
		str[i - move] = '0';
		return (ft_round(str, i - move, 1, pars));
	}
	return (str);
}

int		ft_str_float(char **str, char **str2, t_pars *pars, char *c)
{
	if (!(*str = ft_strjoin_clean(*str, ".", 1)))
		return (0);
	if (!(*str = ft_strjoin_clean(*str, *str2, 1)))
		return (0);
	if (!(*str = ft_round(*str, ft_strlen(*str) - 1, 0, pars)))
		return (0);
	(*str)[ft_strlen(*str) - 1] = '\0';
	if ((*str)[ft_strlen(*str) - 1] == '.' && !(*pars).opt.hash)
		(*str)[ft_strlen(*str) - 1] = '\0';
	if ((*pars).b_width && ((*pars).width -= (ft_strlen(*str) +
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
	if ((*pars).opt.space
			&& (!(*str = ft_strjoin_clean(" ", *str, 2))))
		return (0);
	return (1);
}

int		create_str_dec_zero(t_pars *pars, char **str2)
{
	while ((*pars).b_acc)
	{
		if (!(*str2 = ft_strjoin_clean(*str2, "0", 1)))
			return (0);
		(*pars).b_acc--;
	}
	return (1);
}

int		ft_dec(t_pars *pars, t_func tab, char **str2, unsigned long long dec)
{
	char	*tmp;

	(*pars).b_acc = (*pars).acc;
	while ((*pars).acc)
	{
		(*pars).input.f *= 10;
		(*pars).acc--;
	}
	(*pars).acc = (*pars).b_acc;
	dec = (unsigned long long)(*pars).input.f;
	(*pars).input.f -= dec;
	tmp = *str2;
	if (dec != 0 && !(*str2 = ft_ulitoa_base(dec, tab.base[(*pars).nb], *pars)))
		return (0);
	else if (dec == 0)
		if (!(create_str_dec_zero(pars, str2)))
			return (0);
	if (dec)
		free(tmp);
	while (ft_strlen(*str2) < (size_t)(*pars).acc)
		if (!(*str2 = ft_strjoin_clean("0", *str2, 2)))
			return (0);
	return (1);
}

int		ft_float(t_func tab, t_pars *pars)
{
	char				*str;
	char				*str2;
	unsigned long long	ent;

	if (!ft_special_float(pars))
	{
		if (!(str2 = ft_strnew(0)))
			return (0);
		(*pars).input.f *= (*pars).neg ? -1 : 1;
		ent = (unsigned long long)(*pars).input.f;
		(*pars).input.f -= ent;
		if (!(str = ft_ulitoa_base(ent, tab.base[(*pars).nb], *pars)))
			return (0);
		(*pars).acc = (*pars).b_acc ? (*pars).acc + 1 : 6 + 1;
		if (!(ft_dec(pars, tab, &str2, 0)))
			return (0);
		if (!(ft_str_float(&str, &str2, pars, NULL)))
			return (0);
		(*pars).ret += ft_putstr(str);
		free(str);
		free(str2);
	}
	else
		ft_str(tab, pars);
	return (1);
}
