/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams-algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:38:42 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/08 09:54:31 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

#include <stdio.h>

// @returns		0 if equal, 1 if nbr1 is smaller, -1 if nbr2 is smaller
static int	smaller_than(int nbr1, int nbr2)
{
	if (nbr1 < nbr2)
		return (1);
	if (nbr1 > nbr2)
		return (-1);
	return (0);
}

// @brief		Returns ltr and rtl lines where x direction is dominant as array
static t_pixel	*draw_line_dom_x(t_pixel a, t_pixel b)
{
	t_pixel		*pixels;
	t_pixel		curr_pos;
	int			error;
	int			i;

	pixels = malloc(sizeof(t_pixel) * abs(b.x_coord - a.x_coord + 1));
	if (!pixels)
		return (NULL);
	curr_pos = a;
	error = abs(b.x_coord - a.x_coord) / 2;
	i = 0;
	while (curr_pos.x_coord != b.x_coord)
	{
		pixels[i++] = curr_pos;
		curr_pos.x_coord += smaller_than(a.x_coord, b.x_coord);
		error = error - abs(b.y_coord - a.y_coord);
		if (error < 0)
		{
			curr_pos.y_coord += smaller_than(a.y_coord, b.y_coord);
			error = error + abs(b.x_coord - a.x_coord);
		}
	}
	pixels[i] = b;
	return (pixels);
}

// @brief		Returns btt and ttb lines where y direction is dominant as array
static t_pixel	*draw_line_dom_y(t_pixel a, t_pixel b)
{
	t_pixel		*pixels;
	t_pixel		curr_pos;
	int			error;
	int			i;

	pixels = malloc(sizeof(t_pixel) * abs(b.y_coord - a.y_coord + 1));
	if (!pixels)
		return (NULL);
	curr_pos = a;
	error = abs(b.y_coord - a.y_coord) / 2;
	i = 0;
	while (curr_pos.y_coord != b.y_coord)
	{
		pixels[i++] = curr_pos;
		curr_pos.y_coord += smaller_than(a.y_coord, b.y_coord);
		error = error - abs(b.x_coord - a.x_coord);
		if (error < 0)
		{
			curr_pos.x_coord += smaller_than(a.x_coord, b.x_coord);
			error = error + abs(b.y_coord - a.y_coord);
		}
	}
	pixels[i] = b;
	return (pixels);
}

t_pixel	*get_colored_pixel_array(t_pixel a, t_pixel b)
{
	t_pixel		*pixels;
	int			*colors;
	int			index;

	index = -1;
	if (abs(b.x_coord - a.x_coord) >= abs(b.y_coord - a.y_coord))
	{
		pixels = draw_line_dom_x(a, b);
		colors = get_gradient(abs(b.x_coord - a.x_coord) + 1, a.color, b.color);
		while (pixels && colors && ++index < abs(b.x_coord - a.x_coord))
			pixels[index].color = colors[index];
	}
	else
	{
		pixels = draw_line_dom_y(a, b);
		colors = get_gradient(abs(b.y_coord - a.y_coord) + 1, a.color, b.color);
		while (pixels && colors && ++index < abs(b.y_coord - a.y_coord))
			pixels[index].color = colors[index];
	}
	return (free(pixels), free(colors), pixels);
}

int	test_bresenham(int testcase, int ax, int ay, int ac, int bx, int by, int bc)
{
	t_pixel		pixel_a;
	t_pixel		pixel_b;
	t_pixel		*pixels;
	int			pixel;
	int			looplen;

	pixel_a.x_coord = ax;
	pixel_a.y_coord = ay;
	pixel_a.color = ac;
	pixel_b.x_coord = bx;
	pixel_b.y_coord = by;
	pixel_b.color = bc;
	pixels = get_colored_pixel_array(pixel_a, pixel_b);
	pixel = 0;

	if (abs(bx - ax) >= abs(by - ay))
		looplen = abs(bx - ax) + 1;
	else
		looplen = abs(by - ay) + 1;

	ft_printf("\n--- NEXT TESTCASE: %d! (looplen is %d)\n", testcase, looplen);
	printf("Point 1: (%+02d|%+02d) - (%03d|%03d|%03d|%03d)\n", ax, ay, get_col(ac, 'r'), get_col(ac, 'g'), get_col(ac, 'b'), get_col(ac, 'a'));
	printf("Point 2: (%+02d|%+02d) - (%03d|%03d|%03d|%03d)\n-\n", bx, by, get_col(bc, 'r'), get_col(bc, 'g'), get_col(bc, 'b'), get_col(bc, 'a'));
	while (pixel < looplen)
	{
		printf("Pixel %02d: (%+02d|%+02d) - color: (%03d, %03d, %03d, %03d)\n", pixel, pixels[pixel].x_coord, pixels[pixel].y_coord, get_col(pixels[pixel].color, 'r'), get_col(pixels[pixel].color, 'g'), get_col(pixels[pixel].color, 'b'), get_col(pixels[pixel].color, 'a'));
		pixel++;
	}
	ft_printf("---\n");
	return (1);
}

int	main(void)
{
	test_bresenham(1, 0, 0, get_rgba(255, 0, 0, 0), 5, 0, get_rgba(0, 255, 0, 0));
	test_bresenham(2, 5, 0, get_rgba(0, 255, 0, 0), 0, 0, get_rgba(255, 0, 0, 0));
	test_bresenham(3, 0, 0, get_rgba(0, 0, 255, 0), 0, 5, get_rgba(255, 255, 0, 0));
	test_bresenham(4, 0, 5, get_rgba(255, 255, 0, 0), 0, 0, get_rgba(0, 0, 255, 0));
	test_bresenham(5, 0, 0, get_rgba(0, 255, 255, 0), 5, 5, get_rgba(255, 0, 255, 0));
	test_bresenham(6, 5, 5, get_rgba(255, 0, 255, 0), 0, 0, get_rgba(0, 255, 255, 0));
	test_bresenham(7, -5, 0, get_rgba(255, 255, 255, 0), -10, 0, get_rgba(0, 0, 0, 0));
	test_bresenham(8, 0, -5, get_rgba(0, 0, 0, 0), 0, -10, get_rgba(255, 255, 255, 0));
	test_bresenham(9, -5, -5, get_rgba(171, 205, 239, 0), 5, 5, get_rgba(18, 52, 86, 0));
	test_bresenham(10, 0, 0, get_rgba(101, 67, 33, 0), 3, 9, get_rgba(254, 220, 186, 0));
	test_bresenham(11, 0, 0, get_rgba(101, 67, 33, 0), 9, 3, get_rgba(254, 220, 186, 0));
	return 0;
}