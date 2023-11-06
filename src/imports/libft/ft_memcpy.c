/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 09:35:26 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/12 08:49:30 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*char_src;
	char		*char_dst;
	size_t		counter;

	if (!src && !dst)
		return (NULL);
	char_src = (char *)src;
	char_dst = (char *)dst;
	counter = 0;
	while (counter < n)
	{
		char_dst[counter] = char_src[counter];
		counter++;
	}
	return (dst);
}
