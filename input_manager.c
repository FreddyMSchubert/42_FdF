/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 06:36:04 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/02 10:00:08 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	This file is used to get and format the input
*/

#include "fdf.h"

/*
	@brief			creates a new hm node based on coords and file input
	@param str		string from input for height/color, e.g. "20,0xFF0000"; "10"
	@param x		x Coordinate
	@param y		y Coordinate
	@returns		new dynamically allocated hm_node based on input
*/
t_hm_node	*create_hm_node(char *str, int x, int y)
{
	t_hm_node		*new_node;
	char			**split_str;

	new_node = malloc(sizeof(t_hm_node));
	split_str = ft_split(str, ',');
	if (!new_node || !split_str)
		return (free_rec(split_str), free(new_node), NULL);
	new_node->x_coord = x;
	new_node->y_coord = y;
	if (!split_str[1])
	{
		new_node->z_coord = ft_atoi(split_str[0]);
		new_node->color_hex = DEFAULT_NODE_COLOR;
	}
	else
	{
		new_node->z_coord = ft_atoi(split_str[0]);
		new_node->color_hex = ft_hex_atoi(split_str[1]);
	}
	free_rec(split_str);
	return (new_node);
}

/*
	@brief				turns an array of input coords into an array of nodes
	@param **strings	split up inputs e.g. ft_split(get_next_line(fd))
	@param y_counter	current y coordinate
	@returns			new dynamically allocated hm_node row based on input
*/
t_hm_node	**create_hm_node_line(char **strings, int y_counter)
{
	int				node_line_len;
	int				x_counter;
	t_hm_node		**node_line;

	node_line_len = 0;
	while (strings[node_line_len])
		node_line_len ++;
	x_counter = 0;
	node_line = malloc((sizeof(t_hm_node *) * node_line_len) + 1);
	if (!node_line)
		return (NULL);
	node_line[node_line_len] = NULL;
	while (x_counter < node_line_len)
	{
		node_line[x_counter] = \
			create_hm_node(strings[x_counter], x_counter, y_counter);
		if (node_line[x_counter] == NULL)
			return (free_rec(node_line), NULL);
		x_counter++;
	}
	return (node_line);
}

/*
	@brief		turns a 2d array of input coords into a 2d array of nodes
	@returns	new dynamically allocated hm_node 2d array based on input
*/
t_hm_node	***create_hm_node_twod_arr(char ***strings)
{
	int			node_col_len;
	int			y_counter;
	t_hm_node	***node_twod_arr;

	node_col_len = 0;
	while (strings[node_col_len])
		node_col_len++;
	y_counter = 0;
	node_twod_arr = malloc(sizeof(t_hm_node **) * (node_col_len) + 1);
	if (!node_twod_arr)
		return (NULL);
	node_twod_arr[node_col_len] = NULL;
	while (y_counter < node_col_len)
	{
		node_twod_arr[y_counter] = \
			create_hm_node_line(strings[y_counter], y_counter);
		if (node_twod_arr[y_counter] == NULL)
			return (free_rec(node_twod_arr), NULL);
		y_counter++;
	}
	return (node_twod_arr);
}

t_hm_node	***get_heightmap(int fd)
{
	t_hm_node	***heightmap;
	t_hm_node	***input_twod_arr;
	t_hm_node	***temp;
	int			y_counter;

	input_twod_arr = malloc(sizeof(t_hm_node **) + 1);
	y_counter = 0;
	input_twod_arr[y_counter] = ft_split(get_next_line(fd), ' ');
	while (input_twod_arr[y_counter] != NULL)
	{
		temp = realloc(input_twod_arr, (sizeof(t_hm_node **) * (y_counter + 1)) + 1);
		if (temp == NULL)
			return (free_rec_rec(input_twod_arr), NULL);
		input_twod_arr = temp;
		y_counter++;
		input_twod_arr[y_counter] = ft_split(get_next_line(fd), ' ');
	}
	input_twod_arr[y_counter] = NULL;
	heightmap = create_hm_node_twod_arr(input_twod_arr);
	free_rec_rec(input_twod_arr);
	return (heightmap);
}
