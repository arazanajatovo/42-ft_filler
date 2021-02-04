/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:27:22 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:11:31 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	i = 0;
	len = 0;
	while (dst[i])
		i++;
	len += size < i ? size : i;
	while (src[j] && j < size - len)
	{
		dst[i++] = src[j++];
	}
	while (src[j])
		j++;
	i -= size <= i ? 1 : 0;
	i += len >= size ? 1 : 0;
	dst[i] = '\0';
	return (len + j);
}
