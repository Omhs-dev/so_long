/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:34:38 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/12 23:49:09 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	read_map(t_game *p)
// {
// 	char	*line;
// 	char	*holder_map;
// 	char	*holder;
// 	int		fd;

// 	fd = open(p->name, O_RDONLY);
// 	holder_map = ft_strdup("");
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		holder = holder_map;
// 		holder_map = ft_strjoin(holder, line);
// 		free(line);
// 		free(holder);
// 	}
// 	p->map = ft_split(holder_map, '\n');
// 	p->map_c = ft_split(holder_map, '\n');
// 	free(holder_map);
// 	close(fd);
// }

void	read_map(t_game *p)
{
	int		fd1;
	char	*str;
	char	*ret;
	char	*temp;
	int		i;

	i = 0;
	ret = malloc(1);
	ret[0] = '\0';
	fd1 = open(p->name, O_RDONLY);
	str = get_next_line(fd1);
	while (str != NULL)
	{
		temp = ft_strjoin(ret, str);
		free(ret);
		ret = temp;
		free(str);
		str = get_next_line(fd1);
		if (!str)
			printf("empty line\n");
	}
	p->map = ft_split(ret, '\n');
	p->map_c = ft_split(ret, '\n');
	close(fd1);
	free(ret);
}

int count_collect(t_game *game)
{
	int i;

	i = is_validate(game, 'C');
	return (i);
}


int	width(char *name)
{
	int		fd;
	int		length;
	char	*game;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (0);
	game = get_next_line(fd);
	length = ft_strlen(game);
	close(fd);
	free(game);
	return (length);
}

int	height(char *name)
{
	int		i;
	char	*rows;
	int		fd;

	i = 0;
	fd = open(name, O_RDONLY);
	rows = get_next_line(fd);
	while (rows != NULL)
	{
		free(rows);
		i++;
		rows = get_next_line(fd);
	}
	close(fd);
	return (i);
}