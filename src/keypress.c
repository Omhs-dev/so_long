/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:49:57 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/13 22:13:28 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	key_p_w(t_game *game)
{
	if (game->map[game->i - 1][game->j] != '1')
	{
		if (game->map[game->i - 1][game->j] == 'C')
		{
			game->map[game->i - 1][game->j] = '0';
			mlx_delete_image(game->mlx, game->collect_img);
			game->collect_img = mlx_texture_to_image(game->mlx, \
			game->collect_t);
			game->n_collect--;
			replacing_coll(game);
		}
		if (game->n_collect == 0 && game->map[game->i - 1][game->j] == 'E')
		{
			mlx_delete_image(game->mlx, game->player_img);
			mlx_close_window(game->mlx);
			return ;
		}
		game->i = game->i - 1;
		game->moves++;
		ft_printf("moves count:%d\n", game->moves);
		output_win(game);
	}
}

void	key_p_a(t_game *game)
{
	if (game->map[game->i][game->j - 1] != '1')
	{
		if (game->map[game->i][game->j] == 'C')
		{
			game->map[game->i][game->j] = '0';
			mlx_delete_image(game->mlx, game->collect_img);
			game->collect_img = mlx_texture_to_image(game->mlx, \
			game->collect_t);
			game->n_collect--;
			replacing_coll(game);
		}	
		if (game->n_collect == 0 && game->map[game->i][game->j - 1] == 'E')
		{
			mlx_delete_image(game->mlx, game->player_img);
			mlx_close_window(game->mlx);
			return ;
		}
		game->j = game->j - 1;
		game->moves++;
		ft_printf("moves count:%d\n", game->moves);
		output_win(game);
	}
}

void	key_p_s(t_game *game)
{
	if (game->map[game->i + 1][game->j] != '1')
	{
		if (game->map[game->i + 1][game->j] == 'C')
		{
			game->map[game->i + 1][game->j] = '0';
			mlx_delete_image(game->mlx, game->collect_img);
			game->collect_img = mlx_texture_to_image(game->mlx, \
			game->collect_t);
			game->n_collect--;
			replacing_coll(game);
		}
		if (game->n_collect == 0 && game->map[game->i + 1][game->j] == 'E')
		{
			mlx_delete_image(game->mlx, game->player_img);
			mlx_close_window(game->mlx);
			return ;
		}
		game->i = game->i + 1;
		game->moves++;
		ft_printf("moves count:%d\n", game->moves);
		output_win(game);
	}
}

void	key_p_d(t_game *game)
{
	if (game->map[game->i][game->j + 1] != '1')
	{
		if (game->map[game->i][game->j + 1] == 'C')
		{
			game->map[game->i][game->j + 1] = '0';
			mlx_delete_image(game->mlx, game->collect_img);
			game->collect_img = mlx_texture_to_image(game->mlx, \
			game->collect_t);
			game->n_collect--;
			replacing_coll(game);
		}
		if (game->n_collect == 0 && game->map[game->i][game->j + 1] == 'E')
		{
			mlx_delete_image(game->mlx, game->player_img);
			mlx_close_window(game->mlx);
			return ;
		}
		game->j = game->j + 1;
		game->moves++;
		ft_printf("moves count:%d\n", game->moves);
		output_win(game);
	}
}
