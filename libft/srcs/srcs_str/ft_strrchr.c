/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 16:30:29 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:12:53 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	tmp = (char*)s;
	res = NULL;
	while (*tmp)
	{
		if (*tmp == c)
			res = tmp;
		tmp++;
	}
	if (c == '\0')
		return (tmp);
	return (res);
}
