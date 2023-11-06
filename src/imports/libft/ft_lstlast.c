/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:29:19 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 09:14:24 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*next_list_item;

	if (!lst)
		return (NULL);
	next_list_item = lst;
	while (next_list_item->next != NULL)
		next_list_item = next_list_item->next;
	return (next_list_item);
}
