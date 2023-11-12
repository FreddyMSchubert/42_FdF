/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:28:47 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 09:23:23 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

#include <math.h>

static void	update_rotate_mode(t_view_settings *settings)
{
	int	rotate_speed;

	rotate_speed = 1;
	if (settings->rotate_mode_pitch == 1)
		settings->pitch += rotate_speed;
	if (settings->rotate_mode_yaw == 1)
		settings->yaw += rotate_speed;
	if (settings->rotate_mode_roll == 1)
		settings->roll += rotate_speed;
}

static t_pixel	*convert_hm_node_to_pixel_iso(t_hm_node *node, \
				t_view_settings *settings)
{
	t_pixel		*pixel;
	int			x;
	int			y;
	int			z;

	x = node->x_coord * settings->zoom;
	y = node->y_coord * settings->zoom;
	z = node->z_coord * settings->zoom * settings->depth_mod;
	rotate_node(&x, &y, &z, settings);
	pixel = malloc(sizeof(t_pixel));
	if (pixel)
	{
		pixel->x_coord = (x - z) / sqrt(2);
		pixel->y_coord = (x + 2 * y + z) / sqrt(6);
		pixel->color = hex_to_rgba(node->color_hex, 255);
	}
	pixel->x_coord += settings->x_offset * COORD_SPREAD;
	pixel->y_coord += settings->y_offset * COORD_SPREAD;
	return (pixel);
}

static t_pixel	**convert_hm_node_line_to_pixel_line(t_hm_node **nodes, \
				t_view_settings *settings)
{
	int			width;
	t_pixel		**pixels;
	int			counter;

	width = 0;
	while (nodes[width])
		width++;
	pixels = malloc (sizeof(t_hm_node **) * (width + 1));
	counter = 0;
	while (pixels && counter < width - 1)
	{
		pixels[counter] = convert_hm_node_to_pixel_iso(nodes[counter], \
														settings);
		if (pixels[counter] == NULL)
			return (fdf_free_rec((void **)pixels), NULL);
		counter++;
	}
	pixels[counter] = NULL;
	return (pixels);
}

t_pixel	***convert_hm_node_grid_to_pixel_grid(t_hm_node ***nodes, \
				t_view_settings *settings)
{
	int			height;
	t_pixel		***pixels;
	int			counter;

	height = 0;
	while (nodes[height])
		height++;
	pixels = malloc (sizeof(t_hm_node ***) * height);
	counter = 0;
	update_rotate_mode(settings);
	while (pixels && counter < height - 1)
	{
		pixels[counter] = convert_hm_node_line_to_pixel_line(nodes[counter], \
														settings);
		if (pixels[counter] == NULL)
			return (fdf_free_rec_rec((void ***)pixels), NULL);
		counter++;
	}
	pixels[counter] = NULL;
	return (pixels);
}
