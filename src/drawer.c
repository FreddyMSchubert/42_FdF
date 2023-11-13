/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 08:32:19 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/13 08:20:43 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_draw_lines(mlx_image_t	*img, t_pixel	***pixelmap)
{
	int		x;
	int		y;
	int		width;

	width = 0;
	while (pixelmap[0][width])
		width++;
	y = 0;
	while (pixelmap[y])
	{
		x = 0;
		while (pixelmap[y][x])
		{
			if (y - 1 >= 0)
				draw_line(img, pixelmap[y][x], pixelmap[y - 1][x]);
			if (x + 1 < width)
				draw_line(img, pixelmap[y][x], pixelmap[y][x + 1]);
			x++;
		}
		y++;
	}
}

void	refresh_screen(t_view_settings *settings)
{
	t_pixel		***pixelmap;
	int			x;
	int			y;

	y = 0;
	while (y < settings->mlx->height)
	{
		x = 0;
		while (x < settings->mlx->width)
		{
			mlx_put_pixel(settings->img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
	pixelmap = convert_hm_node_grid_to_pixel_grid(settings->heightmap, \
													settings);
	fdf_draw_lines(settings->img, pixelmap);
	draw_status(settings);
}

static void	put_line(t_view_settings	*settings, int line, const char *text)
{
	mlx_put_string(settings->mlx, text, 0 + 10, line * 15 + 10);
}

void	draw_controls(t_view_settings	*settings)
{
	put_line(settings, 0, "CONTROLS");

	put_line(settings, 2, "Scroll                   -> Zoom");
	put_line(settings, 3, "Hold Arrow Keys + Scroll -> Change Translation");

	put_line(settings, 5, "Hold P + Scroll -> Change Pitch");
	put_line(settings, 6, "Hold Y + Scroll -> Change Yaw");
	put_line(settings, 7, "Hold R + Scroll -> Change Roll");

	put_line(settings, 9, "Shift + P -> Toggle Pitch Rotate Mode");
	put_line(settings, 10, "Shift + Y -> Toggle Yaw Rotate Mode");
	put_line(settings, 11, "Shift + R -> Toggle Roll Rotate Mode");

	put_line(settings, 13, "i      -> Switch Projection");
	put_line(settings, 14, "s      -> Status Log");
	put_line(settings, 15, "esc    -> Close Window");
	put_line(settings, 16, "delete -> reset settings");
}

void	draw_status(t_view_settings	*s)
{
	put_line(s, 19, "STATUS");

	put_line(s, 21, append_int_to_string("Zoom:    ", s->zoom));
	put_line(s, 22, append_int_to_string("Xoffset: ", s->x_offset));
	put_line(s, 23, append_int_to_string("Yoffset: ", s->y_offset));

	put_line(s, 25, append_int_to_string("Depth:   ", s->depth_mod));

	put_line(s, 27, append_int_to_string("Yaw:   ", s->yaw));
	put_line(s, 28, append_int_to_string("Pitch: ", s->pitch));
	put_line(s, 29, append_int_to_string("Roll:  ", s->roll));

	put_line(s, 31, append_int_to_string("Rotate Yaw: ", s->rotate_mode_yaw));
	put_line(s, 32, append_int_to_string("Rotate Pit: ", s->rotate_mode_pitch));
	put_line(s, 33, append_int_to_string("Rotate Rol: ", s->rotate_mode_roll));
}
