/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:01:57 by bantario          #+#    #+#             */
/*   Updated: 2019/04/23 19:35:24 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nl;
	t_list *cont;

	if (lst == NULL || !f)
		return (NULL);
	cont = f(lst);
	nl = cont;
	while (lst->next)
	{
		lst = lst->next;
		if (!(cont->next = f(lst)))
			return (NULL);
		cont = cont->next;
	}
	return (nl);
}
