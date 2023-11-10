/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 06:28:47 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/10 11:38:34 by fschuber         ###   ########.fr       */
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

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	t_pixel		***pixels;
// 	t_hm_node	***nodes;
// 	int			fd = open("./etc/test_maps/42.fdf", O_RDONLY);

// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	nodes = fdf_get_heightmap(fd);
// 	ft_printf("Successfully received nodes. Now converting to pixels!\n");
// 	pixels = convert_hm_node_grid_to_pixel_grid(nodes);
// 	for (int y = 0; pixels[y][0]->terminator != 1; y++)
// 	{
// 		for (int x = 0; pixels[y][x]->terminator != 1; x++)
// 		{
// 			ft_printf("woo! (%d|%d) - (%d, %d, %d, %d)\n", pixels[y][x]->x_coord, pixels[y][x]->y_coord, get_col_rgba(pixels[y][x]->color, 'r'), get_col_rgba(pixels[y][x]->color, 'g'), get_col_rgba(pixels[y][x]->color, 'b'), get_col_rgba(pixels[y][x]->color, 'a'));
// 		}
// 		ft_printf("\n");
// 	}
// }
