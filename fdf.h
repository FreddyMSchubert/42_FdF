/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:18:51 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/10 12:41:22 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "src/imports/get_next_line/get_next_line.h"
# include "src/imports/ft_printf/ft_printf.h"
# include "src/imports/libft/libft.h"

# include "lib/MLX42/include/MLX42/MLX42.h"

# define DEFAULT_NODE_COLOR 0xFF00FF
# define DEFAULT_WIDTH 256
# define DEFAULT_HEIGHT 256
# define COORD_SPREAD 10
# define PROGRAM_NAME "FDF"

typedef struct t_hm_node
{
	int		x_coord;
	int		y_coord;
	int		z_coord;
	int		color_hex;
	int		terminator;
}				t_hm_node;
typedef struct t_pixel
{
	int		x_coord;
	int		y_coord;
	int		color;
	int		terminator;
}			t_pixel;

// Input functions

t_hm_node	*fdf_create_hm_node(char *str, int x, int y, int terminator);
t_hm_node	**fdf_create_hm_node_line(char **strings, int y_counter, \
										int terminator);
t_hm_node	***fdf_create_hm_node_twod_arr(char ***strings);
t_hm_node	***fdf_get_heightmap(int fd);

void		fdf_free_rec(void **blob);
void		fdf_free_rec_rec(void ***blob);
int			fdf_ft_hex_atoi(const char *s);

// Drawing functions

int			*get_grad(int l, int c1, int c2);
int			draw_line(mlx_image_t *img, t_pixel *a, t_pixel *b);

int			get_rgba(int r, int g, int b, int a);
int			get_col_rgba(int rgba, char col);
int			get_col_rgb(int rgb, char col);
int			hex_to_rgba(int hex, int alpha);

// Conversion functions

t_pixel		***convert_hm_node_grid_to_pixel_grid(t_hm_node ***nodes);

// Main loop / window management

void		logger(char type, char *message);
int			get_pixelmap_width(t_pixel	***pixelmap);
int			get_pixelmap_height(t_pixel	***pixelmap);

mlx_t		*fdf_init(t_pixel	***pixelmap);

#endif