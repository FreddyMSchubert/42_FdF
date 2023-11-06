/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 06:43:57 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:23:31 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*p;
	size_t		i;
	size_t		strlen;

	i = 0;
	strlen = (size_t)ft_strlen(s1);
	p = (char *)malloc(strlen + 1);
	if (p == NULL)
		return (NULL);
	while (i < strlen)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
