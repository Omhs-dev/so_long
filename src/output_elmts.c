/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_elmts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:21:26 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/23 17:53:54 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void output_img(t_game *game, void *img, int x, int y)
{
	mlx_image_to_window(game -> mlx, game -> win, img, x, y);
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
			if (game -> map[y][x] == '0')
				output_img(game, game -> background, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
