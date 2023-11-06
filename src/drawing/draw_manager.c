/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:51:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/06 15:24:42 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

mlx_t	*init(void)
{
	mlx_t		*mlx;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(DEFAULT_WIDTH, DEFAULT_HEIGHT, PROGRAM_NAME, true);
	if (!mlx)
		return (exit(EXIT_FAILURE), NULL);
	ft_printf("Instantiated new window (%d|%d).\n", mlx->width, mlx->height);
	return (mlx);
}

int	main(void)
{
	init();
}
