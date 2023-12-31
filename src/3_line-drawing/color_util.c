/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:11:21 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/10 08:27:49 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// @brief		'Encodes' four individual bytes into an int.
int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// @brief			Returns data of specified color channel
// @param col 		Either 'r', 'g', 'b', 'a'
int	get_col_rgba(int rgba, char col)
{
	if (col == 'r')
		return ((rgba >> 24) & 0xFF);
	if (col == 'g')
		return ((rgba >> 16) & 0xFF);
	if (col == 'b')
		return ((rgba >> 8) & 0xFF);
	if (col == 'a')
		return (rgba & 0xFF);
	return (0);
}

// @brief			Returns data of specified color channel
// @param col 		Either 'r', 'g', 'b'
int	get_col_rgb(int rgb, char col)
{
	if (col == 'r')
		return ((rgb >> 16) & 0xFF);
	if (col == 'g')
		return ((rgb >> 8) & 0xFF);
	if (col == 'b')
		return (rgb & 0xFF);
	return (0);
}

// @brief			Takes in a number in rgb format and returns in rgba format
//					e.g. hexadecimal to rgba format
int	hex_to_rgba(int hex, int alpha)
{
	return (get_rgba(get_col_rgb(hex, 'r'), \
					get_col_rgb(hex, 'g'), \
					get_col_rgb(hex, 'b'), \
					alpha));
}
