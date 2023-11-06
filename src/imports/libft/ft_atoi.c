/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 08:47:50 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 11:47:27 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char s)
{
	if (s == ' ' || s == '\t' || s == '\n' || s == '\v')
		return (1);
	if (s == '\f' || s == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *s)
{
	int		i;
	int		sign;
	int		value;

	i = 0;
	sign = 1;
	value = 0;
	while (ft_isspace(s[i]))
		i++;
	if (!ft_isdigit(s[i]))
	{
		if (s[i] == '-')
			sign = -sign;
		if (s[i] == '-' || s[i] == '+')
			i++;
		else
			return (0);
	}
	while (ft_isdigit(s[i]))
	{
		if (ft_isdigit(s[i]))
			value = (value * 10) + s[i] - 48;
		i++;
	}
	return (value * sign);
}
