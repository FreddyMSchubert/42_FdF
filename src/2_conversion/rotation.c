/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 15:21:38 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/12 20:46:23 by fschuber         ###   ########.fr       */
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

static t_matrix3x3	rotate_plane(double angle, int i, int j)
{
	t_matrix3x3	matrix;
	int			k;
	int			l;
	double		angle_in_radians;

	angle_in_radians = angle * (M_PI / 180.0);
	k = -1;
	while (++k < 3)
	{
		l = -1;
		while (++l < 3)
		{
			matrix.m[k][l] = 0;
			if (k == l)
				matrix.m[k][l] = 1;
		}
	}
	matrix.m[i][i] = cos(angle_in_radians);
	matrix.m[i][j] = -sin(angle_in_radians);
	matrix.m[j][i] = sin(angle_in_radians);
	matrix.m[j][j] = cos(angle_in_radians);
	return (matrix);
}

t_matrix3x3	get_rotation_matrix(double angle, char axis)
{
	if (axis == 'X')
		return (rotate_plane(angle, 1, 2));
	if (axis == 'Y')
		return (rotate_plane(angle, 0, 2));
	if (axis == 'Z')
		return (rotate_plane(angle, 0, 1));
	logger('e', "Invalid axis inputted to get rotation matrix.\n");
	return (rotate_plane(angle, 0, 1));
}

void	apply_rotation_matrix(int *x, int *y, int *z, t_matrix3x3 matrix)
{
	double		a;
	double		b;
	double		c;

	a = matrix.m[0][0] * *x \
		+ matrix.m[0][1] * *y \
		+ matrix.m[0][2] * *z;
	b = matrix.m[1][0] * *x \
		+ matrix.m[1][1] * *y \
		+ matrix.m[1][2] * *z;
	c = matrix.m[2][0] * *x \
		+ matrix.m[2][1] * *y \
		+ matrix.m[2][2] * *z;
	*x = (int)a;
	*y = (int)b;
	*z = (int)c;
}

t_matrix3x3	multiply_two_matrices(t_matrix3x3 matrix1, t_matrix3x3 matrix2)
{
	t_matrix3x3	result;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			result.m[i][j] = 0;
			k = 0;
			while (k < 3)
			{
				result.m[i][j] += matrix1.m[i][k] * matrix2.m[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void	rotate_node(int *x, int *y, int *z, t_view_settings	*settings)
{
	t_matrix3x3		comb_matrix;
	t_matrix3x3		temp_matrix;
	t_matrix3x3		relative_to_world_matrix;

	temp_matrix = multiply_two_matrices(\
				get_rotation_matrix(settings->pitch, 'X'), \
				get_rotation_matrix(settings->roll, 'Y'));
	comb_matrix = multiply_two_matrices(temp_matrix, \
				get_rotation_matrix(settings->yaw, 'Z'));
	apply_rotation_matrix(x, y, z, comb_matrix);
	relative_to_world_matrix = multiply_two_matrices(\
			get_rotation_matrix(settings->keys->mouse_rotation_x, 'Y'), \
			get_rotation_matrix(settings->keys->mouse_rotation_y, 'X'));
	apply_rotation_matrix(x, y, z, relative_to_world_matrix);
}
