/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:32:22 by ohamadou          #+#    #+#             */
/*   Updated: 2023/07/21 17:03:59 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/Libft/includes/libft.h"
# include "../libraries/Libft/includes/get_next_line_bonus.h"
# include "../libraries/Libft/includes/ft_printf.h"

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
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
	int move;
	int end;
	int n_collect;
	int n_player;
	int n_exit;
	int x_player;
	int y_player;
	int moves;
	int endgame;
} t_game;

void output_img(t_game *game, void *img, int x, int y);
int output_map(t_game *game);

#endif