/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:06:41 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/11 15:56:10 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	main( int argc, char **argv)
{
	int	i;

	if (argc != 2)
	{
		write(1, "Please give valid .ber file", 27);
		return (0);
	}
	i = check_filename(argv[1]);
	if (i == 1)
	{
		printf("Error\nmap invalid\n");
		return (0);
	}
	start(argv[1]);
	return (0);
}
