/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:43:27 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/10 12:48:41 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

/*
	@brief		Logs a message with a type in front.
				Types: e - Error, l - Logger, s - Success.
*/
void	logger(char type, char *message)
{
	if (type == 'e')
		ft_printf("\033[31mERROR\033[0m: ");
	if (type == 'l')
		ft_printf("\033[33mLOGGER\033[0m: ");
	if (type == 's')
		ft_printf("\033[32mSUCCCESS\033[0m: ");
	ft_printf("%s", message);
}

//	@returns	Width of inputted pixelmap
int	get_pixelmap_width(t_pixel	***pixelmap)
{
	int		width;


	width = 0;
	while (pixelmap[0][width]->terminator != 1)
	{
		width++;
	}
	return (width);
}

//	@returns	Height of inputted pixelmap
int	get_pixelmap_height(t_pixel	***pixelmap)
{
	int		height;


	height = 0;
	while (pixelmap[height][0]->terminator != 1)
	{
		height++;
	}
	return (height);
}
