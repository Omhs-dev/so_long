/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:09:04 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/23 17:01:47 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

static mlx_image_t* image;

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	// const mlx_t* mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (mlx_is_key_down(param, MLX_KEY_UP))
		image -> instances[0].y -= 5;
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
		image -> instances[0].y += 5;
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
		image -> instances[0].x -= 5;
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
		image -> instances[0].x += 5;
	// printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	mlx_texture_t* texture = mlx_load_png("images/luffy.png");
	// Create and display the image.
	image = mlx_texture_to_image(mlx, texture);
	// if (!image || (mlx_image_to_window(mlx, image, 0, 0) < 0))
	// 	ft_error();
	// memset(image->pixels, 255, image->width * image->height * BPP);
	mlx_image_to_window(mlx, image, 0, 0);
	// Even after the image is being displayed, we can still modify the buffer.
	// mlx_put_pixel(image, 0, 0, 0x0000FF00);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
