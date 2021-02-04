/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstfold.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 22:37:33 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:06:50 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_lstfold(int (*f)(int, int), t_list **list)
{
	t_list	*tmp;
	int		res;

	if (!list)
		return (0);
	res = 0;
	tmp = *list;
	res = (int)(ft_atoi((char*)tmp->content));
	while (tmp->next)
	{
		tmp = tmp->next;
		res = f(res, (int)(ft_atoi((char*)tmp->content)));
	}
	return (res);
}
