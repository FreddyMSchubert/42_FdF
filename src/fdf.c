/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:15:15 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 10:23:33 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>	// for RDONLY
#include <math.h>

mlx_t	*fdf_init(t_hm_node	***heightmap)
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	t_view_settings		*settings;

	mlx = mlx_init(DEFAULT_WIDTH, DEFAULT_HEIGHT, PROGRAM_NAME, true);
	if (!mlx)
		fdf_mlx_error();
	img = mlx_new_image(mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		fdf_mlx_error();
	settings = initialize_settings(mlx, img, heightmap);
	logger('l', "Window initialized.\n");
	refresh_screen(settings);
	logger('s', "Heightmap drawn.\n");
	mlx_key_hook(mlx, &key_handler, settings);
	logger('l', "Key input hook initalized.\n");
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}

int	main(int argc, char	*argv[])
{
	t_hm_node		***heightmap;

	if (argc == 2)
	{
		heightmap = fdf_get_heightmap(open(argv[1], O_RDONLY));
		if (!heightmap)
			return (logger('e', "Input reading failed.\n"), 0);
		fdf_init(heightmap);
		logger('l', "Shutting down.\n");
		return (1);
	}
	else
		logger('e', "Wrong number of arguments inputted.\n");
}
