/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:30:52 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 17:56:49 by fschuber         ###   ########.fr       */
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
				Types: e - Error, l - Logger, s - Success, k - Keypress;
*/
void	logger(char type, char *message)
{
	if (type == 'e')
		ft_printf("\033[31mERROR\033[0m: ");
	if (type == 'l')
		ft_printf("\033[33mLOGGER\033[0m: ");
	if (type == 's')
		ft_printf("\033[32mSUCCESS\033[0m: ");
	if (type == 'k')
		ft_printf("\033[34mKEYPRESS\033[0m: ");
	ft_printf("%s", message);
}

// @brief		Returns a settings struct with default settings.
t_view_settings	*initialize_settings(mlx_t	*mlx, mlx_image_t	*img, \
									t_hm_node	***heightmap)
{
	t_view_settings		*settings;

	settings = malloc(sizeof(t_view_settings));
	settings->projection = 'i';
	settings->zoom = 10;
	settings->x_offset = 0;
	settings->y_offset = 0;
	settings->yaw = 0;
	settings->pitch = 0;
	settings->roll = 0;
	settings->rotate_mode = 0;
	settings->mlx = mlx;
	settings->img = img;
	settings->heightmap = heightmap;
	return (settings);
}
