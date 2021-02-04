/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/09 17:35:02 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/05/21 11:08:37 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_init_input(t_pars *pars)
{
	(*pars).input.i = 0;
	(*pars).input.u = 0;
	(*pars).input.c = 0;
	(*pars).input.str = NULL;
	(*pars).input.f = 0;
}

void	ft_init_flag(t_pars *pars)
{
	(*pars).b_flag = 0;
	(*pars).flag.h = 0;
	(*pars).flag.hh = 0;
	(*pars).flag.l = 0;
	(*pars).flag.ll = 0;
	(*pars).flag.gl = 0;
}

void	ft_init_opt(t_pars *pars)
{
	(*pars).opt.minus = 0;
	(*pars).opt.plus = 0;
	(*pars).opt.hash = 0;
	(*pars).opt.zero = 0;
	(*pars).opt.space = 0;
	(*pars).acc = 0;
	(*pars).width = 0;
}

void	ft_init_pars(t_pars *pars)
{
	(*pars).type = 0;
	(*pars).nb = 0;
	(*pars).b_acc = 0;
	(*pars).b_width = 0;
	(*pars).neg = 0;
	ft_init_opt(pars);
	ft_init_flag(pars);
	ft_init_input(pars);
}
