/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 07:08:17 by tiskow            #+#    #+#             */
/*   Updated: 2016/10/17 04:46:59 by tiskow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*crt;

	new = ft_lstnew(lst->content, lst->content_size);
	if (new)
	{
		new = f(new);
		while (lst->next)
		{
			lst = lst->next;
			crt = ft_lstnew(lst->content, lst->content_size);
			while (new->next)
				crt = crt->next;
			crt->next = new;
		}
	}
	return (new);
}