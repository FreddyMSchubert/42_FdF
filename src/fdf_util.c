/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:30:52 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 10:19:31 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

// @brief	Prints out error message and exits program
void	fdf_mlx_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

/*
	@brief		Logs a message with a type in front.
				Types: e - Error, l - Logger, s - Success, i - Input, m - Scroll
*/
void	logger(char type, char *message)
{
	if (type == 'e')
		ft_printf("\033[31mERROR\033[0m: ");
	if (type == 'l')
		ft_printf("\033[33mLOGGER\033[0m: ");
	if (type == 's')
		ft_printf("\033[32mSUCCESS\033[0m: ");
	if (type == 'i')
		ft_printf("\033[34mINPUT\033[0m: ");
	if (type == 'm')
		ft_printf("\033[34mSCROLL\033[0m: ");
	ft_printf("%s", message);
}

// @brief		Returns a settings struct with default settings.
t_view_settings	*initialize_settings(mlx_t	*mlx, mlx_image_t	*img, \
									t_hm_node	***heightmap, \
									t_keys_held	*keys)
{
	t_view_settings		*settings;

	settings = malloc(sizeof(t_view_settings));
	if (!settings)
		return (NULL);
	settings->projection = 'i';
	settings->zoom = 1;
	settings->x_offset = 92;
	settings->y_offset = 121;
	settings->yaw = -90;
	settings->pitch = -245;
	settings->roll = 28;
	settings->frame = 0;
	settings->rotate_mode_pitch = 0;
	settings->rotate_mode_roll = 0;
	settings->rotate_mode_yaw = 1;
	settings->depth_mod = 10;
	settings->keys = keys;
	settings->mlx = mlx;
	settings->img = img;
	settings->heightmap = heightmap;
	return (settings);
}

t_keys_held	*initialize_keys(void)
{
	t_keys_held		*keys;

	keys = malloc(sizeof(t_keys_held));
	if (!keys)
		return (NULL);
	keys->h = 0;
	keys->p = 0;
	keys->r = 0;
	keys->y = 0;
	keys->vert = 0;
	keys->hori = 0;
	keys->mouse = 0;
	keys->mouse_x = -1;
	keys->mouse_y = -1;
	return (keys);
}
