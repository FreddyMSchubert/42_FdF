/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:31:11 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 08:12:12 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list_item;

	new_list_item = malloc(sizeof(t_list));
	if (!new_list_item)
		return (NULL);
	new_list_item->content = content;
	new_list_item->next = NULL;
	return (new_list_item);
}
