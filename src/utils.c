/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:44:45 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/13 22:15:04 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	next_line_true(char *line_str)
{
	int	i;

	i = 0;
	while (line_str[i + 1])
	{
		if (line_str[i] == '\n' && line_str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	map_checker(t_game *game)
{
	if (check_map_c(game, 0, 0)
		&& check_map(game, 0, 0)
		&& is_validate(game, 'E')
		&& is_validate(game, 'P')
		&& is_validate(game, 'C') != 0
		&& valid_path(game)
		&& is_rectangular(game))
		return (0);
	ft_printf("Error\nPlease: use a valid map\n");
	return (1);
}

void	replacing_coll(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->collect_img, j * 60, \
					i * 84);
			j++;
		}
		i++;
	}
}
