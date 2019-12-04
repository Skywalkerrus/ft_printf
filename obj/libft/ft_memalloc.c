/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:13:32 by bantario          #+#    #+#             */
/*   Updated: 2019/04/22 15:25:59 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *mas;

	if (size > 1844674407370955161)
		return (NULL);
	mas = malloc(sizeof(size));
	if (mas == NULL)
		return (NULL);
	ft_memset(mas, 0, size);
	return (mas);
}
