/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_elmts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:21:26 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/02 17:42:48 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void output_img(t_game *game, void *img, int x, int y)
{
	mlx_image_to_window(game -> mlx, img, x, y);
}

static int output_player(t_game *game, void *img, int x, int y)
{
	game -> x_p = x;
	game -> y_p = y;
	output_img(game, img, x, y);
}

static void output_exit(t_game *game, int x, int y)
{
	if (game -> n_collect == 0)
	{
		mlx_delete_image(game -> mlx, game -> exit_img);
		game -> exit_img = mlx_load_png("../assets/wall.png");
	}
	output_img(game, game -> exit_img, x, y);
}

int output_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (game -> map[y])
	{
		x = 0;
		while (game -> map[y][x])
		{
			if (game -> map[y][x] == '1')
				output_img(game, game -> wall_img, x * 32, y * 32);
			else if (game -> map[y][x] == '0')
				output_img(game, game -> background, x * 32, y * 32);
			else if (game -> map[y][x] == 'P')
				output_player(game, game -> player_img, x * 32, y * 32);
			else if (game -> map[y][x] == 'C')
				output_img(game, game -> collect_img, x * 32, y * 32);
			else if (game -> map[y][x] == 'E')
				output_exit(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
