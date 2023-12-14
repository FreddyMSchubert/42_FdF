/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:02:54 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/14 06:44:20 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// @brief		zooms
void	zoom(t_view_settings *settings, double amount)
{
	int			prevzoom;

	prevzoom = settings->zoom;
	settings->zoom += amount / 3;
	if (settings->zoom <= 0)
		settings->zoom = 1;
	refresh_screen(settings);
	if (settings->zoom != prevzoom)
	{
		logger('l', "Zoomed. ");
	}
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
	logger('l', "Changed x offset ");
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
	logger('l', "Changed y offset ");
}

// @brief		changes depth
void	edit_depth(t_view_settings *settings, double amount)
{
	int			increment;

	increment = amount / 10;
	if (increment == 0 && amount != 0)
	{
		if (amount < 0)
			increment = -1;
		if (amount > 0)
			increment = 1;
	}
	settings->depth_mod += increment;
	refresh_screen(settings);
	logger('l', "Changed terrain depth ");
}
