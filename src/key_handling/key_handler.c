/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:02:37 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/13 19:54:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

static void	handle_held_keys(mlx_key_data_t keydata, t_view_settings *settings)
{
	int		keystatus;

	if (keydata.action == MLX_PRESS)
		keystatus = 1;
	if (keydata.action == MLX_RELEASE)
		keystatus = 0;
	if (keydata.key == 80)
		settings->keys->p = keystatus;
	if (keydata.key == 89)
		settings->keys->y = keystatus;
	if (keydata.key == 82)
		settings->keys->r = keystatus;
	if (keydata.key == 72)
		settings->keys->h = keystatus;
	if (keydata.key == 265 || keydata.key == 264)
		settings->keys->vert = keystatus;
	if (keydata.key == 263 || keydata.key == 262)
		settings->keys->hori = keystatus;
	if (keydata.key == 340)
		settings->keys->shift = keystatus;
}

static int	toggle(int num)
{
	if (num == 0)
		return (1);
	return (0);
}

static void	handle_multiple_held_keys(t_view_settings *settings)
{
	if (settings->keys->shift == 1 && settings->keys->r == 1)
		settings->rotate_mode_roll = toggle(settings->rotate_mode_roll);
	if (settings->keys->shift == 1 && settings->keys->p == 1)
		settings->rotate_mode_pitch = toggle(settings->rotate_mode_pitch);
	if (settings->keys->shift == 1 && settings->keys->y == 1)
		settings->rotate_mode_yaw = toggle(settings->rotate_mode_yaw);
}

// @brief	hook callback function
void	key_handler(mlx_key_data_t keydata, void *param)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ENTER)
			reset_settings((t_view_settings *)param);
		if (keydata.key == MLX_KEY_S)
			status_log((t_view_settings *)param);
		if (keydata.key == MLX_KEY_ESCAPE)
			closing_hook((t_view_settings *)param);
		if (keydata.key == MLX_KEY_I)
			switch_projection((t_view_settings *)param);
	}
	handle_held_keys(keydata, (t_view_settings *)param);
	handle_multiple_held_keys((t_view_settings *)param);
}
