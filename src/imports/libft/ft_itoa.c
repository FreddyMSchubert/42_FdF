/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 09:02:10 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 11:43:01 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	num_length(int num)
{
	if (num < 0)
		return (1 + num_length(-num));
	if (num < 10)
		return (1);
	return (1 + num_length(num / 10));
}

static void	itoa_loop(int num, char *str, int index)
{
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num >= 10)
		itoa_loop(num / 10, str, index - 1);
	str[index] = (num % 10) + '0';
}

char	*ft_itoa(int numb)
{
	size_t	length;
	char	*char_numb;

	if (numb == -2147483648)
		return (ft_strdup("-2147483648"));
	length = num_length(numb);
	char_numb = (char *)malloc(length + 1);
	if (char_numb == NULL)
		return (NULL);
	char_numb[length] = '\0';
	itoa_loop(numb, char_numb, length - 1);
	return (char_numb);
}
