/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:51:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/09 08:12:14 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include <math.h>

// @brief		Draws pixel pxl on lmx at specified position and color
// int	draw_pixel(mlx_t mlx, t_pixel pxl)
// {
	
// }

// @brief		gets step size for a gradient of length l
//				between c1 and c2 on color channel col
static double	get_color_gradient_step(int l, int c1, int c2, char col)
{
	double		step;

	if (l < 2)
		return (c1);
	step = (double)(get_col(c2, col) - get_col(c1, col)) / (l - 1);
	return (step);
}

/*
	@returns		Dynamically allocated array of length l containing a
					color feed between including the colors c1 and c2
*/
int	*get_gradient(int l, int c1, int c2)
{
	int		i;
	int		*colors;

	i = 0;
	colors = malloc(sizeof(int) * l);
	if (!colors)
		return (NULL);
	while (i < l)
	{
		colors[i] = get_rgba(\
			get_col(c1, 'r') + i * get_color_gradient_step(l, c1, c2, 'r'), \
			get_col(c1, 'g') + i * get_color_gradient_step(l, c1, c2, 'g'), \
			get_col(c1, 'b') + i * get_color_gradient_step(l, c1, c2, 'b'), \
			get_col(c1, 'a') + i * get_color_gradient_step(l, c1, c2, 'a'));
		i++;
	}
	return (colors);
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
