/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:24:47 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:19:09 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1size;
	size_t		s2size;
	char		*p;

	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	p = (char *)malloc(s1size + s2size + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(&p[0], s1, s1size);
	ft_memcpy(&p[s1size], s2, s2size);
	p[s1size + s2size] = '\0';
	return (p);
}
