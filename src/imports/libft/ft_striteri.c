/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:02:26 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 11:19:03 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		counter;
	int		strlen;

	counter = 0;
	strlen = 0;
	while (s[strlen])
		strlen++;
	while (counter < strlen)
	{
		f(counter, &s[counter]);
		counter++;
	}
}
