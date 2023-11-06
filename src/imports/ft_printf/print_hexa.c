/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:58:12 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/19 08:33:38 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hexa(int num, char case_format)
{
	int					written_chars;
	unsigned int		u_num;

	written_chars = 0;
	u_num = (unsigned int)num;
	if (u_num >= 16)
	{
		written_chars = print_hexa(u_num / 16, case_format);
		if (written_chars == -1)
			return (-1);
	}
	if (case_format == 'x')
		if (write(1, &"0123456789abcdef"[u_num % 16], 1) == -1)
			return (-1);
	if (case_format == 'X')
		if (write(1, &"0123456789ABCDEF"[u_num % 16], 1) == -1)
			return (-1);
	written_chars ++;
	return (written_chars);
}
