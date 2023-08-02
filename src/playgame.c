/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:37:30 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/02 19:20:24 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void game_events(int key, t_game *game)
{
	if (key = MLX_KEY_W || key = MLX_KEY_UP)
	{
		game -> y_p -= 1;
		key_w(game);
	}
	else if (key == MLX_KEY_S || key == MLX_KEY_DOWN)
	{
		game -> y_p += 1;
		key_s(game);
	}
	else if (key == MLX_KEY_D || key == MLX_KEY_RIGHT)
	{
		game -> x_p += 1;
		key_d(game);
	}
	else if (key == MLX_KEY_A || key == MLX_KEY_LEFT)
	{
		game -> x_p -= 1;
		key_a(game);
	}
}

static int press(int key, t_game *game)
{
	if (key == MLX_KEY_ESCAPE || key == MLX_KEY_Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(key, game);
		printf("Moves : %d\n", game->moves);
	}
	return (0);
}

// void playgame(t_game *game)
// {
// 	mlx_key_hook(game->mlx, &game_events, )
// }