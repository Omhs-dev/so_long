/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:43:01 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/12 20:20:41 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// int check_ber(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 		i += 1;
// 	while (i)
// 	{
// 		--i;
// 		if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
// 			&& str[i - 3] == '.')
// 			return (1);
// 	}
// 	return (0);
// }

int	check_ber(char *name)
{
	int	len;
	int	fd1;

	fd1 = open(name, O_RDONLY);
	if (fd1 < 0)
	{
		close(fd1);
		return (1);
	}
	close(fd1);
	len = ft_strlen(name);
	while (len >= 0)
	{
		if (name[len] == '.')
		{
			if (name[len + 1] == 'b' && name[len + 2] == 'e'
				&& name[len + 3] == 'r')
				return (0);
			else
				return (1);
		}
		len--;
	}
	return (1);
}

// int main(void)
// {
// 	check_ber("test.be");
// }