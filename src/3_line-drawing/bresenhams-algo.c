/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams-algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:38:42 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/14 05:40:05 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

#include <stdio.h>

// @brief		Returns ltr and rtl lines where x direction is dominant as array
static void	draw_line_dom_x(t_pixel *a, t_pixel *b, mlx_image_t *img)
{
	t_pixel		pos;
	int			error;
	int			curr_color;

	pos = *a;
	error = abs(b->x_coord - a->x_coord) / 2;
	while (pos.x_coord != b->x_coord)
	{
		curr_color = get_grad_at_step(abs(b->x_coord - a->x_coord), \
									a->color, b->color, \
									pos.x_coord - a->x_coord);
		if (pos.x_coord >= 0 && pos.y_coord >= 0 && \
				pos.x_coord < DEFAULT_WIDTH && pos.y_coord < DEFAULT_HEIGHT)
			mlx_put_pixel(img, pos.x_coord, pos.y_coord, curr_color);
		pos.x_coord += smaller_than(a->x_coord, b->x_coord);
		error = error - abs(b->y_coord - a->y_coord);
		if (error < 0)
		{
			pos.y_coord += smaller_than(a->y_coord, b->y_coord);
			error = error + abs(b->x_coord - a->x_coord);
		}
	}
	if (b->x_coord >= 0 && b->y_coord >= 0 && \
		b->x_coord < DEFAULT_WIDTH && b->y_coord < DEFAULT_HEIGHT)
		mlx_put_pixel(img, b->x_coord, b->y_coord, b->color);
}

// @brief		Returns btt and ttb lines where y direction is dominant as array
static void	draw_line_dom_y(t_pixel *a, t_pixel *b, mlx_image_t *img)
{
	t_pixel		pos;
	int			error;
	int			curr_color;

	pos = *a;
	error = abs(b->y_coord - a->y_coord) / 2;
	while (pos.y_coord != b->y_coord)
	{
		curr_color = get_grad_at_step(abs(b->y_coord - a->y_coord), \
									a->color, b->color, \
									pos.y_coord - a->y_coord);
		if (pos.x_coord >= 0 && pos.y_coord >= 0 && \
				pos.x_coord < DEFAULT_WIDTH && pos.y_coord < DEFAULT_HEIGHT)
			mlx_put_pixel(img, pos.x_coord, pos.y_coord, curr_color);
		pos.y_coord += smaller_than(a->y_coord, b->y_coord);
		error = error - abs(b->x_coord - a->x_coord);
		if (error < 0)
		{
			pos.x_coord += smaller_than(a->x_coord, b->x_coord);
			error = error + abs(b->y_coord - a->y_coord);
		}
	}
	if (b->x_coord >= 0 && b->y_coord >= 0 && \
		b->x_coord < DEFAULT_WIDTH && b->y_coord < DEFAULT_HEIGHT)
		mlx_put_pixel(img, b->x_coord, b->y_coord, b->color);
}

/*
	@brief		Draws a line between two pixels on screen img
*/
void	draw_line(mlx_image_t *img, t_pixel *a, t_pixel *b)
{
	if (abs(b->x_coord - a->x_coord) >= abs(b->y_coord - a->y_coord))
		draw_line_dom_x(a, b, img);
	else
		draw_line_dom_y(a, b, img);
}
