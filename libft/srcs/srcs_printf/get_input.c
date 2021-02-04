/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_input.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 04:59:16 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/26 04:55:35 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_get_int(va_list ap, t_func tab, t_pars *pars)
{
	(void)tab;
	if ((*pars).flag.ll)
		(*pars).input.i = va_arg(ap, long long);
	else if ((*pars).flag.l)
		(*pars).input.i = va_arg(ap, long);
	else if ((*pars).flag.h)
		(*pars).input.i = (short)va_arg(ap, int);
	else if ((*pars).flag.hh)
		(*pars).input.i = (char)va_arg(ap, int);
	else
		(*pars).input.i = va_arg(ap, int);
	(*pars).input.i < 0 ? (*pars).neg = 1 : 0;
	(*pars).opt.plus = (*pars).neg ? 1 : (*pars).opt.plus;
}

void	ft_get_uint(va_list ap, t_func tab, t_pars *pars)
{
	(void)tab;
	if ((*pars).flag.ll)
		(*pars).input.u = va_arg(ap, unsigned long long);
	else if ((*pars).flag.l)
		(*pars).input.u = va_arg(ap, unsigned long);
	else if ((*pars).flag.h)
		(*pars).input.u = (unsigned short)va_arg(ap, unsigned int);
	else if ((*pars).flag.hh)
		(*pars).input.u = (unsigned char)va_arg(ap, unsigned int);
	else
		(*pars).input.u = va_arg(ap, unsigned int);
}

void	ft_get_double(va_list ap, t_func tab, t_pars *pars)
{
	(void)tab;
	if ((*pars).flag.gl)
		(*pars).input.f = va_arg(ap, long double);
	else
		(*pars).input.f = va_arg(ap, double);
	(*pars).input.f < 0 ? (*pars).neg = 1 : 0;
	(*pars).opt.plus = (*pars).neg ? 1 : (*pars).opt.plus;
}

void	ft_get_single(va_list ap, t_func tab, t_pars *pars)
{
	if (tab.type[(*pars).nb] == 's')
		(*pars).input.str = va_arg(ap, char *);
	else if (tab.type[(*pars).nb] == 'c')
		(*pars).input.c = (unsigned char)va_arg(ap, int);
	else if (tab.type[(*pars).nb] == '%')
		(*pars).input.c = '%';
	else if (tab.type[(*pars).nb] == 'p')
	{
		(*pars).input.p = va_arg(ap, void*);
		(*pars).input.u = (unsigned long long)(*pars).input.p;
	}
}
