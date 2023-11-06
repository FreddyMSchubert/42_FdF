/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:57:02 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/19 08:51:58 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int	print_addr(unsigned long address)
{
	int		written_chars;

	written_chars = 0;
	if (address >= 16)
		written_chars = print_addr(address / 16);
	if (written_chars == -1)
		return (-1);
	if (write(1, &"0123456789abcdef"[address % 16], 1) == -1)
		return (-1);
	written_chars ++;
	return (written_chars);
}

int	print_ptr(void *ptr)
{
	int		written_chars;

	written_chars = 2;
	if (write(1, "0x", 2) == -1)
		return (-1);
	written_chars += print_addr((unsigned long) ptr);
	if (written_chars == 2 - 1)
		return (-1);
	return (written_chars);
}
