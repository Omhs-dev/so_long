/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:18:53 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/25 21:04:16 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void init_img(t_game *game)
{
	mlx_texture_t* texture = mlx_load_png("images/wall.png");
	game -> wall_img = mlx_texture_to_image(game -> mlx, texture);
	mlx_image_to_window(game->mlx, game ->wall_img, 0, 0);
	mlx_loop(game->mlx);
	mlx_delete_image(game->mlx, game ->wall_img);
	mlx_delete_texture(texture);
	mlx_terminate(game->mlx);
}

static void wind_size_init(t_game *game)
{
	int i;

	game -> map_w = ft_strlen(game ->map[0]) * 32;
	i = 0;
	while (game ->map[i] != '\0')
		i++;
	game -> map_h = i * 32;
}
void game_init(t_game *game)
{
	game -> mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	wind_size_init(game);
	game ->  move = 0;
	game -> end = 0;
	init_img(game);
	output_map(game);
}