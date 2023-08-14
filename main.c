/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:06:41 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/14 02:57:59 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main( int argc, char **argv)
{
	int		check;
	t_game	*play;

	if (argc == 1)
		return (ft_printf("Error\nplease: use a .ber file\n"));
	if (argc > 2)
		return (ft_printf("Error\ntoo many arguments\n"));
	check = check_ber(argv[1]);
	if (check == 1)
		return (ft_printf("Error\nPlease: use a valid map\n"));
	play = start_game(argv[1]);
	if (!play)
	{
		free(play);
		exit(EXIT_FAILURE);
	}
	play->mlx = mlx_init((play->map_w - 1) * 60, (play->map_h) * 48, \
	"So Long", false);
	output_map(play);
	output_win(play);
	mlx_key_hook(play->mlx, &ft_hook, play);
	mlx_loop_hook(play->mlx, &output_player, play);
	mlx_loop(play->mlx);
	exit_game(play);
	return (0);
}
