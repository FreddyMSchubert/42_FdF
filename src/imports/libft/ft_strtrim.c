/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:15:30 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 11:50:43 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	go to front, go to back with seperate variables
	select the section that is supposed to be kept
	endselector - startselector gives the length, allocate it
	then just copy over with a loop starting at startselector
*/

#include "libft.h"

static int	char_contained_in_set(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		beg;
	int		end;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	if (set[0] == '\0' || s1[0] == '\0')
	{
		p = ft_substr(s1, 0, ft_strlen(s1));
		return (p);
	}
	beg = 0;
	end = ft_strlen(s1) - 1;
	while (char_contained_in_set(set, s1[beg]))
		beg++;
	while (char_contained_in_set(set, s1[end]) && end >= beg)
		end--;
	p = ft_substr(s1, beg, end - beg + 1);
	return (p);
}
