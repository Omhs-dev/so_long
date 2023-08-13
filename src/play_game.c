/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:37:30 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/13 22:57:33 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_player(t_game *game)
{
	game->x_p = 0;
	while (game->map_c[game->x_p])
	{
		game->y_p = 0;
		while (game->map_c[game->x_p][game->y_p])
		{
			if (game->map_c[game->x_p][game->y_p] == 'P')
				return ;
			game->y_p++;
		}
		game->x_p++;
	}
}

void	game_path(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->map_h || y < 0 || y >= game->map_w)
		return ;
	if (game->map_c[x][y] == '1' || game->map_c[x][y] == 'x')
		return ;
	if (game->map_c[x][y] == 'C')
		game->collect++;
	if (game->map_c[x][y] == 'E')
		game->endgame = 1;
	game->map_c[x][y] = 'x';
	game_path(game, x, y + 1);
	game_path(game, x + 1, y);
	game_path(game, x, y - 1);
	game_path(game, x - 1, y);
}

int	valid_path(t_game *game)
{
	check_player(game);
	game_path(game, game->x_p, game->y_p);
	if ((game->endgame == 1) && (game->collect == game->n_collect))
		return (1);
	return (0);
}

t_game	*start_game(char *game)
{
	t_game	*play;

	play = malloc(sizeof(t_game));
	if (play == NULL)
		return (0);
	play->name = game;
	read_map(play);
	play->map_w = m_width(play->name);
	play->map_h = m_height(play->name);
	play->moves = 0;
	play->collect = 0;
	play->n_collect = count_collect(play);
	if (map_checker(play))
		return (0);
	return (play);
}
