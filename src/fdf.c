/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:15:15 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/09 14:25:12 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>	// for stderr
#include <fcntl.h>	// for RDONLY
#include <math.h>

// @brief	Prints out error message and exits program
void	fdf_mlx_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static t_pixel	*convert_hm_node_to_pixel(t_hm_node *node)
{
	t_pixel		*pixel;

	pixel = malloc(sizeof(t_pixel));
	if (pixel)
	{
		pixel->x_coord = (node->x_coord - node->z_coord) / sqrt(2);
		pixel->y_coord = (node->x_coord + 2 * node->y_coord + node->z_coord) \
							/ sqrt(6);
		pixel->color = get_rgba(get_col_rgb(node->color_hex, 'r'), \
								get_col_rgb(node->color_hex, 'g'), \
								get_col_rgb(node->color_hex, 'b'), 0);
	}
	return (pixel);
}

static t_pixel	***loop_through_all_nodes(t_hm_node ***heightmap)
{
	t_pixel	***pixelmap;
	t_pixel	**pixelrow;
	int		x;
	int		y;
	int		heightmap_size_y;
	int		heightmap_size_x;

	heightmap_size_x = 0;
	heightmap_size_y = 0;
	while (heightmap[heightmap_size_y])
		heightmap_size_y++;
	while (heightmap[0][heightmap_size_x])
		heightmap_size_x++;
	pixelmap = malloc(sizeof(t_pixel **) * heightmap_size_y);
	y = 0;
	while (heightmap[y])
	{
		x = 0;
		while (heightmap[y][x])
		{
			x++;
		}
		y++;
	}
	// thats complicated and dysfunctional. instead, convert the coords into a pixel map right away in the input function. there we have the setup to do it easily already. also keep track of array dimensions and pass them back. this skips the whole purpose of step 1.
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
	draw_line(img, (t_pixel){DEFAULT_WIDTH - 100, DEFAULT_HEIGHT - 1, \
					get_rgba(255, 0, 0, 255)}, \
					(t_pixel){0, 0, get_rgba(0, 255, 0, 255)});
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	return (mlx);
}

int	main(int argc, char	*argv[])
{
	t_hm_node		***heightmap;
	t_pixel			***pixelmap;
	int				fd;

	if (argc == 2)
	{
		fd = open(argv[2], O_RDONLY);
		heightmap = fdf_get_heightmap(fd);
		if (!heightmap)
			return (0);
		pixelmap = loop_through_all_nodes(heightmap);
		fdf_init();
	}
}

/*
	1. loop through all nodes, convert each 3d node to a 2d pixel, return 2d pixel array
	2. loop through all pixels, drawing a line between the current pixel and its top neightbour and right neighbour if they exist
	3. play mario wonder
*/