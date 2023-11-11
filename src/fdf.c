/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:15:15 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 08:29:11 by fschuber         ###   ########.fr       */
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

/*
	@brief		Logs a message with a type in front.
				Types: e - Error, l - Logger, s - Success.
*/
void	logger(char type, char *message)
{
	if (type == 'e')
		ft_printf("\033[31mERROR\033[0m: ");
	if (type == 'l')
		ft_printf("\033[33mLOGGER\033[0m: ");
	if (type == 's')
		ft_printf("\033[32mSUCCESS\033[0m: ");
	ft_printf("%s", message);
}

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

	if (argc == 2)
	{
		heightmap = fdf_get_heightmap(open(argv[1], O_RDONLY));
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
