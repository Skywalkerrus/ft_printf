/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:17:57 by bantario          #+#    #+#             */
/*   Updated: 2019/04/23 19:31:41 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *n_list;

	if (*alst == NULL || alst == NULL)
		return ;
	if (del == NULL)
		return ;
	list = *alst;
	while (list != NULL)
	{
		n_list = list->next;
		del(list->content, list->content_size);
		free(list);
		list = NULL;
		list = n_list;
	}
	*alst = NULL;
}
