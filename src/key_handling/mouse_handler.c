/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:20:16 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 10:29:31 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	mouse_handler(t_view_settings *settings)
{
	int32_t		new_mouse_x;
	int32_t		new_mouse_y;

	mlx_get_mouse_pos(settings->mlx, &new_mouse_x, &new_mouse_y);
	if (settings->keys->mouse_x != -1 || settings->keys->mouse_y != -1)
	{
		yaw(settings, new_mouse_x - settings->keys->mouse_x);
		pitch(settings, new_mouse_y - settings->keys->mouse_y);
	}
	settings->keys->mouse_x = new_mouse_x;
	settings->keys->mouse_y = new_mouse_y;
}
