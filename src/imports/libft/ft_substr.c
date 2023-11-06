/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 07:11:20 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/12 06:11:29 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	int			substr_len;

	substr_len = len;
	if (ft_strlen(s) - start < len)
		substr_len = ft_strlen(s) - start;
	if (substr_len < 0)
		substr_len = 0;
	if (ft_strlen(s) < start)
		substr_len = 0;
	p = (char *)malloc(substr_len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, &s[start], substr_len);
	p[substr_len] = '\0';
	return (p);
}
