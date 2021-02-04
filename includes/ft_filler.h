/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_filler.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/28 10:27:35 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 01:03:21 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "../libft/includes/libft.h"
# include "../SDL2/SDL.h"
# include "../SDL2/SDL_ttf.h"

typedef struct			s_parse
{
	char				player;
	char				bot;
	int					map_row;
	int					map_col;
	int					tok_row;
	int					tok_col;
	char				**map;
	char				**token;
	int					**hmap;
}						t_parse;

typedef struct			s_tok
{
	int					x;
	int					y;
	int					sum;
	int					val;
}						t_tok;

int						filler(SDL_Renderer *rend);
void					fill_board(t_parse pars, SDL_Renderer *rend);
void					set_background(SDL_Renderer *rend);

#endif
