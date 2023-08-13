/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_elmts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:21:26 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/13 22:14:15 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_position(t_game *game)
{
	game->i = 0;
	while (game->map[game->i])
	{
		game->j = 0;
		while (game->map[game->i][game->j])
		{
			if (game->map[game->i][game->j] == 'P')
				return ;
			game->j++;
		}
		game->i++;
	}
}

void	output_img(t_game *game)
{
	game->wall_t = mlx_load_png("./assets/wall.png");
	game->wall_img = mlx_texture_to_image(game->mlx, game->wall_t);
	game->player_t = mlx_load_png("./assets/luffy.png");
	game->player_img = mlx_texture_to_image(game->mlx, game->player_t);
	game->exit_t = mlx_load_png("./assets/exit.png");
	game->exit_img = mlx_texture_to_image(game->mlx, game->exit_t);
	game->collect_t = mlx_load_png("./assets/collect.png");
	game->collect_img = mlx_texture_to_image(game->mlx, game->collect_t);
}

void	output_player(void *param)
{
	t_game	*data;

	data = param;
	mlx_delete_image(data->mlx, data->player_img);
	data->player_img = mlx_texture_to_image(data->mlx, data->player_t);
	mlx_image_to_window(data->mlx, data->player_img, data->j \
	* 60, data->i * 84);
}

void	output_win(t_game *game)
{
	game->map_move = ft_itoa(game->moves);
	if (game->line_move)
		mlx_delete_image(game->mlx, game->line_move);
	game->line_move = mlx_put_string(game->mlx, game->map_move, 30, 500);
	free(game->map_move);
}

void	output_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	output_img(game);
	player_position(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall_img, j * 60, i * 84);
			else if (game->map[i][j] == 'P')
				mlx_image_to_window(game->mlx, game->player_img, \
				j * 60, i * 84);
			else if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->collect_img, \
				j * 60, i * 84);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->exit_img, j * 60, i * 84);
			j++;
		}
		i++;
	}
}
