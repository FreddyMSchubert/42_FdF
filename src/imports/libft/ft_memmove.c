/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:23:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 11:49:28 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	SCENARIO 1: Beginning of DST is free (default case when not overlapping)
		-> Copy from beginning (=> copy_forward)
	SCENARIO 2: Beginnign of DST is filled
		-> Copy from end (=> copy_backwards)
	SCENARIO 3: Full Overlap
		-> just return DST
	checked in reverse order
*/

static void	*copy_forward(char *dst, const char *src, size_t len)
{
	size_t		counter;

	counter = 0;
	while (counter < len)
	{
		dst[counter] = src[counter];
		counter++;
	}
	return (dst);
}

static void	*copy_backward(char *dst, const char *src, size_t len)
{
	int		counter;

	counter = len - 1;
	while (counter >= 0)
	{
		dst[counter] = src[counter];
		counter--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*char_dst;
	char	*char_src;
	int		ptr_sub;

	char_dst = (char *)dst;
	char_src = (char *)src;
	ptr_sub = char_dst - char_src;
	if (ptr_sub == 0)
		return (dst);
	if (ptr_sub > 0 && ptr_sub < (int)len)
		return (copy_backward(char_dst, char_src, len));
	return (copy_forward(char_dst, char_src, len));
}
