/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:40:11 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/16 17:52:52 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	general function that are helpful
*/

#include "../../fdf.h"

// @brief	frees a twodimensional array
void	fdf_free_rec(void **blob)
{
	int		counter;

	counter = 0;
	if (blob != NULL)
	{
		while (blob[counter] != NULL)
		{
			free(blob[counter]);
			counter++;
		}
		free(blob);
	}
}

void	fdf_free_rec_rec(void ***blob)
{
	for (int y = 0; blob && blob[y]; y++)
	{
		for (int x = 0; blob[y][x]; x++)
		{
			free(blob[y][x]);
		}
		free(blob[y]);
	}
	if (blob)
		free (blob);
}

// @brief		turns hexa strings (e.g. colors) into ints. doesnt handle neg.
int	fdf_ft_hex_atoi(const char *s)
{
	int		i;
	int		value;

	i = 0;
	value = 0;
	if (s[i] == '0' && ft_toupper(s[i + 1]) == 'X')
		i += 2;
	while (ft_isdigit(s[i]) || \
		(s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'))
	{
		value = (value * 16);
		if (ft_isdigit(s[i]))
			value += s[i] - '0';
		else
			value += ft_toupper(s[i]) - 'A' + 10;
		i++;
	}
	return (value);
}

/*
	@brief			Counts the number of strings in a null-terminated array of strings
	@param strings	Array of strings (char **)
	@returns		Length of the array (excluding the terminating NULL)
*/
int	count_array_length(char **strings)
{
	int	length;

	length = 0;
	while (strings && strings[length] && \
			ft_strncmp(strings[length], "\n", 2) != 0)
	{
		length++;
	}
	return (length);
}
