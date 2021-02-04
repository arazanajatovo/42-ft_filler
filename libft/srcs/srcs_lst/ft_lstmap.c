/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 14:32:47 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/24 13:07:08 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;

	if (!lst || !f)
		return (NULL);
	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	list = f(lst);
	if (lst->next)
		list->next = ft_lstmap(lst->next, f);
	else
		list->next = NULL;
	return (list);
}
