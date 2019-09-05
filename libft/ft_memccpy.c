/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:39:48 by bantario          #+#    #+#             */
/*   Updated: 2019/04/19 16:39:39 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dd;
	unsigned char	*ss;

	i = 0;
	dd = (unsigned char *)d;
	ss = (unsigned char *)s;
	while (i < n)
	{
		dd[i] = ss[i];
		if ((unsigned char)c == ss[i])
			return (dd + i + 1);
		i++;
	}
	return (NULL);
}
