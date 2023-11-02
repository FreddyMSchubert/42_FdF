/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:40:11 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/02 10:01:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	general function that are helpful
*/

#include "fdf.h"

// @brief	frees a twodimensional array
void	free_rec(void **blob)
{
	int		counter;

	counter = 0;
	if (blob != NULL)
	{
		while (blob[counter] != '\0')
		{
			free(blob[counter]);
			counter++;
		}
		free(blob);
	}
}

void	free_rec_rec(void ***blob)
{
	
}

// @brief		turns hexa strings (e.g. colors) into ints. doesnt handle neg.
int	ft_hex_atoi(const char *s)
{
	int		i;
	int		value;

	i = 0;
	value = 0;
	while (ft_isdigit(s[i]) || \
		(ft_toupper(s[i]) >= 'a' && ft_toupper(s[i]) <= 'f'))
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
