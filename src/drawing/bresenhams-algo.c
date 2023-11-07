/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams-algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:38:42 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/07 14:20:35 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

// 5 functions
// 1 to feed data into the other functions
// 4 other: ttb, btt, ltr, rtl
// for

void	draw_line(mlx_t mlx, t_pixel a, t_pixel b)
{
	int			error;
	t_pixel		*pixels;
	t_pixel		curr_pixel;

	curr_pixel = a;
	if ((b.x_coord - a.x_coord) > (b.y_coord - a.y_coord))
	{
		error = (b.x_coord - a.x_coord) / 2;
		pixels = malloc(sizeof(t_pixel) * (b.x_coord - a.x_coord));
		while (curr_pixel.x_coord < b.x_coord)
		{
			pixels[curr_pixel.x_coord - a.x_coord] = curr_pixel;
			error -= (b.y_coord - a.y_coord);
			if (error >= 0)
				continue ;
			curr_pixel.y_coord++;
			error = error + (b.x_coord - a.x_coord);
		}
	}
	else
	{
		error = (b.y_coord - a.y_coord) / 2;
		pixels = malloc(sizeof(t_pixel) * (b.y_coord - a.y_coord));
	}
}

// shouldnt do it like this. should split by 1. is y axis or x axis the fast axis; 2. is a in bottom left or b in bottom left?
void	draw_line(mlx_t mlx, t_pixel a, t_pixel b)
{
	t_pixel		*pixels;

	if (b.x_coord >= a.x_coord)
	{
		if (b.y_coord >= a.y_coord)
			pixels = draw_line_ltr(mlx, a, b);
		else
			pixels = draw_line_ttb(mlx, a, b);
	}
	else
	{
		if (b.y_coord >= a.y_coord)
			pixels = draw_line_rtl(mlx, a, b);
		else
			pixels = draw_line_btt(mlx, a, b);
	}

	return (pixels);
}
