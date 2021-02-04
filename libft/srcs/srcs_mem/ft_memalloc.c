/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 18:59:13 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:07:42 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_malloc;

	if (!(new_malloc = (void*)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(new_malloc, size);
	return (new_malloc);
}
