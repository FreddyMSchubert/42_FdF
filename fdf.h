/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:18:51 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/06 08:40:44 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "src/imports/get_next_line/get_next_line.h"
# include "src/imports/ft_printf/ft_printf.h"
# include "src/imports/libft/libft.h"

# include "lib/MLX42/include/MLX42/MLX42.h"

# define DEFAULT_NODE_COLOR 0xFFFFFF
# define DEFAULT_WIDTH 256
# define DEFAULT_HEIGHT 256
# define PROGRAM_NAME "FDF"

typedef struct t_hm_node
{
	int		x_coord;
	int		y_coord;
	int		z_coord;
	int		color_hex;
}				t_hm_node;

// Util functions

void		free_rec(void **blob);
void		free_rec_rec(void ***blob);
int			ft_hex_atoi(const char *s);

// Input functions

t_hm_node	*create_hm_node(char *str, int x, int y);
t_hm_node	**create_hm_node_line(char **strings, int y_counter);
t_hm_node	***create_hm_node_twod_arr(char ***strings);

#endif