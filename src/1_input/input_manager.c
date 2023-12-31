/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 06:36:04 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/14 06:21:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This file is used to get and format the input
*/

#include "../../fdf.h"

/*
	@brief				creates a new hm node based on coords and file input
	@param str			string from input for height/color, "20,0xFF0000"; "10"
	@param x			x Coordinate
	@param y			y Coordinate
	@param terminator	serves as sentinel value. should be 0 by default
	@returns			new dynamically allocated hm_node based on input
*/
t_hm_node	*fdf_create_hm_node(char *str, int x, int y)
{
	t_hm_node		*new_node;
	char			**split_str;

	new_node = malloc(sizeof(t_hm_node));
	split_str = ft_split(str, ',');
	if (!new_node || !split_str || !str)
		return (fdf_free_rec((void **)split_str), free(new_node), NULL);
	new_node->x_coord = x * 5;
	new_node->y_coord = y * 5;
	new_node->z_coord = ft_atoi(split_str[0]);
	if (!split_str[1])
		new_node->color_hex = DEFAULT_NODE_COLOR;
	else
		new_node->color_hex = fdf_ft_hex_atoi(split_str[1]);
	fdf_free_rec((void **)split_str);
	return (new_node);
}

/*
	@brief				turns an array of input coords into an array of nodes
	@param **strings	split up inputs e.g. ft_split(get_next_line(fd))
	@param y_counter	current y coordinate
	@returns			new dynamically allocated hm_node row based on input
*/
t_hm_node	**fdf_create_hm_node_line(char **strings, int y_counter)
{
	int				node_line_len;
	int				x_counter;
	t_hm_node		**node_line;

	node_line_len = 0;
	while (strings[node_line_len] && \
			strings[node_line_len][0] != '\0' && \
			strings[node_line_len][0] != '\n')
		node_line_len ++;
	x_counter = 0;
	node_line = malloc(sizeof(t_hm_node *) * (node_line_len + 1));
	while (x_counter < node_line_len && strings[x_counter])
	{
		node_line[x_counter] = \
			fdf_create_hm_node(strings[x_counter], x_counter, y_counter);
		if (node_line[x_counter] == NULL)
			return (fdf_free_rec((void **)node_line), NULL);
		x_counter++;
	}
	node_line[x_counter] = NULL;
	return (node_line);
}

/*
	@brief		turns a 2d array of input coords into a 2d array of nodes
	@returns	new dynamically allocated hm_node 2d array based on input
*/
t_hm_node	***fdf_create_hm_node_twod_arr(char ***strings)
{
	int			node_col_len;
	int			y_counter;
	t_hm_node	***node_twod_arr;

	node_col_len = 0;
	while (strings[node_col_len])
		node_col_len++;
	y_counter = 0;
	node_twod_arr = malloc(sizeof(t_hm_node **) * (node_col_len + 1));
	if (!node_twod_arr)
		return (NULL);
	while (y_counter < node_col_len)
	{
		node_twod_arr[y_counter] = \
			fdf_create_hm_node_line(strings[y_counter], y_counter);
		if (node_twod_arr[y_counter] == NULL)
			return (fdf_free_rec_rec((void ***)node_twod_arr), NULL);
		y_counter++;
		if (y_counter < node_col_len && count_array_length(strings[y_counter]) \
			!= count_array_length(strings[y_counter - 1]) && strings[y_counter])
			return (ft_printf("Invalid input in line %d.\n", y_counter), NULL);
	}
	node_twod_arr[y_counter] = NULL;
	return (node_twod_arr);
}

/*
	@brief		turns filedes content of input coords into a 2d array
	@returns	new dynamically allocated hm_node 2d array based on input
*/
t_hm_node	***fdf_get_heightmap(int fd)
{
	t_hm_node	***heightmap;
	char		***input_twod_arr;
	int			y_counter;

	if (fd < 0)
		return (logger('e', "Invalid file path.\n"), NULL);
	input_twod_arr = malloc(sizeof(char **));
	y_counter = 0;
	input_twod_arr[y_counter] = ft_split(get_next_line(fd), ' ');
	while (input_twod_arr[y_counter] != NULL)
	{
		input_twod_arr = realloc(input_twod_arr, \
				(sizeof(char ***) * (y_counter + 2)));
		y_counter++;
		input_twod_arr[y_counter] = ft_split(get_next_line(fd), ' ');
	}
	input_twod_arr[y_counter] = NULL;		// technically not needed
	logger('l', "Read out data from input file.\n");
	heightmap = fdf_create_hm_node_twod_arr(input_twod_arr);
	fdf_free_rec_rec((void ***)input_twod_arr);
	return (heightmap);
}
