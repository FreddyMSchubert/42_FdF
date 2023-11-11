/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:49:43 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 17:59:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

#define ROTATION_STEP 100

// @brief		changes pitch
static void	pitch(mlx_key_data_t keydata, t_view_settings *settings)
{
	if (keydata.key == 321)
		settings->pitch -= ROTATION_STEP;
	if (keydata.key == 322)
		settings->pitch += ROTATION_STEP;
	if (keydata.key == 323)
		settings->pitch = 0;
	refresh_screen(settings);
	logger('l', "Changed pitch.\n");
}

// @brief		changes yaw
static void	yaw(mlx_key_data_t keydata, t_view_settings *settings)
{
	if (keydata.key == 324)
		settings->yaw -= ROTATION_STEP;
	if (keydata.key == 325)
		settings->yaw += ROTATION_STEP;
	if (keydata.key == 326)
		settings->yaw = 0;
	refresh_screen(settings);
	logger('l', "Changed yaw.\n");
}

// @brief		changes roll
static void	roll(mlx_key_data_t keydata, t_view_settings *settings)
{
	if (keydata.key == 327)
		settings->roll -= ROTATION_STEP;
	if (keydata.key == 328)
		settings->roll += ROTATION_STEP;
	if (keydata.key == 329)
		settings->roll = 0;
	refresh_screen(settings);
	logger('l', "Changed roll.\n");
}

void	change_rotation(mlx_key_data_t keydata, t_view_settings *settings)
{
	if (keydata.key >= 321 && keydata.key <= 323)
		pitch(keydata, settings);
	if (keydata.key >= 324 && keydata.key <= 326)
		yaw(keydata, settings);
	if (keydata.key >= 327 && keydata.key <= 329)
		roll(keydata, settings);
}
