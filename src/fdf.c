/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:15:15 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/10 13:07:48 by fschuber         ###   ########.fr       */
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

void	fdf_draw_lines(mlx_image_t	*img, t_pixel	***pixelmap)
{
	int		width;
	int		height;
	int		x;
	int		y;

	t_pixel pix1 = (t_pixel){100, 245, 0xFFFFFF, 0};
	t_pixel pix2 = (t_pixel){100, 255, 0xFFFFFF, 0};
	draw_line(img, &pix1, &pix2);
	width = get_pixelmap_width(pixelmap);
	height = get_pixelmap_height(pixelmap);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
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

mlx_t	*fdf_init(t_pixel	***pixelmap)
{
	mlx_t			*mlx;
	mlx_image_t		*img;

	mlx = mlx_init(DEFAULT_WIDTH, DEFAULT_HEIGHT, PROGRAM_NAME, true);
	if (!mlx)
		fdf_mlx_error();
	img = mlx_new_image(mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		fdf_mlx_error();
	logger('l', "Window initialized.\n");
	fdf_draw_lines(img, pixelmap);
	logger('s', "Heightmap drawn.\n");
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char	*argv[])
{
	t_hm_node		***heightmap;
	t_pixel			***pixelmap;
	int				fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (logger('e', "Invalid file path.\n"), 0);
		heightmap = fdf_get_heightmap(fd);
		if (!heightmap)
			return (logger('e', "Input reading failed.\n"), 0);
		pixelmap = convert_hm_node_grid_to_pixel_grid(heightmap);
		logger('l', "Converted node data into pixel format.\n");
		fdf_init(pixelmap);
		logger('l', "Shutting down.\n");
		return (1);
	}
	else
		logger('e', "Wrong number of arguments inputted.\n");
}
