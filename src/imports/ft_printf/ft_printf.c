/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 07:40:32 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/19 08:49:06 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>

#include "ft_printf.h"

static int	identify_specials(const char *str, va_list args, int counter)
{
	if (str[counter + 1] == 'd' || str[counter + 1] == 'i')
		return (print_int(va_arg(args, int)));
	if (str[counter + 1] == 'c')
		return (print_char((char) va_arg(args, int)));
	if (str[counter + 1] == 'u')
		return (print_u_int(va_arg(args, int)));
	if (str[counter + 1] == 's')
		return (print_str(va_arg(args, char *)));
	if (str[counter + 1] == '%')
		return (print_char('%'));
	if (str[counter + 1] == 'p')
		return (print_ptr(va_arg(args, void *)));
	if (str[counter + 1] == 'x')
		return (print_hexa(va_arg(args, int), 'x'));
	if (str[counter + 1] == 'X')
		return (print_hexa(va_arg(args, int), 'X'));
	return (-1);
}

int	process_string(const char *str, va_list args)
{
	int	counter;
	int	printed_chars_counter;
	int	specials_output;

	counter = 0;
	printed_chars_counter = 0;
	specials_output = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] == '%')
		{
			specials_output = identify_specials(str, args, counter++);
			if (specials_output == -1)
				return (-1);
			printed_chars_counter += specials_output;
		}
		else
		{
			if (write(1, &str[counter], 1) == -1)
				return (-1);
			printed_chars_counter++;
		}
		counter++;
	}
	return (printed_chars_counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed_chars_counter;

	va_start(args, str);
	printed_chars_counter = 0;
	if (!str)
		return (va_end(args), 0);
	printed_chars_counter = process_string(str, args);
	va_end(args);
	if (printed_chars_counter == -1)
		return (-1);
	return (printed_chars_counter);
}
