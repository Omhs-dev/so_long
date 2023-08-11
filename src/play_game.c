/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:37:30 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/11 17:56:05 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


// int	check(t_game *game)
// {
// 	if (check_map1(game, 0, 0)
// 		&& check_map(game, 0, 0)
// 		&& check_count(game, 'E') == 1
// 		&& check_count(game, 'P') == 1
// 		&& check_count(game, 'C') != 0
// 		&& valid_path(game)
// 		&& rect_check(game))
// 		return (0);
// 	ft_printf("Error\nmap invalid\n");
// 	return (1);
// }

int	start(char *game)
{
	t_game	*d;
	mlx_t	*mlx;

	d = malloc(sizeof(t_game));
	if (d == NULL)
		return (0);
	d->name = game;
	read_map(d);
	d->map_w = width(d->name);
	d->map_h = height(d->name);
	d->move = 0;
	d->collect = 0;
	// d->n_collect = col_count(d);
	if (map_checker(d))
		return (0);
	d->mlx = mlx_init((d->map_w -1) * 60, (d->map_h) * 84, "game", false);
	map_construct(d);
	mlx_key_hook(d->mlx, &ft_hook, d);
	mlx_loop_hook(d->mlx, &player_render, d);
	print_screen(d);
	mlx_loop(d->mlx);
	free_img(d);
	return (0);
}

// void playgame(t_game *game)
// {
// 	mlx_key_hook(game->mlx, &game_events, )
// }