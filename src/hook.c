/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:38:01 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/12 23:23:58 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_hook(mlx_key_data_t key_game, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (key_game.key == MLX_KEY_ESCAPE && key_game.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (key_game.key == MLX_KEY_D && key_game.action == MLX_PRESS)
		key_p_d(game);
	else if (key_game.key == MLX_KEY_W && key_game.action == MLX_PRESS)
		key_p_w(game);
	else if (key_game.key == MLX_KEY_S && key_game.action == MLX_PRESS)
		key_p_s(game);
	else if (key_game.key == MLX_KEY_A && key_game.action == MLX_PRESS)
		key_p_a(game);
}
