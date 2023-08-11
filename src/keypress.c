/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:49:57 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/02 18:44:38 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void player_update(char key, t_game *game)
{
	mlx_delete_image(game->mlx, game->player_img);
	if (key == 'w')
		game->player_img = mlx_load_png("../assets/luffy.png");
	else if (key == 's')
		game->player_img = mlx_load_png("../assets/luffy.png");
	else if (key == 'd')
		game->player_img = mlx_load_png("../assets/luffy.png");
	else if (key == 'a')
		game->player_img = mlx_load_png("../assets/luffy.png");
}

void key_w(t_game *game)
{
	player_update('w', game);
	if (game->map[game->y_p][game->x_p] == 'E'
		&& game->n_collect == 0)
	{
		mlx_close_window(game->mlx);
		game->map[game->y_p + 1][game->x_p] = '0';
		game->moves++;
		game->endgame = 1;
		output_map(game);
	}
	else if (game->map[game->y_p][game->x_p] == '1'
		|| game->map[game->y_p][game->x_p] == 'E')
		game->y_p += 1;
	else
	{
		mlx_close_window(game->mlx);
		if (game->map[game->y_p][game->x_p] == 'C')
			game->n_collect -= 1;
		game->map[game->y_p][game->x_p] == 'P';
		game->map[game->y_p + 1][game->x_p] == '0';
		game->moves++;
		output_map(game);
	}
}

void key_s(t_game *game)
{
	player_update('s', game);
	if (game->map[game->y_p][game->x_p] == 'E'
		&& game->n_collect == 0)
	{
		mlx_close_window(game->mlx);
		game->map[game->y_p - 1][game->x_p] = '0';
		game->moves++;
		game->endgame = 1;
		output_map(game);
	}
	else if (game->map[game->y_p][game->x_p] == '1'
		|| game->map[game->y_p][game->x_p] == 'E')
		game->y_p -= 1;
	else
	{
		mlx_close_window(game->mlx);
		if (game->map[game->y_p][game->x_p] == 'C')
			game->n_collect -= 1;
		game->map[game->y_p][game->x_p] == 'P';
		game->map[game->y_p - 1][game->x_p] == '0';
		game->moves++;
		output_map(game);
	}
}

void key_d(t_game *game)
{
	player_update('d', game);
	if (game->map[game->y_p][game->x_p] == 'E'
		&& game->n_collect == 0)
	{
		mlx_close_window(game->mlx);
		game->map[game->y_p - 1][game->x_p] = '0';
		game->moves++;
		game->endgame = 1;
		output_map(game);
	}
	else if (game->map[game->y_p][game->x_p] == '1'
		|| game->map[game->y_p][game->x_p] == 'E')
		game->y_p -= 1;
	else
	{
		mlx_close_window(game->mlx);
		if (game->map[game->y_p][game->x_p] == 'C')
			game->n_collect -= 1;
		game->map[game->y_p][game->x_p] == 'P';
		game->map[game->y_p - 1][game->x_p] == '0';
		game->moves++;
		output_map(game);
	}
}

void key_a(t_game *game)
{
	player_update('a', game);
	if (game->map[game->y_p][game->x_p] == 'E'
		&& game->n_collect == 0)
	{
		mlx_close_window(game->mlx);
		game->map[game->y_p + 1][game->x_p] = '0';
		game->moves++;
		game->endgame = 1;
		output_map(game);
	}
	else if (game->map[game->y_p][game->x_p] == '1'
		|| game->map[game->y_p][game->x_p] == 'E')
		game->y_p += 1;
	else
	{
		mlx_close_window(game->mlx);
		if (game->map[game->y_p][game->x_p] == 'C')
			game->n_collect -= 1;
		game->map[game->y_p][game->x_p] == 'P';
		game->map[game->y_p + 1][game->x_p] == '0';
		game->moves++;
		output_map(game);
	}
}
