/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 07:07:11 by fschuber          #+#    #+#             */
/*   Updated: 2023/11/03 06:54:25 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	@brief		Finds the first new line in the string; \n
	@return		The index, -1 for NULL or -2 if there's no new line; \n
*/
int	gnl_strchr(char *str, int c)
{
	int	counter;

	counter = -1;
	if (str == NULL)
		return (-1);
	while (str[++counter] != '\0')
		if (str[counter] == c)
			return (counter);
	return (-2);
}

/*
	@returns		Length of inputted string;
*/
int	gnl_strlen(const char *str)
{
	int	counter;

	counter = 0;
	if (!str)
		return (0);
	while (str[counter])
		counter++;
	return (counter);
}

/*
	@brief		Returns a substring of string s of length len beginning at index start;
*/
char	*gnl_substr(char const *s, int start, size_t len)
{
	char		*p;
	int			substr_len;
	int			counter;

	substr_len = len;
	if (gnl_strlen(s) - start < (int) len)
		substr_len = gnl_strlen(s) - start;
	if (substr_len < 0 || gnl_strlen(s) < start)
		substr_len = 0;
	p = (char *)malloc(substr_len + 1);
	if (p == NULL)
		return (NULL);
	counter = 0;
	while (counter < substr_len)
	{
		p[counter] = s[start + counter];
		counter++;
	}
	p[substr_len] = '\0';
	return (p);
}

/*
	@brief		Returns a new string combined of s1 and s2 without freeing anything;
*/
char	*gnl_strjoin(char const *s1, char const *s2)
{
	size_t		s1size;
	size_t		s2size;
	size_t		counter;
	char		*p;

	counter = 0;
	if (s1 == NULL && s2 == NULL)
		return (gnl_substr("", 0, 0));
	s1size = gnl_strlen(s1);
	s2size = gnl_strlen(s2);
	p = (char *)malloc(s1size + s2size + 1);
	if (p == NULL)
		return (NULL);
	while (s1 && counter < s1size)
	{
		p[counter] = s1[counter];
		counter++;
	}
	while (s2 && counter < s1size + s2size)
	{
		p[counter] = s2[counter - s1size];
		counter++;
	}
	p[s1size + s2size] = '\0';
	return (p);
}
