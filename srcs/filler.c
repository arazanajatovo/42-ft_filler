/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/28 10:26:38 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 02:27:19 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

t_tok	check_pos(t_parse pars, int i, int j)
{
	t_tok	tok;
	int		x;
	int		y;

	tok.x = i;
	tok.y = j;
	tok.sum = 0;
	tok.val = 0;
	x = 0;
	while (x < pars.tok_row && tok.val < 2)
	{
		y = 0;
		while (y < pars.tok_col && tok.val < 2)
		{
			if (pars.token[x][y] == '*')
			{
				if (pars.hmap[i + x][j + y] < 0)
					tok.val += pars.hmap[i + x][j + y] * -1;
				else
					tok.sum += pars.hmap[i + x][j + y];
			}
			y++;
		}
		x++;
	}
	return (tok);
}

t_tok	get_token_pos(t_tok tok, t_parse pars)
{
	t_tok	new_tok;
	int		i;
	int		j;

	i = 0;
	while (i <= pars.map_row - pars.tok_row)
	{
		j = 0;
		while (j <= pars.map_col - pars.tok_col)
		{
			new_tok = check_pos(pars, i, j);
			if (new_tok.val == 1 && (new_tok.sum < tok.sum || tok.val == 0))
				tok = new_tok;
			j++;
		}
		i++;
	}
	tok.val = tok.val == 0 ? -1 : tok.val;
	return (tok);
}

int		set_hmap_nb(int **hmap, int i, int j, int nb)
{
	hmap[i][j] = nb;
	return (1);
}

void	fill_hmap(t_parse pars, int nb)
{
	int	i;
	int	j;
	int b;
	int m;

	m = 999999;
	b = 0;
	i = 0;
	while (i < pars.map_row)
	{
		j = 0;
		while (j < pars.map_col)
		{
			if (pars.hmap[i][j] == nb)
			{
				b = (i - 1 >= 0 && pars.hmap[i - 1][j] == m) ? set_hmap_nb(pars.hmap, i - 1, j, nb + 1) : b;
				b = (j - 1 >= 0 && pars.hmap[i][j - 1] == m) ? set_hmap_nb(pars.hmap, i, j - 1, nb + 1) : b;
				b = (i + 1 < pars.map_row && pars.hmap[i + 1][j] == m) ? set_hmap_nb(pars.hmap, i + 1, j, nb + 1) : b;
				b = (j + 1 < pars.map_col && pars.hmap[i][j + 1] == m) ? set_hmap_nb(pars.hmap, i, j + 1, nb + 1) : b;
			}
			j++;
		}
		i++;
	}
	if (b)
		fill_hmap(pars, nb + 1);
}

int		filler(SDL_Renderer *rend)
{
	t_parse pars;
	t_tok	tok;
	char	**split;
	char	*line;
	int		m;
	int		i;
	int		j;

	m = 999999;
	//Parsing
	//Player
	i = 0;
	get_next_line(0, &line);
	while (line[i] != '1' && line[i] != '2' && line[i])
		i++;
	pars.player = line[i] == '1' ? 'O' : 'X';
	pars.bot = pars.player == 'O' ? 'X' : 'O';
	//Row Col
	get_next_line(0, &line);
	split = ft_strsplit(line, ' ');
	pars.map_row = ft_atoi(split[1]);
	pars.map_col = ft_atoi(split[2]);
	free(split);

	//Core
	//Parse Map
	if (!(pars.map = (char**)malloc(sizeof(char*) * pars.map_row + 1)))
		return (-1);
	pars.map[pars.map_row] = NULL;
	////////////// WHILE ///////////
	while (tok.val != -1)
	{
		/////////// create hmap ////////////
		if (!(pars.hmap = (int**)malloc(sizeof(int*) * pars.map_row)))
			return (-1);
		i = 0;
		while (i < pars.map_row)
			if (!(pars.hmap[i++] = (int*)malloc(sizeof(int) * pars.map_col)))
				return (-1);
		//init tok
		tok.x = 0;
		tok.y = 0;
		tok.sum = 0;
		tok.val = 0;
		i = 0;
		get_next_line(0, &line);
		while (i < pars.map_row)
		{
			get_next_line(0, &line);
			split = ft_strsplit(line, ' ');
			pars.map[i++] = ft_toupper(split[1]);
			free(split);
		}
		//SDL Map
		SDL_RenderClear(rend);
		set_background(rend);
		fill_board(pars, rend);
		//Parse Token
		get_next_line(0, &line);
		split = ft_strsplit(line, ' ');
		pars.tok_row = ft_atoi(split[1]);
		pars.tok_col = ft_atoi(split[2]);
		free(split);
		if (!(pars.token = (char**)malloc(sizeof(char*) * pars.tok_row + 1)))
			return (-1);
		pars.token[pars.tok_row] = NULL;
		i = 0;
		while (i < pars.tok_row)
		{
			get_next_line(0, &line);
			pars.token[i++] = line;
		}
		//////////////////////
		////// ALGO ICI //////
		//init hmap
		i = 0;
		while (i < pars.map_row)
		{
			j = 0;
			while (j < pars.map_col)
			{
				if (pars.map[i][j] == pars.player || pars.map[i][j] == pars.bot)
				{
					pars.hmap[i][j] = pars.map[i][j] == pars.player ? -1 : -2;
					if (pars.map[i][j] == pars.bot)
					{
						(i - 1 >= 0 && pars.map[i - 1][j] == '.') ? set_hmap_nb(pars.hmap, i - 1, j, 1) : 0;
						(j - 1 >= 0 && pars.map[i][j - 1] == '.') ? set_hmap_nb(pars.hmap, i, j - 1, 1) : 0;
						(i + 1 < pars.map_row && pars.map[i + 1][j] == '.') ? set_hmap_nb(pars.hmap, i + 1, j, 1) : 0;
						(j + 1 < pars.map_col && pars.map[i][j + 1] == '.') ? set_hmap_nb(pars.hmap, i, j + 1, 1) : 0;
					}
				}
				else
					pars.hmap[i][j] = pars.hmap[i][j] != 1 ? m : 1;
				j++;
			}
			i++;
		}
		//////// fill hmap (f recur - floodfill) ////////
		fill_hmap(pars, 1);
		//////// get token pos /////////
		tok = get_token_pos(tok, pars);
		/////// write pos ////////
		//if (tok.val == 1)
		ft_printf("%d %d\n", tok.x, tok.y);
		////// FIN ALGO //////
		//////////////////////
		free(pars.hmap);
		free(pars.token);
		get_next_line(0, &line);
	}
	return (0);
}
