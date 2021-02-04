/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/26 23:09:38 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 17:57:10 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

static int		ft_fill_line(t_read **rd, int bfs, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	if (bfs == 0 && i == 0)
		return (0);
	if (!((*rd)->line = ft_strnew(i)))
		return (-1);
	while (j < i)
	{
		(*rd)->line[j] = (*rd)->str[j];
		j++;
	}
	while ((*rd)->str[i])
		i++;
	tmp = (*rd)->str;
	(*rd)->str = ft_strsub(tmp, j + 1, i - j);
	free(tmp);
	return (1);
}

static int		ft_create_line(const int fd, t_read **rd)
{
	int		bfs;
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	bfs = BUFF_SIZE;
	if (!(str = ft_strnew(bfs)))
		return (-1);
	while ((*rd)->str[i] != '\n' && (*rd)->str[i])
		i++;
	if (!(*rd)->str[i])
	{
		if ((bfs = read(fd, str, BUFF_SIZE) > 0))
		{
			tmp = (*rd)->str;
			(*rd)->str = ft_strjoin(tmp, str);
			free(tmp);
			free(str);
			return (ft_create_line(fd, rd));
		}
	}
	free(str);
	return (ft_fill_line(rd, bfs, i));
}

static int		ft_rdnew(const int fd, t_read **rd, t_read *begin)
{
	if (!((*rd) = (t_read*)malloc(sizeof(t_read))))
		return (-1);
	(*rd)->str = ft_strnew(0);
	(*rd)->fd = fd;
	if (!begin)
	{
		(*rd)->next = *rd;
		(*rd)->prev = *rd;
	}
	else
	{
		(*rd)->next = begin;
		(*rd)->prev = begin->prev;
		begin->prev->next = *rd;
		begin->prev = *rd;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_read	*rd;
	char			*check_fd;
	t_read			*begin;
	int				ret;

	check_fd = NULL;
	if (fd < 0 || BUFF_SIZE < 1 || read(fd, check_fd, 0) < 0)
		return (-1);
	begin = rd;
	if (rd)
		while (rd->fd != fd && rd->next->fd != begin->fd)
			rd = rd->next;
	if (!rd || rd->fd != fd)
	{
		if (rd)
		{
			rd->next = NULL;
			rd = rd->next;
		}
		if (ft_rdnew(fd, &rd, begin) == -1)
			return (-1);
	}
	ret = ft_create_line(fd, &rd);
	ret == 1 ? *line = rd->line : 0;
	return (ret);
}
