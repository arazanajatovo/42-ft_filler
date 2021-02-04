/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: maxigarc <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 10:41:55 by maxigarc     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 02:48:52 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

/*void	display_txt(t_parse pars, SDL_Renderer *rend)
{
	TTF_Font *font = TTF_OpenFont("sixty.ttf", 24);
	SDL_Surface	*s_p1;
	SDL_Surface *s_p2;
	SDL_Color	p1_c = {183, 254, 255};
	SDL_Color	p2_c = {249, 140, 140};
	SDL_Color	black = {255, 255, 255};
	SDL_Rect	rect;
	SDL_Texture *p1_lbl;
	SDL_Texture *p2_lbl;
	int w;
	int h;

	if (pars.player == 'O')
		s_p1 = TTF_RenderText_Solid(font, "Player :", p1_c);
	else
		s_p1 = TTF_RenderText_Solid(font, "Bot :", p1_c);
	p1_lbl = SDL_CreateTextureFromSurface(rend, s_p1);
	w = s_p1->w;
	h = s_p1->h;
	SDL_FreeSurface(s_p1);
	rect.x = 1825;
	rect.y = 20;
	rect.w = w;
	rect.h = h;
	SDL_RenderCopy(rend, p1_lbl, NULL, &rect);
	SDL_DestroyTexture(p1_lbl);
	if (pars.player == 'O')
		s_p2 = TTF_RenderText_Solid(font, "Bot :", p2_c);
	else
		s_p2 = TTF_RenderText_Solid(font, "Player :", p2_c);
	p2_lbl = SDL_CreateTextureFromSurface(rend, s_p2);
	w = s_p2->w;
	h = s_p2->h;
	SDL_FreeSurface(s_p2);
	rect.x = 1825;
	rect.y = 120;
	rect.w = w;
	rect.h = h;
	SDL_RenderCopy(rend, p2_lbl, NULL, &rect);
	SDL_DestroyTexture(p2_lbl);
}*/

void	fill_board(t_parse pars, SDL_Renderer *rend)
{
	SDL_Rect	tile;
	SDL_Color	col;
	SDL_Color	tile_c = {9, 18, 27, 255};
	SDL_Color	player1_c = {183, 254, 255, 255};
	SDL_Color	player2_c = {249, 140, 140, 255};
	int			i;
	int			j;

	i = 0;
	tile.y = 25;
	tile.w = (1470 - pars.map_col - 1) / pars.map_col;
	tile.h = (1140 - pars.map_row - 1) / pars.map_row;
	while (i < pars.map_row)
	{
		j = 0;
		tile.x = 25;
		while (j < pars.map_col)
		{
			col = tile_c;
			col = pars.map[i][j] == 'O' ? player1_c : col;
			col = pars.map[i][j] == 'X' ? player2_c : col;
			if (SDL_SetRenderDrawColor(rend, col.r, col.g, col.b, col.a))
				SDL_Log("Erreur couleur rendu %s\n", SDL_GetError());
			if (SDL_RenderFillRect(rend, &tile))
				SDL_Log("Erreur fill rectangle %s\n", SDL_GetError());
			tile.x += tile.w + 1;
			j++;
		}
		tile.y += tile.h + 1;
		i++;
	}
//	display_txt(pars, rend);
	SDL_RenderPresent(rend);
}

void	set_background(SDL_Renderer *rend)
{
	SDL_Color		bg = {31, 63, 96, 255};
	SDL_Rect		bg_r;

	bg_r.x = 0;
	bg_r.y = 0;
	bg_r.w = 2000;
	bg_r.h = 1200;
	if (SDL_SetRenderDrawColor(rend, bg.r, bg.g, bg.b, bg.a) != 0)	
		SDL_Log("Erreur couleur rendu %s\n", SDL_GetError());
	if (SDL_RenderFillRect(rend, &bg_r) != 0)
		SDL_Log("Erreur fill rectangle %s\n", SDL_GetError());
}

int		main(void)
{
	SDL_Window		*window = NULL;
	SDL_Renderer	*renderer = NULL;
	int				b = 0;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("ERREUR : Initialisation SDL > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if (TTF_Init() == -1)
	{
		ft_printf("TTF_Init: %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}
	/*execution du programme...*/
	window = SDL_CreateWindow("Premiere fenetre SDL 2", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1800, 1200, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		SDL_Log("ERREUR : Creation fenetre echouee > %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	//renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		SDL_Log("Erreur SDL_CreateRenderer %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	//	if (SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer) != 0)
	//		SDL_Log("Erreur creation window et render %s\n", SDL_GetError());


	SDL_RaiseWindow(window);
	SDL_bool prog_running;
	int i;

	while (prog_running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_MOUSEBUTTONDOWN:
					if (!b)
					{
						filler(renderer);
						b = 1;
					}
					break;
				case SDL_QUIT:
					prog_running = SDL_FALSE;
					break;
				default:
					break;
			}
		}
	}

	if (SDL_RenderClear(renderer) != 0)
	{
		SDL_Log("Erreur SDL_RenderClear %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	TTF_Quit();
	SDL_Quit();

	return EXIT_SUCCESS;
}
