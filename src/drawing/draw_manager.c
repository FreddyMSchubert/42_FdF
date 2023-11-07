/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:51:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/07 13:36:39 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
	@brief			Returns an array of pixels that are a line using Bresenham
	@param mlx 		Window to draw to
	@param a 		Pixel 1. Must never be right of above Pixel 2
	@param b 		Pixel 2. Must never be left or below Pixel 1
*/
void	draw_line(mlx_t mlx, t_pixel a, t_pixel b)
{
	int			error;
	t_pixel		*pixels;
	t_pixel		curr_pixel;

	curr_pixel = a;
	if ((b.x_coord - a.x_coord) > (b.y_coord - a.y_coord))
	{
		error = (b.x_coord - a.x_coord) / 2;
		pixels = malloc(sizeof(t_pixel) * (b.x_coord - a.x_coord));
		while (curr_pixel.x_coord < b.x_coord)
		{
			pixels[curr_pixel.x_coord - a.x_coord] = curr_pixel;
			error -= (b.y_coord - a.y_coord);
			if (error >= 0)
				continue ;
			curr_pixel.y_coord++;
			error = error + (b.x_coord - a.x_coord);
		}
	}
	else
	{
		error = (b.y_coord - a.y_coord) / 2;
		pixels = malloc(sizeof(t_pixel) * (b.y_coord - a.y_coord));
	}
}

mlx_t	*fdf_init(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(DEFAULT_WIDTH, DEFAULT_HEIGHT, PROGRAM_NAME, true);
	if (!mlx)
		fdf_mlx_error();
	ft_printf("Instantiated new window (%d|%d).\n", mlx->width, mlx->height);
	img = mlx_new_image(mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		fdf_mlx_error();
	mlx_put_pixel(img, DEFAULT_WIDTH / 2 - 1, \
		DEFAULT_HEIGHT / 2 - 1, 0xFF0000FF);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (mlx);
}

int	main(void)
{
	fdf_init();
}
