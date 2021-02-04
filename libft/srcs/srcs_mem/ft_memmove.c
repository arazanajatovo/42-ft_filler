/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/10 20:02:44 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:08:32 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*ndst;
	const char	*nsrc;

	nsrc = src;
	ndst = dst;
	if (nsrc < ndst)
	{
		nsrc += len;
		ndst += len;
		while (len--)
			*(--ndst) = *(--nsrc);
	}
	else if (nsrc != ndst)
		ft_memcpy(ndst, nsrc, len);
	return (dst);
}
