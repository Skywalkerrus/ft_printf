/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 19:42:51 by bantario          #+#    #+#             */
/*   Updated: 2019/04/21 16:03:00 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *jaba;

	if ((jaba = (t_list *)malloc(sizeof(jaba) * content_size)) == NULL)
		return (NULL);
	if (content == NULL)
	{
		jaba->content = NULL;
		jaba->content_size = 0;
	}
	else
	{
		if ((jaba->content = malloc(sizeof(content_size))) == NULL)
		{
			free(jaba);
			return (NULL);
		}
		ft_memcpy(jaba->content, content, content_size);
		jaba->content_size = content_size;
	}
	jaba->next = NULL;
	return (jaba);
}
