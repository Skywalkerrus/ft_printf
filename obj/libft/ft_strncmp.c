/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:16:51 by bantario          #+#    #+#             */
/*   Updated: 2019/04/15 19:59:41 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	if (*s1 == '\0' || *s2 == '\0')
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (i < n && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		i++;
		s1++;
		s2++;
	}
	return (0);
}
