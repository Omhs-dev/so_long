/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:09:04 by ohamadou          #+#    #+#             */
/*   Updated: 2023/08/02 16:18:53 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"

static mlx_image_t* img;

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		img->instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		img->instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		img->instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		img->instances[0].x += 5;
}

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	img = mlx_new_image(mlx, 55, 55);
	
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Display an instance of the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}