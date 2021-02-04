/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/10 20:50:18 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:13:22 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*rst_haystack;
	char	*rst_needle;

	rst_haystack = (char*)haystack;
	rst_needle = (char*)needle;
	if (!(*needle))
		return ((char*)haystack);
	while (*haystack)
	{
		haystack = (const char*)rst_haystack;
		needle = (const char*)rst_needle;
		while (*haystack == *needle && *haystack && *needle)
		{
			haystack++;
			needle++;
		}
		if (!(*needle))
			return (rst_haystack);
		rst_haystack++;
	}
	return (NULL);
}
