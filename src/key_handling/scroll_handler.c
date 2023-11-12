/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scroll_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 07:59:20 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 19:01:14 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	scroll_handler(double xdelta, double ydelta, void *param)
{
	t_view_settings		*settings;

	(void)xdelta;
	settings = (t_view_settings *)param;
	if (settings->keys->p == 1)
		pitch(settings, ydelta);
	else if (settings->keys->y == 1)
		yaw(settings, ydelta);
	else if (settings->keys->r == 1)
		roll(settings, ydelta);
	else if (settings->keys->vert == 1)
		edit_y_offset(settings, ydelta);
	else if (settings->keys->hori == 1)
		edit_x_offset(settings, ydelta);
	else if (settings->keys->h == 1)
		edit_depth(settings, ydelta);
	else
		zoom(settings, ydelta);
}
