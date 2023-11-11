/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:10:39 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 16:51:44 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// @brief		resets settings
void	kenter(t_view_settings *settings)
{
	t_view_settings		*defaults;

	defaults = initialize_settings(settings->mlx, settings->img, \
									settings->heightmap);
	settings->projection = defaults->projection;
	settings->zoom = defaults->zoom;
	settings->x_offset = defaults->x_offset;
	settings->y_offset = defaults->y_offset;
	settings->yaw = defaults->yaw;
	settings->pitch = defaults->pitch;
	settings->roll = defaults->roll;
	settings->rotate_mode = defaults->rotate_mode;
	logger('l', "Default settings restored.\n");
}

// @brief		displays debug log
void	k0(t_view_settings *settings)
{
	ft_printf("\n   DEBUG LOG!\n");
	ft_printf("     width:       %d\n", settings->mlx->width);
	ft_printf("     height:      %d\n", settings->mlx->height);
	ft_printf("     projection:  %c\n", settings->projection);
	ft_printf("     zoom:        %d\n", settings->zoom);
	ft_printf("     x offset:    %d\n", settings->x_offset);
	ft_printf("     y offset:    %d\n", settings->y_offset);
	ft_printf("     yaw:         %d\n", settings->yaw);
	ft_printf("     pitch:       %d\n", settings->pitch);
	ft_printf("     roll:        %d\n", settings->roll);
	ft_printf("     rotate mode: %d\n\n", settings->rotate_mode);
}

// @brief		switches projection
void	kdot(t_view_settings *settings)
{
	if (settings->projection == 'i')
		settings->projection = 'p';
	else
		settings->projection = 'i';
	logger('l', "Projection is now ");
	if (settings->projection == 'i')
		ft_printf("isometric.\n");
	else
		ft_printf("parallel.\n");
}

// @brief		resets settings
void	kclear(t_view_settings *settings)
{
	mlx_terminate(settings->mlx);
	logger('l', "Shutting down program...");
}
