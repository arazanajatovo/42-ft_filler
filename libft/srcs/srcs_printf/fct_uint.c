/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct_uint.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/22 09:11:02 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/22 09:30:46 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_uint_opt(char **str, t_pars *pars)
{
	if ((*pars).b_width &&
			((*pars).width -= (ft_strlen(*str) + (*pars).opt.plus)) > 0)
	{
		(*pars).b_width = 2;
		if (!(*str = ft_width_int(*pars, *str)))
			return (0);
	}
	if (((*pars).nb == 8 || (((*pars).nb == 6 || (*pars).nb == 7) &&
					(*pars).opt.hash)) &&
			(*pars).b_width != 2 && (!(*str = ft_strjoin_clean("0x", *str, 2))))
		return (0);
	if ((*pars).nb == 5 && (*pars).opt.hash && (*pars).b_width != 2
			&& (!(*str = ft_strjoin_clean("0", *str, 2))))
		return (0);
	if ((*pars).opt.space && (*pars).b_width != 2
			&& (!(*str = ft_strjoin_clean(" ", *str, 2))))
		return (0);
	if ((*pars).nb == 7)
		*str = ft_toupper(*str);
	return (1);
}

int		ft_uint(t_func tab, t_pars *pars)
{
	char	*str;

	if (!(str = ft_ulitoa_base((*pars).input.u, tab.base[(*pars).nb], *pars)))
		return (0);
	if (((*pars).nb == 4 || (*pars).nb == 5 || (*pars).nb == 8
			|| (((*pars).nb == 6 || (*pars).nb == 7) && !(*pars).opt.hash))
			&& (*pars).input.u == 0 && (*pars).b_acc == 1
			&& (*pars).acc == 0)
	{
		free(str);
		if (!(str = ft_strnew(0)))
			return (0);
	}
	if ((*pars).b_acc && ((*pars).acc -= ft_strlen(str)) > 0)
	{
		if ((*pars).nb == 5)
			(*pars).acc -= (*pars).opt.hash;
		if (!(str = ft_acc_int(*pars, str)))
			return (0);
	}
	if (!(ft_uint_opt(&str, pars)))
		return (0);
	(*pars).ret += ft_putstr(str);
	free(str);
	return (1);
}
