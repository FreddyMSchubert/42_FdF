/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:32:19 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 10:50:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_draw_lines(mlx_image_t	*img, t_pixel	***pixelmap)
{
	int		x;
	int		y;
	int		width;

	width = 0;
	while (pixelmap[0][width])
		width++;
	y = 0;
	while (pixelmap[y])
	{
		x = 0;
		while (pixelmap[y][x])
		{
			if (y - 1 >= 0)
				draw_line(img, pixelmap[y][x], pixelmap[y - 1][x]);
			if (x + 1 < width)
				draw_line(img, pixelmap[y][x], pixelmap[y][x + 1]);
			x++;
		}
		y++;
	}
}

void	refresh_screen(t_view_settings *settings)
{
	t_pixel		***pixelmap;
	int			x;
	int			y;

	y = 0;
	while (y < settings->mlx->height)
	{
		x = 0;
		while (x < settings->mlx->width)
		{
			mlx_put_pixel(settings->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	pixelmap = convert_hm_node_grid_to_pixel_grid(settings->heightmap, \
													settings);
	fdf_draw_lines(settings->img, pixelmap);
}
