/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:06:41 by ohamadou          #+#    #+#             */
/*   Updated: 2023/07/21 16:49:55 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int main(int argc, char **argv)
{
	t_game game;
	
	if (argc == 2)
	{
		game.map = read_map(argv[1]);
		if (check_map(&game) && check_ber(&game))
		{
			
		}
	}
}