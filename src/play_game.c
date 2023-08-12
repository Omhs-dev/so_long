/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:37:30 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/12 05:43:12 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// int	check(t_game *game)
// {
// 	if (check_map_c(game, 0, 0)
// 		&& check_map(game, 0, 0)
// 		&& check_count(game, 'E') == 1
// 		&& check_count(game, 'P') == 1
// 		&& check_count(game, 'C') != 0
// 		&& valid_path(game)
// 		&& rect_check(game))
// 		return (0);
// 	ft_printf("Error\nmap invalid\n");
// 	return (1);
// }

void check_player(t_game *game)
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

// int	start_game(char *game)
// {
// 	t_game	*d;
// 	// mlx_t	*mlx;

// 	d = malloc(sizeof(t_game));
// 	if (d == NULL)
// 		return (0);
// 	d->name = game;
// 	read_map(d);
// 	d->map_w = width(d->name);
// 	d->map_h = height(d->name);
// 	d->move = 0;
// 	d->collect = 0;
// 	d->n_collect = count_collect(d);
// 	if (map_checker(d))
// 		return (0);
// 	d->mlx = mlx_init((d->map_w -1) * 60, (d->map_h) * 84, "game", false);
// 	output_map(d);
// 	mlx_key_hook(d->mlx, &ft_hook, d);
// 	mlx_loop_hook(d->mlx, &output_player, d);
// 	output_win(d);
// 	mlx_loop(d->mlx);
// 	exit_game(d);
// 	return (0);
// }

void	game_path(t_game *game, int x, int y)
{
	if (game->map_c[x][y] == '1'
		&& game->map_c[x][y] == 0)
		return ;
	if (game->map_c[x][y] == 'C')
		game->collect++;
	if (game->map_c[x][y] == 'E')
		game->endgame = 1;
	game->map_c[x][y] = 'x';
	if (game->map_c[x][y + 1] != '1'
		&& game->map_c[x][y + 1] != 'x')
		game_path(game, x, y + 1);
	if (game->map_c[x + 1][y] != '1'
		&& game->map_c[x +1][y] != 'x')
		game_path(game, x + 1, y);
	if (game->map_c[x][y - 1] != '1'
		&& game->map_c[x][y - 1] != 'x')
		game_path(game, x, y - 1);
	if (game->map_c[x - 1][y] != '1'
		&& game->map_c[x - 1][y] != 'x')
		game_path(game, x - 1, y);
}

int valid_path(t_game *game)
{
	check_player(game);
	game_path(game, game->x_p, game->y_p);
	if ((game->endgame == 1) && (game->collect == game->n_collect))
		return (1);
	return (0);
}
