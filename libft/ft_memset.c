/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:15:17 by bantario          #+#    #+#             */
/*   Updated: 2019/04/09 16:08:42 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned long	i;

	i = 0;
	if (c == (c + '0'))
	{
		while (i < len)
		{
			((char *)str)[i] = c;
			i++;
		}
	}
	else
	{
		c = c - '0';
		c = c + '0';
		while (i < len)
		{
			((char *)str)[i] = c;
			i++;
		}
	}
	return (str);
}
