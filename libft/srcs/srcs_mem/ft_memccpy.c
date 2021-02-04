/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:01:39 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:07:51 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*strsrc;
	unsigned char	*strdst;

	strsrc = (unsigned char*)src;
	strdst = (unsigned char*)dst;
	while (n != 0)
	{
		if (*strsrc == (unsigned char)c)
		{
			*strdst = *strsrc;
			strdst++;
			return (strdst);
		}
		*strdst = *strsrc;
		strdst++;
		strsrc++;
		n--;
	}
	return (NULL);
}
