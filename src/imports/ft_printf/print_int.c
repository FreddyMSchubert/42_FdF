/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 08:45:48 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/19 09:00:59 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	num_length(long num)
{
	if (num < 0)
		return (1 + num_length(-num));
	if (num < 10)
		return (1);
	return (1 + num_length(num / 10));
}

static int	itoout_loop(long num, int index)
{
	char	temp;
	int		written_chars;
	int		write_output;

	written_chars = 0;
	write_output = 0;
	if (num < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		written_chars++;
		num = -num;
	}
	if (num >= 10)
		write_output = itoout_loop(num / 10, index - 1);
	if (write_output == -1)
		return (-1);
	written_chars += write_output;
	temp = (num % 10) + '0';
	if (write(1, &temp, 1) == -1)
		return (-1);
	return (written_chars + 1);
}

int	print_int(int int_num)
{
	long	long_num;
	int		length;

	long_num = (long)int_num;
	length = num_length(long_num);
	if (itoout_loop(long_num, length - 1) == -1)
		return (-1);
	return (length);
}

int	print_u_int(unsigned int int_num)
{
	unsigned long	long_num;
	int				length;

	long_num = (unsigned long)int_num;
	length = num_length(long_num);
	if (itoout_loop(long_num, length - 1) == -1)
		return (-1);
	return (length);
}
