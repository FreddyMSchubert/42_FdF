/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 07:23:35 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/14 07:25:27 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../fdf.h"

void apply_rotation(int *x, int *y, int *z, double yaw, double pitch, double roll)
{
	double cosYaw = cos(yaw * M_PI / 180.0);
	double sinYaw = sin(yaw * M_PI / 180.0);
	double cosPitch = cos(pitch * M_PI / 180.0);
	double sinPitch = sin(pitch * M_PI / 180.0);
	double cosRoll = cos(roll * M_PI / 180.0);
	double sinRoll = sin(roll * M_PI / 180.0);

	double a, b, c;
	a = cosYaw * cosPitch * *x + (cosYaw * sinPitch * sinRoll - sinYaw * cosRoll) * *y + (cosYaw * sinPitch * cosRoll + sinYaw * sinRoll) * *z;
	b = sinYaw * cosPitch * *x + (sinYaw * sinPitch * sinRoll + cosYaw * cosRoll) * *y + (sinYaw * sinPitch * cosRoll - cosYaw * sinRoll) * *z;
	c = -sinPitch * *x + cosPitch * sinRoll * *y + cosPitch * cosRoll * *z;

	*x = (int)a;
	*y = (int)b;
	*z = (int)c;
}

void	update_rotate_mode(t_view_settings *settings)
{
	int	rotate_speed;

	rotate_speed = 1;
	if (settings->rotate_mode_pitch == 1)
		settings->pitch += rotate_speed;
	if (settings->rotate_mode_yaw == 1)
		settings->yaw += rotate_speed;
	if (settings->rotate_mode_roll == 1)
		settings->roll += rotate_speed;
}
