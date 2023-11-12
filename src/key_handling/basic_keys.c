/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 10:10:39 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 19:14:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// @brief		resets settings
void	reset_settings(t_view_settings *settings)
{
	t_view_settings		*defaults;

	defaults = initialize_settings(settings->mlx, settings->img, \
									settings->heightmap, settings->keys);
	settings->projection = defaults->projection;
	settings->zoom = defaults->zoom;
	settings->x_offset = defaults->x_offset;
	settings->y_offset = defaults->y_offset;
	settings->yaw = defaults->yaw;
	settings->pitch = defaults->pitch;
	settings->roll = defaults->roll;
	settings->depth_mod = defaults->depth_mod;
	settings->rotate_mode_pitch = defaults->rotate_mode_pitch;
	settings->rotate_mode_roll = defaults->rotate_mode_roll;
	settings->rotate_mode_yaw = defaults->rotate_mode_yaw;
	logger('l', "Default settings restored.\n");
}

// @brief		displays debug log
void	status_log(t_view_settings *settings)
{
	ft_printf("\n   DEBUG LOG!\n");
	ft_printf("     width:             %d\n", settings->mlx->width);
	ft_printf("     height:            %d\n", settings->mlx->height);
	ft_printf("     projection:        %c\n", settings->projection);
	ft_printf("     zoom:              %d\n", settings->zoom);
	ft_printf("     x offset:          %d\n", settings->x_offset);
	ft_printf("     y offset:          %d\n", settings->y_offset);
	ft_printf("     yaw:               %d\n", settings->yaw);
	ft_printf("     pitch:             %d\n", settings->pitch);
	ft_printf("     roll:              %d\n", settings->roll);
	ft_printf("     depth:             %d\n", settings->depth_mod);
	ft_printf("     frame:             %d\n", settings->frame);
	ft_printf("     rotate mode yaw:   %d\n", settings->rotate_mode_yaw);
	ft_printf("     rotate mode roll:  %d\n", settings->rotate_mode_roll);
	ft_printf("     rotate mode pitch: %d\n", settings->rotate_mode_yaw);
	ft_printf("     shift key:         %d\n", settings->keys->shift);
}

// @brief		toggles projection
void	switch_projection(t_view_settings *settings)
{
	if (settings->projection == 'i')
		settings->projection = 'c';
	else
		settings->projection = 'i';
	logger('l', "Changed projection to ");
	if (settings->projection == 'i')
		ft_printf("isometric.\n");
	else
		ft_printf("cabinet.\n");
}
