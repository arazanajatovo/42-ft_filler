/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 16:49:56 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:12:47 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*rst_haystack;
	char	*rst_needle;
	size_t	i;
	size_t	j;

	i = 0;
	rst_haystack = (char*)haystack;
	rst_needle = (char*)needle;
	while (*haystack && i < len)
	{
		j = 0;
		haystack = (const char*)rst_haystack;
		needle = (const char*)rst_needle;
		while (*haystack == *needle && *(haystack)++ && *(needle)++)
			j++;
		if (!(*needle))
		{
			if (i + j > len)
				return (NULL);
			return (rst_haystack);
		}
		rst_haystack++;
		i++;
	}
	return (NULL);
}
