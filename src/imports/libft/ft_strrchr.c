/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:46:35 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 16:25:17 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;

	counter = ft_strlen(s);
	while (counter >= 0)
	{
		if (s[counter] == (char)c)
		{
			return ((char *) &s[counter]);
		}
		counter--;
	}
	return (NULL);
}
