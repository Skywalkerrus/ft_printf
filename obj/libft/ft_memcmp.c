/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 14:59:31 by bantario          #+#    #+#             */
/*   Updated: 2019/04/13 20:54:01 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char			*ss1;
	const unsigned char			*ss2;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	if (ss1 == ss2 && n == 0)
		return (0);
	while (n--)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		if (*ss1 == *ss2)
			;
		ss1++;
		ss2++;
	}
	return (0);
}
