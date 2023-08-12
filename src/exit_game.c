/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:32:20 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/12 05:13:53 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	exit_game(t_game *game)
{	
	mlx_delete_texture(game->player_t);
	mlx_delete_image(game->mlx, game->player_img);
	mlx_delete_texture(game->wall_t);
	mlx_delete_image(game->mlx, game->wall_img);
	mlx_delete_texture(game->collect_t);
	if (game->collect_img != NULL)
		mlx_delete_image(game->mlx, game->collect_img);
	mlx_delete_texture(game->exit_t);
	mlx_delete_image(game->mlx, game->exit_img);
	free_map(game->map);
	free_map(game->map_c);
	mlx_terminate(game->mlx);
	free(game);
}
