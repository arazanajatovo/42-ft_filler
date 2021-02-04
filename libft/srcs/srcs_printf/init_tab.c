/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_tab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 03:43:44 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/22 06:15:49 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_init_base(t_func *tab)
{
	(*tab).base[0] = 0;
	(*tab).base[1] = 0;
	(*tab).base[2] = 10;
	(*tab).base[3] = 10;
	(*tab).base[4] = 10;
	(*tab).base[5] = 8;
	(*tab).base[6] = 16;
	(*tab).base[7] = 16;
	(*tab).base[8] = 16;
	(*tab).base[9] = 2;
	(*tab).base[10] = 10;
	(*tab).base[11] = 0;
	(*tab).base[12] = 0;
}

void	ft_init_func_print(t_func *tab)
{
	(void)tab;
	(*tab).f[0] = &ft_str;
	(*tab).f[1] = &ft_char;
	(*tab).f[2] = &ft_int;
	(*tab).f[3] = &ft_int;
	(*tab).f[4] = &ft_uint;
	(*tab).f[5] = &ft_uint;
	(*tab).f[6] = &ft_uint;
	(*tab).f[7] = &ft_uint;
	(*tab).f[8] = &ft_uint;
	(*tab).f[9] = &ft_uint;
	(*tab).f[10] = &ft_float;
	(*tab).f[11] = &ft_char;
	(*tab).f[12] = &ft_char;
}

void	ft_init_func_get_input(t_func *tab)
{
	(*tab).f_get[0] = &ft_get_single;
	(*tab).f_get[1] = &ft_get_single;
	(*tab).f_get[2] = &ft_get_int;
	(*tab).f_get[3] = &ft_get_int;
	(*tab).f_get[4] = &ft_get_uint;
	(*tab).f_get[5] = &ft_get_uint;
	(*tab).f_get[6] = &ft_get_uint;
	(*tab).f_get[7] = &ft_get_uint;
	(*tab).f_get[8] = &ft_get_single;
	(*tab).f_get[9] = &ft_get_uint;
	(*tab).f_get[10] = &ft_get_double;
	(*tab).f_get[11] = &ft_get_single;
	(*tab).f_get[12] = NULL;
}

void	ft_init_tab(t_func *tab)
{
	(*tab).type[0] = 's';
	(*tab).type[1] = 'c';
	(*tab).type[2] = 'd';
	(*tab).type[3] = 'i';
	(*tab).type[4] = 'u';
	(*tab).type[5] = 'o';
	(*tab).type[6] = 'x';
	(*tab).type[7] = 'X';
	(*tab).type[8] = 'p';
	(*tab).type[9] = 'b';
	(*tab).type[10] = 'f';
	(*tab).type[11] = '%';
	(*tab).type[12] = '\0';
	ft_init_func_get_input(tab);
	ft_init_func_print(tab);
	ft_init_base(tab);
}
