/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:18:51 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/02 09:35:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

# define DEFAULT_NODE_COLOR 0xFFFFFF

typedef struct t_hm_node
{
	int		x_coord;
	int		y_coord;
	int		z_coord;
	int		color_hex;
}				t_hm_node;

// Util functions

void		free_rec(void **blob);
int			ft_hex_atoi(const char *s);

// Input functions

t_hm_node	*create_hm_node(char *str, int x, int y);
t_hm_node	**create_hm_node_line(char **strings, int y_counter);
t_hm_node	***create_hm_node_twod_arr(char ***strings);

#endif