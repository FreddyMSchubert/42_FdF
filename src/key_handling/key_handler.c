/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 09:02:37 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 17:35:41 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// @brief	hook callback function
void	key_handler(mlx_key_data_t keydata, void *param)
{
	// ft_printf("Key pressed: %d\n", keydata.key);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == 335)
			kenter((t_view_settings *)param);
		if (keydata.key == 320)
			k0((t_view_settings *)param);
		if (keydata.key == 282 || keydata.key == 256)
			kclear((t_view_settings *)param);
		if (keydata.key == 330)
			kdot((t_view_settings *)param);
		if (keydata.key == 334)
			kplus((t_view_settings *)param);
		if (keydata.key == 333)
			kminus((t_view_settings *)param);
		if (keydata.key >= 262 && keydata.key <= 265)
			arrowkeys(keydata, (t_view_settings *)param);
		if (keydata.key >= 321 && keydata.key <= 329)
			change_rotation(keydata, (t_view_settings *)param);
	}
}
