/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:18:51 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/11 11:33:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "src/imports/get_next_line/get_next_line.h"
# include "src/imports/ft_printf/ft_printf.h"
# include "src/imports/libft/libft.h"

# include "lib/MLX42/include/MLX42/MLX42.h"

# define DEFAULT_NODE_COLOR 0xFF00FF
# define DEFAULT_WIDTH 5120
# define DEFAULT_HEIGHT 2880
# define COORD_SPREAD 10
# define PROGRAM_NAME "FDF"

typedef struct s_hm_node
{
	int		x_coord;
	int		y_coord;
	int		z_coord;
	int		color_hex;
}				t_hm_node;
typedef struct s_pixel
{
	int		x_coord;
	int		y_coord;
	int		color;
}			t_pixel;

typedef struct s_view_settings
{
	char			projection;
	int				zoom;
	int				x_offset;
	int				y_offset;
	int				yaw;
	int				pitch;
	int				roll;
	int				rotate_mode;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_hm_node		***heightmap;
}				t_view_settings;

// Input functions

t_hm_node		*fdf_create_hm_node(char *str, int x, int y);
t_hm_node		**fdf_create_hm_node_line(char **strings, int y_counter);
t_hm_node		***fdf_create_hm_node_twod_arr(char ***strings);
t_hm_node		***fdf_get_heightmap(int fd);

void			fdf_free_rec(void **blob);
void			fdf_free_rec_rec(void ***blob);
int				fdf_ft_hex_atoi(const char *s);

// Drawing functions

int				*get_grad(int l, int c1, int c2);
int				draw_line(mlx_image_t *img, t_pixel *a, t_pixel *b);
int				smaller_than(int nbr1, int nbr2);

int				get_rgba(int r, int g, int b, int a);
int				get_col_rgba(int rgba, char col);
int				get_col_rgb(int rgb, char col);
int				hex_to_rgba(int hex, int alpha);

// Conversion functions

t_pixel			***convert_hm_node_grid_to_pixel_grid(t_hm_node ***nodes, \
					t_view_settings *settings);

// Main loop / window management

void			logger(char type, char *message);
void			fdf_mlx_error(void);
t_view_settings	*initialize_settings(mlx_t	*mlx, mlx_image_t	*img, \
									t_hm_node	***heightmap);
void			refresh_screen(t_view_settings *settings);

mlx_t			*fdf_init(t_hm_node	***heightmap);
void			fdf_draw_lines(mlx_image_t	*img, t_pixel	***pixelmap, \
								t_view_settings *settings);

// Key Input

void			key_handler(mlx_key_data_t keydata, void *settings);

void			kenter(t_view_settings *settings);
void			k0(t_view_settings *settings);
void			kdot(t_view_settings *settings);
void			kclear(t_view_settings *settings);

void			kplus(t_view_settings *settings);
void			kminus(t_view_settings *settings);
void			arrowkeys(mlx_key_data_t keydata, t_view_settings *settings);

#endif