/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:32:22 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/13 22:25:14 by ohamadou         ###   ########.fr       */
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

# define WIDTH 500
# define HEIGHT 500
# define DIMENS 50
// # define BPP sizeof(int32_t)

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**map_c;
	char			*name;
	char			*map_move;
	void			*win;
	void			*background;
	mlx_image_t		*wall_img;
	mlx_image_t		*player_img;
	mlx_image_t		*collect_img;
	mlx_image_t		*exit_img;
	mlx_texture_t	*wall_t;
	mlx_texture_t	*collect_t;
	mlx_texture_t	*exit_t;
	mlx_texture_t	*player_t;
	mlx_texture_t	*path_t;
	mlx_image_t		*line_move;
	int				map_w;
	int				map_h;
	int				move;
	int				i;
	int				j;
	int				end;
	int				n_collect;
	int				collect;
	int				n_player;
	int				n_exit;
	int				x_p;
	int				y_p;
	int				x_p1;
	int				y_p1;
	int				moves;
	int				endgame;
}	t_game;

void	output_img(t_game *game);
void	read_map(t_game *p);
void	game_init(t_game *game);
void	free_map(char **map);
void	key_p_w(t_game *game);
void	key_p_a(t_game *game);
void	key_p_d(t_game *game);
void	key_p_s(t_game *game);
void	output_player(void *game);
void	output_win(t_game *game);
void	output_map(t_game *game);
void	ft_hook(mlx_key_data_t key_game, void *param);
void	check_player(t_game *game);
void	exit_game(t_game *game);
void	game_path(t_game *game, int x, int y);
void	player_position(t_game *game);
void	replacing_coll(t_game *game);
int		valid_path(t_game *game);
int		check_ber(char *str);
int		m_width(char *name);
int		m_height(char *name);
int		count_collect(t_game *game);
int		map_checker(t_game *game);
int		is_pec(t_game *game);
int		check_map(t_game *game, int i, int j);
int		check_map_c(t_game *game, int i, int j);
int		is_rectangular(t_game *game);
int		is_validate(t_game *game, char c);
int		next_line_true(char *line_str);
t_game	*start_game(char *game);
// void	ft_hook_moves(t_game *game);
// void	ft_hooks(void *param);
// int	move_up(t_game *g);
// int	move_down(t_game *g);
// int	start_game(char *game);
// int	move_left(t_game *g);
// int	move_right(t_game *g);

#endif