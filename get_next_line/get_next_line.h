/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: freddy <freddy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:25:52 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/25 17:10:19 by freddy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// utils

int		gnl_strchr(char *str, int c);
int		ft_strlen(const char	*str);
char	*gnl_substr(char const *s, int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

// important

char	*get_next_line(int fd);
int		get_next_chunk(char **left, int filedes, int *read_ret);
char	*split_off_line(char **left, int split_i);

#endif
