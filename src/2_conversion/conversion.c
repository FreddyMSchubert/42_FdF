/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:28:47 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/10 17:40:54 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

#include <math.h>

static t_pixel	*convert_hm_node_to_pixel(t_hm_node *node)
{
	t_pixel		*pixel;

	pixel = malloc(sizeof(t_pixel));
	if (pixel)
	{
		pixel->x_coord = (node->x_coord - node->z_coord) / sqrt(2);
		pixel->y_coord = (node->x_coord + 2 * node->y_coord + node->z_coord) \
							/ sqrt(6);
		pixel->color = hex_to_rgba(node->color_hex, 255);
		pixel->terminator = node->terminator;
	}
	return (pixel);
}

static t_pixel	**convert_hm_node_line_to_pixel_line(t_hm_node **nodes)
{
	int			width;
	t_pixel		**pixels;
	int			counter;

	width = 0;
	while (nodes[width]->terminator != 1)
		width++;
	pixels = malloc (sizeof(t_hm_node **) * (width + 1));
	counter = 0;
	while (pixels && counter < width + 1)
	{
		pixels[counter] = convert_hm_node_to_pixel(nodes[counter]);
		if (pixels[counter] == NULL)
			return (fdf_free_rec((void **)pixels), NULL);
		counter++;
	}
	return (pixels);
}

t_pixel	***convert_hm_node_grid_to_pixel_grid(t_hm_node ***nodes)
{
	int			height;
	t_pixel		***pixels;
	int			counter;

	height = 0;
	while (nodes[height][0]->terminator != 1)
		height++;
	pixels = malloc (sizeof(t_hm_node ***) * height);
	counter = 0;
	while (pixels && counter < height + 1)
	{
		pixels[counter] = convert_hm_node_line_to_pixel_line(nodes[counter]);
		if (pixels[counter] == NULL)
			return (fdf_free_rec_rec((void ***)pixels), NULL);
		counter++;
	}
	return (pixels);
}
