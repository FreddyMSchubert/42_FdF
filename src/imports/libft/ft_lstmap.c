/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:45:22 by fschuber          #+#    #+#             */
/*   Updated: 2023/10/13 09:53:14 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*f_list;

	if (!lst || !f)
		return (NULL);
	f_list = ft_lstnew(f(lst->content));
	if (!f_list)
		return (NULL);
	f_list->next = ft_lstmap(lst->next, f, del);
	return (f_list);
}
