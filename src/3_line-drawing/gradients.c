/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 08:51:23 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/10 07:36:40 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
#include <math.h>

// @brief		gets step size for a gradient of length l
//				between c1 and c2 on color channel col
static double	get_gradient_step(int l, int c1, int c2, char col)
{
	double		step;

	if (l < 2)
		return (c1);
	step = (double)(get_col_rgba(c2, col) - get_col_rgba(c1, col)) / (l - 1);
	return (step);
}

/*
	@returns		Dynamically allocated array of length l containing a
					color feed between including the colors c1 and c2
*/
int	*get_gradient(int l, int c1, int c2)
{
	int		i;
	int		*colors;

	i = 0;
	colors = malloc(sizeof(int) * l);
	if (!colors)
		return (NULL);
	while (i < l)
	{
		colors[i] = get_rgba(\
			get_col_rgba(c1, 'r') + i * get_gradient_step(l, c1, c2, 'r'), \
			get_col_rgba(c1, 'g') + i * get_gradient_step(l, c1, c2, 'g'), \
			get_col_rgba(c1, 'b') + i * get_gradient_step(l, c1, c2, 'b'), \
			get_col_rgba(c1, 'a') + i * get_gradient_step(l, c1, c2, 'a'));
		i++;
	}
	return (colors);
}
