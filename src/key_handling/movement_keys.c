/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:02:54 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 17:48:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// @brief		zooms in
void	kplus(t_view_settings *settings)
{
	settings->zoom += settings->zoom / 5;
	refresh_screen(settings);
	logger('l', "Zoomed in.\n");
}

// @brief		zooms out
void	kminus(t_view_settings *settings)
{
	settings->zoom -= settings->zoom / 5;
	if (settings->zoom <= 0)
		settings->zoom = 1;
	refresh_screen(settings);
	logger('l', "Zoomed out.\n");
}

void	arrowkeys(mlx_key_data_t keydata, t_view_settings *settings)
{
	int	step;

	step = 1;
	if (keydata.key == 265)
		settings->y_offset -= step;
	if (keydata.key == 262)
		settings->x_offset += step;
	if (keydata.key == 264)
		settings->y_offset += step;
	if (keydata.key == 263)
		settings->x_offset -= step;
	if (settings->x_offset < 0)
		settings->x_offset = 0;
	if (settings->x_offset > settings->mlx->width)
		settings->x_offset = settings->mlx->width - 1;
	if (settings->y_offset < 0)
		settings->y_offset = 0;
	if (settings->y_offset > settings->mlx->height)
		settings->y_offset = settings->mlx->height - 1;
	refresh_screen(settings);
	logger('l', "Moved position.\n");
}
