/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:18:51 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/09 08:16:03 by fschuber         ###   ########.fr       */
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
typedef struct t_pixel
{
	int		x_coord;
	int		y_coord;
	int		color;
}			t_pixel;

// Input functions

t_hm_node	*fdf_create_hm_node(char *str, int x, int y);
t_hm_node	**fdf_create_hm_node_line(char **strings, int y_counter);
t_hm_node	***fdf_create_hm_node_twod_arr(char ***strings);
t_hm_node	***fdf_get_heightmap(int fd);

void		fdf_free_rec(void **blob);
void		fdf_free_rec_rec(void ***blob);
int			fdf_ft_hex_atoi(const char *s);

// Drawing functions

mlx_t		*fdf_init(void);
int			*get_gradient(int l, int c1, int c2);
int			draw_pixel(mlx_t mlx, t_pixel pxl);

void		fdf_mlx_error(void);
int			get_rgba(int r, int g, int b, int a);
int			get_col(int rgba, char col);

#endif