/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_clean.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/05/17 19:22:53 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/26 02:41:56 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_strjoin_clean(char *str1, char *str2, int b)
{
	char	*tmp;

	if (b == 1)
	{
		tmp = str1;
		if (!(str1 = ft_strjoin(tmp, str2)))
			return (NULL);
		free(tmp);
		return (str1);
	}
	if (b == 2)
	{
		tmp = str2;
		if (!(str2 = ft_strjoin(str1, tmp)))
			return (NULL);
		free(tmp);
		return (str2);
	}
	return (NULL);
}
