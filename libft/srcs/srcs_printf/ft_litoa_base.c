/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_litoa_base.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 07:26:22 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/22 08:54:36 by maxigarc    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int		nb_len(unsigned long long value, int base)
{
	int	i;

	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char	*fill_litoa(unsigned long long val, int base, char *tab)
{
	char	*litoa;
	int		len;

	if (val == 0)
		len = 1;
	else
		len = nb_len(val, base);
	if (!(litoa = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	litoa[len--] = '\0';
	while (len >= 0)
	{
		litoa[len--] = tab[val % base];
		val /= base;
	}
	return (litoa);
}

char	*init_tab_base(int base, t_pars pars)
{
	char	*tab_base;
	char	c;
	int		i;

	c = '0';
	i = 0;
	if (!(tab_base = (char*)malloc(sizeof(char) * base + 1)))
		return (NULL);
	tab_base[base] = '\0';
	while (i < base)
	{
		if (c > '9' && (c < 'a' && c < 'A'))
			c = pars.nb == 7 ? 'A' : 'a';
		tab_base[i++] = c++;
	}
	return (tab_base);
}

char	*ft_litoa_base(long long value, int base, t_pars pars)
{
	unsigned long long	val;
	int					neg;
	char				*tab_base;
	char				*litoa;

	neg = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (value < 0)
	{
		neg = base == 10 ? 1 : 0;
		val = value * -1;
	}
	else
		val = (unsigned long long)value;
	if (!(tab_base = init_tab_base(base, pars)))
		return (NULL);
	if (!(litoa = fill_litoa(val, base, tab_base)))
		return (NULL);
	free(tab_base);
	return (litoa);
}

char	*ft_ulitoa_base(unsigned long long value, int base, t_pars pars)
{
	char				*tab_base;
	char				*litoa;

	if (base < 2 || base > 16)
		return (NULL);
	if (!(tab_base = init_tab_base(base, pars)))
		return (NULL);
	if (!(litoa = fill_litoa(value, base, tab_base)))
		return (NULL);
	free(tab_base);
	return (litoa);
}
