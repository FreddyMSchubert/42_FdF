/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 07:18:01 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/03 06:55:08 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	@brief		Reads one chunk from filedes & appends it to left; \n
	@brief		The return value of read gets written into read_ret; \n
	@returns	-1 on failure, 0 on EOF, 1 on success; \n
*/
int	get_next_chunk(char **left, int filedes, int *read_ret)
{
	char			*temp;
	char			*buffer;

	buffer = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer)
		return (-1);
	*read_ret = read(filedes, buffer, BUFFER_SIZE);
	if (*read_ret <= 0)
		return (free (buffer), *read_ret);
	buffer[*read_ret] = '\0';
	temp = *left;
	*left = gnl_strjoin(temp, buffer);
	free (buffer);
	free (temp);
	if (!*left)
		return (-1);
	return (1);
}

/*
	@brief		Returns a full line & removes it from left;
*/
char	*split_off_line(char **left, int split_i)
{
	char	*temp_left;
	char	*temp_return;

	temp_return = gnl_substr(*left, 0, split_i);
	temp_left = gnl_substr(*left, split_i, gnl_strlen(*left) - split_i);
	free(*left);
	*left = temp_left;
	return (temp_return);
}

/*
	@returns			Line by line of filedes content on subsequent function calls;
	@brief	left:		chars read but not returned in last function call; \n
	@brief	read_ret:	return value of read call;
*/
char	*get_next_line(int filedes)
{
	static char		*left;
	int				read_ret;

	read_ret = 1;
	while (gnl_strchr(left, '\n') < 0 && read_ret > 0)
		if (get_next_chunk(&left, filedes, &read_ret) == -1)
			return (free (left), left = NULL, NULL);
	if (gnl_strlen(left) > 0)
	{
		if (gnl_strchr(left, '\n') == -2)
			return (split_off_line(&left, gnl_strlen(left)));
		else
			return (split_off_line(&left, gnl_strchr(left, '\n') + 1));
	}
	if (gnl_strlen(left) == 0 && read_ret == 0)
		return (free (left), left = NULL, NULL);
	return (free(left), left = NULL, NULL);
}
