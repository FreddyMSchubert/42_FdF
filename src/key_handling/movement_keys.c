/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:02:54 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 08:42:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// @brief		zooms
void	zoom(t_view_settings *settings, double amount)
{
	settings->zoom += amount / 3;
	if (settings->zoom <= 0)
		settings->zoom = 1;
	refresh_screen(settings);
	logger('i', "Zoomed. ");
	ft_printf("Zoom is now %d.\n", settings->zoom);
}

// @brief		changes x offset
void	edit_x_offset(t_view_settings *settings, double amount)
{
	settings->x_offset += amount;
	if (settings->x_offset < 0)
		settings->x_offset = 0;
	if (settings->x_offset > settings->mlx->width)
		settings->x_offset = settings->mlx->width - 1;
	refresh_screen(settings);
	logger('i', "Changed x offset, ");
	ft_printf("it's now %d.\n", settings->x_offset);
}

// @brief		changes y offset
void	edit_y_offset(t_view_settings *settings, double amount)
{
	settings->y_offset += amount;
	if (settings->y_offset < 0)
		settings->y_offset = 0;
	if (settings->y_offset > settings->mlx->height)
		settings->y_offset = settings->mlx->height - 1;
	refresh_screen(settings);
	logger('i', "Changed y offset, ");
	ft_printf("it's now %d.\n", settings->y_offset);
}

// @brief		changes depth
void	edit_depth(t_view_settings *settings, double amount)
{
	settings->depth_mod += amount / 10;
	refresh_screen(settings);
	logger('i', "Changed depth, ");
	ft_printf("it's now %d.\n", settings->depth_mod);
}
