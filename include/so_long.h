/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:32:22 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/23 17:54:31 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"

# define WIDTH 750
# define HEIGHT 750
// # define BPP sizeof(int32_t)

typedef struct s_game
{
	void **map;
	void *mlx;
	void *win;
	void *background;
	void *wall_img;
	void *player_img;
	void *collect_img;
	void *exit_img;
	int map_w;
	int map_h;
} t_game;

void output_img(t_game *game, void *img, int x, int y);
int output_map(t_game *game);

#endif