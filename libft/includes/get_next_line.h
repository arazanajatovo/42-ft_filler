/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 15:48:59 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/28 18:02:29 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42

# include "./libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>

typedef struct		s_read
{
	struct s_read	*next;
	struct s_read	*prev;
	char			*str;
	char			*line;
	int				fd;
}					t_read;

int					get_next_line(const int fd, char **line);

#endif
