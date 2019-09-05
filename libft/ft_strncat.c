/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 18:05:38 by bantario          #+#    #+#             */
/*   Updated: 2019/04/19 16:41:11 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len;
	char		*ss1;
	const char	*ss2;

	ss1 = (char *)s1;
	ss2 = (const char *)s2;
	len = 0;
	i = 0;
	while (ss1[len])
		len++;
	while (n > 0 && ss2[i] != '\0')
	{
		ss1[len] = ss2[i];
		i++;
		len++;
		n--;
	}
	ss1[len] = '\0';
	return (ss1);
}
