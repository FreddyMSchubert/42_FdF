/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:08:22 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/12 10:15:47 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *haystack, int n, size_t arrayend)
{
	size_t			counter;
	unsigned char	*char_haystack;
	unsigned char	needle;

	needle = (unsigned char)n;
	char_haystack = (unsigned char *)haystack;
	counter = 0;
	while (counter < arrayend)
	{
		if (char_haystack[counter] == needle)
			return ((void *)&char_haystack[counter]);
		counter++;
	}
	return (NULL);
}
