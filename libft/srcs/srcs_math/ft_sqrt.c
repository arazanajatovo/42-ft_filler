/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_sqrt.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 18:27:57 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:10:14 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_sqrt_solve(int min, int max, int nb)
{
	int	nb_t;

	nb_t = ((max - min) / 2) + min;
	if (max - min <= 1)
		return (0);
	else if (nb_t * nb_t == nb)
		return (nb_t);
	else if (nb_t * nb_t > nb)
		return (ft_sqrt_solve(min, nb_t, nb));
	else
		return (ft_sqrt_solve(nb_t, max, nb));
}

int			ft_sqrt(int nb)
{
	int	max;

	max = 46340;
	if (max * max == nb)
		return (max);
	return (ft_sqrt_solve(0, max, nb));
}
