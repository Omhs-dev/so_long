/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:34:38 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/14 03:05:41 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map(t_game *p)
{
	char	*line;
	char	*holder_map;
	char	*holder;
	int		fd;

	fd = open(p->name, O_RDONLY);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		if (next_line_true(holder_map))
			break ;
		free(line);
		free(holder);
	}
	p->map = ft_split(holder_map, '\n');
	p->map_c = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
}

int	count_collect(t_game *game)
{
	int	i;

	i = is_validate(game, 'C');
	return (i);
}

int	m_width(char *name)
{
	int		fd;
	int		length;
	char	*game;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	game = get_next_line(fd);
	length = 0;
	if (game)
	{
		length = ft_strlen(game);
		free(game);
	}
	close(fd);
	return (length);
}

int	m_height(char *name)
{
	int		i;
	char	*rows;
	int		fd;

	i = 0;
	fd = open(name, O_RDONLY);
	rows = get_next_line(fd);
	if (fd < 0)
	{
		return (-1);
		free(rows);
	}
	while (rows != NULL)
	{
		i++;
		rows = get_next_line(fd);
	}
	close(fd);
	return (i);
}
