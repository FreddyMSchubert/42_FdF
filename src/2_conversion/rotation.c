/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:21:38 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 17:54:33 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../../fdf.h"

// /* Rotate a vector by a counterclockwise angle in a coordinate plane. 
// 			[ 1    0       0   ]
// 	Rx =	[ 0  cos(a) -sin(a)]        ==> Rotate in the (y,z)-plane
// 			[ 0  sin(a)  cos(a)]

// 			[ cos(a)  0   -sin(a)]
// 	Ry =	[   0     1      0   ]      ==> Rotate in the (x,z)-plane
// 			[ sin(a)  0    cos(a)]

// 			[ cos(a) -sin(a) 0]
// 	Rz =	[ sin(a)  cos(a) 0]         ==> Rotate in the (x,y)-plane
// 			[   0       0    1]
// 	-> https://blogs.sas.com/content/iml/2016/11/07/rotations-3d-data.html
// */

static double	(*rotate_plane(double angle, int i, int j))[3]
{
	double		(*matrix)[3];
	int			k;
	int			l;
	double		angle_in_radians;

	angle_in_radians = angle * (M_PI / 180.0);
	matrix = malloc(3 * sizeof(*matrix));
	if (!matrix)
		return (NULL);
	k = -1;
	while (++k < 3)
	{
		l = -1;
		while (++l < 3)
		{
			matrix[k][l] = 0;
			if (k == l)
				matrix[k][l] = 1;
		}
	}
	matrix[i][i] = cos(angle_in_radians);
	matrix[i][j] = -sin(angle_in_radians);
	matrix[j][i] = sin(angle_in_radians);
	matrix[j][j] = cos(angle_in_radians);
	return (matrix);
}

static double	(*get_rotation_matrix(double angle, char axis))[3]
{
	if (axis == 'X')
		return (rotate_plane(angle, 1, 2));
	if (axis == 'Y')
		return (rotate_plane(angle, 0, 2));
	if (axis == 'Z')
		return (rotate_plane(angle, 0, 1));
	return (NULL);
}

static t_hm_node	*apply_rotation_matrix(t_hm_node *node, double (*matrix)[3])
{
	double		x;
	double		y;
	double		z;

	x = matrix[0][0] * node->x_coord \
		+ matrix[0][1] * node->y_coord \
		+ matrix[0][2] * node->z_coord;
	y = matrix[1][0] * node->x_coord \
		+ matrix[1][1] * node->y_coord \
		+ matrix[1][2] * node->z_coord;
	z = matrix[2][0] * node->x_coord \
		+ matrix[2][1] * node->y_coord \
		+ matrix[2][2] * node->z_coord;
	node->x_coord = x;
	node->y_coord = y;
	node->z_coord = z;
	return (node);
}

void	multiply_two_matrices(double (*result)[3], double (*matrix1)[3], \
								double (*matrix2)[3])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			result[i][j] = 0;
			k = 0;
			while (k < 3)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

void	print_matrix(double matrix[3][3])
{
	printf("\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%f ", matrix[i][j]);
		}
		printf("\n");
	}
}

t_hm_node	*rotate_node(t_hm_node	*node, t_view_settings	*settings)
{
	double	(*x_matrix)[3];
	double	(*y_matrix)[3];
	double	(*z_matrix)[3];
	double	(*comb_matrix)[3];
	double	(*temp_matrix)[3];

	x_matrix = get_rotation_matrix(settings->pitch, 'X');
	y_matrix = get_rotation_matrix(settings->roll, 'Y');
	z_matrix = get_rotation_matrix(settings->yaw, 'Z');
	// print_matrix(x_matrix);
	// print_matrix(y_matrix);
	// print_matrix(z_matrix);
	comb_matrix = malloc(3 * sizeof(*comb_matrix));
	temp_matrix = malloc(3 * sizeof(*temp_matrix));
	multiply_two_matrices(temp_matrix, x_matrix, y_matrix);
	multiply_two_matrices(comb_matrix, temp_matrix, z_matrix);
	// ft_printf("(%d|%d|%d) -> ", node->x_coord, node->y_coord, node->z_coord);
	node = apply_rotation_matrix(node, comb_matrix);
	// ft_printf("(%d|%d|%d)\n", node->x_coord, node->y_coord, node->z_coord);
	free(comb_matrix);
	free(temp_matrix);
	free(x_matrix);
	free(y_matrix);
	free(z_matrix);
	return (node);
}
