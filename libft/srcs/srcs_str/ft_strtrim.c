/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 22:11:25 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:13:37 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	j;
	size_t	start;
	size_t	end;
	char	*new_s;

	j = 0;
	end = 0;
	if (!s)
		return (NULL);
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end++;
	if (!s[end])
		return (ft_strnew(1));
	start = end;
	while (s[end])
		end++;
	end--;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (!(new_s = ft_strnew(end - start + 1)))
		return (NULL);
	while (start < end + 1)
		new_s[j++] = s[start++];
	new_s[j] = '\0';
	return (new_s);
}
