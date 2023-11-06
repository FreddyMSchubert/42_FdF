/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:40:25 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 15:55:16 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	int		strlen;
	char	*p;

	counter = 0;
	strlen = 0;
	while (s[strlen])
		strlen++;
	p = malloc((strlen * sizeof(char)) + 1);
	if (p == NULL)
		return (NULL);
	while (counter < strlen)
	{
		p[counter] = f(counter, s[counter]);
		counter++;
	}
	p[counter] = '\0';
	return (p);
}
