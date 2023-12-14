/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:18:51 by fschuber          #+#    #+#             */
/*   Updated: 2023/12/14 06:39:10 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// if this is 1, the program will log a bunch of stuff
# define VERBOSE 0

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
	double	x_coord;
	double	y_coord;
	double	z_coord;
	int		color_hex;
}				t_hm_node;
typedef struct s_pixel
{
	int		x_coord;
	int		y_coord;
	int		color;
}			t_pixel;

typedef struct s_matrix3x3
{
	double		m[3][3];
}				t_matrix3x3;

typedef struct s_keys_held
{
	int				p;
	int				y;
	int				r;
	int				h;
	int				vert;
	int				hori;
	int				shift;
	int				mouse;
}				t_keys_held;
typedef struct s_view_settings
{
	char			projection;
	int				zoom;
	int				x_offset;
	int				y_offset;
	int				yaw;
	int				pitch;
	int				roll;
	int				depth_mod;
	int				rotate_mode_pitch;
	int				rotate_mode_roll;
	int				rotate_mode_yaw;
	t_keys_held		*keys;
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
int				count_array_length(char **strings);

// Drawing functions

int				*get_grad(int l, int c1, int c2);
int				get_grad_at_step(int l, int c1, int c2, int step);
void			draw_line(mlx_image_t *img, t_pixel *a, t_pixel *b);
int				smaller_than(int nbr1, int nbr2);

int				get_rgba(int r, int g, int b, int a);
int				get_col_rgba(int rgba, char col);
int				get_col_rgb(int rgb, char col);
int				hex_to_rgba(int hex, int alpha);

// Conversion functions

t_pixel			***convert_hm_node_grid_to_pixel_grid(t_hm_node ***nodes, \
					t_view_settings *settings);
void 			apply_rotation(int *x, int *y, int *z, double pitch, \
					double roll, double yaw);
void			update_rotate_mode(t_view_settings *settings);

// Main loop / window management

void			logger(char type, char *message);
void			fdf_mlx_error(void);
t_view_settings	*initialize_settings(mlx_t	*mlx, mlx_image_t	*img, \
									t_hm_node	***heightmap, \
									t_keys_held	*keys);
t_keys_held		*initialize_keys(void);
void			refresh_screen(t_view_settings *settings);
void			draw_controls(t_view_settings	*settings);
void			closing_hook(void *param);

mlx_t			*fdf_init(t_hm_node	***heightmap);
void			fdf_draw_lines(mlx_image_t	*img, t_pixel	***pixelmap);
const char		*append_int_to_string(const char *str, int num);

// Key + Scroll Input

void			key_handler(mlx_key_data_t keydata, void *settings);
void			scroll_handler(double xdelta, double ydelta, void *param);

void			reset_settings(t_view_settings *settings);
void			status_log(t_view_settings *settings);
void			switch_projection(t_view_settings *settings);

void			edit_x_offset(t_view_settings *settings, double amount);
void			edit_y_offset(t_view_settings *settings, double amount);
void			pitch(t_view_settings *settings, double amount);
void			yaw(t_view_settings *settings, double amount);
void			roll(t_view_settings *settings, double amount);
void			zoom(t_view_settings *settings, double amount);
void			edit_depth(t_view_settings *settings, double amount);

#endif