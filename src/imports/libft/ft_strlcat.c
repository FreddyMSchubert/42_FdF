/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 06:10:49 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:19:18 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstbuff)
{
	size_t		counter;
	size_t		srclen;
	size_t		dstlen;

	counter = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstbuff <= dstlen)
		return (srclen + dstbuff);
	while (src[counter] && counter + dstlen < dstbuff)
	{
		dst[counter + dstlen] = src[counter];
		counter++;
	}
	if (counter + dstlen + 1 < dstbuff)
		dst[counter + dstlen] = '\0';
	else if (dstbuff > 0 && dstlen <= dstbuff - 1)
		dst[dstbuff - 1] = '\0';
	return (srclen + dstlen);
}
