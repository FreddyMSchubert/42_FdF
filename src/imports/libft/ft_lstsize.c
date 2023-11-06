/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:33:49 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 09:11:25 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*next_list_item;
	int		list_items_count;

	if (!lst)
		return (0);
	next_list_item = lst->next;
	list_items_count = 1;
	while (next_list_item != NULL)
	{
		next_list_item = next_list_item->next;
		list_items_count++;
	}
	return (list_items_count);
}
