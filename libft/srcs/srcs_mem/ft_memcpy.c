/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:01:39 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:08:14 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strsrc;
	unsigned char	*strdest;

	i = 0;
	strsrc = (unsigned char*)src;
	strdest = (unsigned char*)dst;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dst);
}
