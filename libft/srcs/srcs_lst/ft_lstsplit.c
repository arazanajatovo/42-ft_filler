/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 21:19:49 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:07:27 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstsplit(char const *s, char c)
{
	t_list	*list;
	char	**split;
	int		i;

	i = 0;
	list = NULL;
	if (!s && !c)
		return (NULL);
	split = ft_strsplit(s, c);
	while (split[i])
	{
		ft_lstaddback(&list, ft_lstnew(split[i], ft_strlen(split[i])));
		i++;
	}
	return (list);
}
