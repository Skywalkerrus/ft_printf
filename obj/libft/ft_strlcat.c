/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:16:23 by bantario          #+#    #+#             */
/*   Updated: 2019/04/21 19:06:25 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		r;

	r = ft_strlen(s1);
	i = 0;
	if (r > size)
		r = size;
	if (r == size || size == 0)
		return (r + ft_strlen(s2));
	while (s1[i] != '\0' && i < size)
		i++;
	j = i;
	while (s2[i - j] != '\0' && i < size - 1)
	{
		s1[i] = s2[i - j];
		i++;
	}
	if (j < size)
		s1[i] = '\0';
	return (j + ft_strlen(s2));
}
