/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:11:39 by bantario          #+#    #+#             */
/*   Updated: 2019/04/21 14:31:58 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*fin;

	fin = (char *)s;
	while (*fin != c)
	{
		if (*fin == '\0')
			return (NULL);
		fin++;
	}
	return (fin);
}
