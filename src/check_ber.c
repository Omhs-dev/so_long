/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:43:01 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/13 22:03:34 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_ber(char *str)
{
	int	i;
	int	fd1;

	i = 0;
	fd1 = open(str, O_RDONLY);
	if (fd1 < 0)
	{
		close(fd1);
		return (1);
	}
	close(fd1);
	while (str[i])
		i += 1;
	while (i >= 4)
	{
		if (str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
			&& str[i - 4] == '.')
			return (0);
		i--;
	}
	return (1);
}

// int	check_ber(char *name)
// {
// 	int	len;
// 	int	fd1;

// 	fd1 = open(name, O_RDONLY);
// 	if (fd1 < 0)
// 	{
// 		close(fd1);
// 		return (1);
// 	}
// 	close(fd1);
// 	len = ft_strlen(name);
// 	while (len >= 0)
// 	{
// 		if (name[len] == '.')
// 		{
// 			if (name[len + 1] == 'b' && name[len + 2] == 'e'
// 				&& name[len + 3] == 'r')
// 				return (0);
// 			else
// 				return (1);
// 		}
// 		len--;
// 	}
// 	return (1);
// }

// int main(void)
// {
// 	check_ber("test.be");
// }