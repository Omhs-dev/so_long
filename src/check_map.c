/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:07:21 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/13 22:04:16 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_rectangular(t_game *game)
{
	int	i;

	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i - 1]) != ft_strlen(game->map[i]))
			return (free_map(game->map), 0);
		i++;
	}
	return (1);
}

int	is_validate(t_game *game, char c)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C'
				&& game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
			if (game->map[i][j] == c)
				e++;
			j++;
		}
		j = 0;
		i++;
	}
	return (e);
}

int	check_map(t_game *game, int i, int j)
{
	while (game->map[i] && game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}
	while (game->map[i])
		i++;
	i--;
	j = 0;
	while (game->map[i] && game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	check_map_c(t_game *game, int i, int j)
{
	while (game->map[i] && game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}
	while (game->map[i])
		i++;
	i--;
	j = 0;
	while (game->map[i] && game->map[i][j])
	{
		if (game->map[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
