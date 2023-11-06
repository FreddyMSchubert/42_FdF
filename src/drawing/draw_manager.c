/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:51:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/06 08:42:19 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

mlx_t	*init()
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(DEFAULT_WIDTH, DEFAULT_HEIGHT, PROGRAM_NAME, true);
	if (!mlx)
		return(exit(EXIT_FAILURE), NULL);
	return (mlx);
}

int		main(void)
{
	init();
}
