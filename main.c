/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:06:41 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/12 23:23:02 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	map_checker(t_game *game)
{
	if (check_map_c(game, 0, 0)
		&& check_map(game, 0, 0)
		&& is_validate(game, 'E') == 1
		&& is_validate(game, 'P') == 1
		&& is_validate(game, 'C') != 0
		&& valid_path(game)
		&& is_rectangular(game))
		return (0);
	ft_printf("Error\nmap invalid\n");
	return (1);
}

int	start_game(char *game)
{
	t_game	*d;
	// mlx_t	*mlx;

	d = malloc(sizeof(t_game));
	if (d == NULL)
		return (0);
	d->name = game;
	read_map(d);
	d->map_w = width(d->name);
	d->map_h = height(d->name);
	d->moves = 0;
	d->collect = 0;
	d->n_collect = count_collect(d);
	if (map_checker(d))
		return (0);
	d->mlx = mlx_init((d->map_w - 1) * 60, (d->map_h) * 48, "game", false);
	output_map(d);
	mlx_key_hook(d->mlx, &ft_hook, d);
	mlx_loop_hook(d->mlx, &output_player, d);
	output_win(d);
	mlx_loop(d->mlx);
	exit_game(d);
	return (0);
}

int	main( int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "Please give valid .ber file", 27);
		return (0);
	}
	i = check_ber(argv[1]);
	if (i == 1)
	{
		printf("Error\nmap invalid\n");
		return (0);
	}
	start_game(argv[1]);
	system("leak so_long");
	return (0);
}
