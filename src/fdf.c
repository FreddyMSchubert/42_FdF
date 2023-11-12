/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:15:15 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 10:48:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <fcntl.h>	// for RDONLY
#include <math.h>

void	generic_hook(void *param)
{
	t_view_settings		*settings;

	settings = (t_view_settings *)param;
	settings->frame++;
	if (settings->rotate_mode_pitch == 1 || \
		settings->rotate_mode_roll == 1 || \
		settings->rotate_mode_yaw == 1)
		refresh_screen(settings);
	if (mlx_is_mouse_down(settings->mlx, MLX_MOUSE_BUTTON_LEFT))
		mouse_handler(settings);
}

void	closing_hook(void *param)
{
	t_view_settings		*settings;

	settings = (t_view_settings *)param;
	fdf_free_rec_rec((void ***)settings->heightmap);
	// mlx_terminate(settings->mlx);
	logger('i', "Shutting down program...\n");
}

mlx_t	*fdf_init(t_hm_node	***heightmap)
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	t_view_settings		*settings;
	t_keys_held			*keys;

	mlx = mlx_init(DEFAULT_WIDTH, DEFAULT_HEIGHT, PROGRAM_NAME, true);
	if (!mlx)
		fdf_mlx_error();
	img = mlx_new_image(mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		fdf_mlx_error();
	keys = initialize_keys();
	settings = initialize_settings(mlx, img, heightmap, keys);
	logger('l', "Window initialized.\n");
	refresh_screen(settings);
	logger('s', "Heightmap drawn.\n");
	mlx_key_hook(mlx, &key_handler, settings);
	mlx_scroll_hook(mlx, &scroll_handler, settings);
	mlx_loop_hook(mlx, &generic_hook, settings);
	mlx_close_hook(mlx, &closing_hook, settings);
	logger('l', "Input hooks initalized.\n");
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
