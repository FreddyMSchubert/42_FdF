/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:32:41 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/11 15:51:42 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int		counter;
	char	newline;

	counter = 0;
	newline = '\n';
	while (s[counter])
	{
		write(fd, &s[counter], 1);
		counter++;
	}
	write(fd, &newline, 1);
}
