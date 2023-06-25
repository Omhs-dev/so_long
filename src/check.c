/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:43:01 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/25 20:31:11 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_ber(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i += 1;
	while (i)
	{
		--i;
		if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
			&& str[i - 3] == '.')
			return (1);
	}
	return (0);
}

// int main(void)
// {
// 	check_ber("test.be");
// }