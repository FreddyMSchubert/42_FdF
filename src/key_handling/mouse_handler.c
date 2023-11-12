/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:20:16 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 20:29:48 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// @brief		Gets called every frame where lmb is held.
// @brief		Saves mouse movement data for conversion.c to handle
void	mouse_handler(t_view_settings *settings, int is_first_frame_of_click)
{
	int32_t		new_mouse_x;
	int32_t		new_mouse_y;

	ft_printf("%d", is_first_frame_of_click);
	settings->keys->mouse = 1;
	mlx_get_mouse_pos(settings->mlx, &new_mouse_x, &new_mouse_y);
	if (is_first_frame_of_click == 1)
	{
		settings->keys->mouse_x = new_mouse_x;
		settings->keys->mouse_y = new_mouse_y;
	}
	settings->keys->mouse_rotation_x += new_mouse_x - settings->keys->mouse_x;
	settings->keys->mouse_rotation_y += new_mouse_y - settings->keys->mouse_y;
	refresh_screen(settings);
	settings->keys->mouse_x = new_mouse_x;
	settings->keys->mouse_y = new_mouse_y;
}
