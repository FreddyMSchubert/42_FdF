/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhams-algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:38:42 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/09 08:17:25 by fschuber         ###   ########.fr       */
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

	pixels = malloc(sizeof(t_pixel) * (abs(b.x_coord - a.x_coord) + 1));
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

	pixels = malloc(sizeof(t_pixel) * (abs(b.y_coord - a.y_coord) + 1));
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

/*
	@brief		Takes in two coordinates and interpolates their positions and color. 
	@returns	Dynamically allocated array with all pixels 
				between including a and b.
	@brief		Not designed to handle anything over including INT MAX or under 0
*/
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
	if (!pixels || !colors)
		return (free(pixels), free(colors), NULL);
	free (colors);
	return (pixels);
}
