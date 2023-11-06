/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 08:39:22 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/18 09:34:29 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// the man the myth the legend
int	ft_printf(const char *str, ...);

// printing functions
int	print_char(char c);
int	print_str(char *str);
int	print_int(int int_num);
int	print_u_int(unsigned int int_num);
int	print_ptr(void *ptr);
int	print_hexa(int num, char case_format);

#endif