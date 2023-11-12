/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:49:43 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 08:23:38 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

#define ROTATION_STEP 1

// @brief		changes pitch
void	pitch(t_view_settings *settings, double amount)
{
	settings->pitch += amount;
	settings->pitch %= 360;
	refresh_screen(settings);
	logger('i', "Changed pitch");
	ft_printf(" to %d°.\n", settings->pitch);
}

// @brief		changes yaw
void	yaw(t_view_settings *settings, double amount)
{
	settings->yaw += amount;
	settings->yaw %= 360;
	refresh_screen(settings);
	logger('i', "Changed yaw");
	ft_printf(" to %d°.\n", settings->yaw);
}

// @brief		changes roll
void	roll(t_view_settings *settings, double amount)
{
	settings->roll += amount;
	settings->roll %= 360;
	refresh_screen(settings);
	logger('i', "Changed roll");
	ft_printf(" to %d°.\n", settings->roll);
}
