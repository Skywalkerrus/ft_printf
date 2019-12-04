/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 17:43:16 by bantario          #+#    #+#             */
/*   Updated: 2019/04/19 16:40:58 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char		*ss1;
	const char	*ss2;
	int			i;
	int			len;

	len = 0;
	i = 0;
	ss1 = (char *)s1;
	ss2 = (const char *)s2;
	len = ft_strlen(s1);
	while (ss2[i] != '\0')
	{
		ss1[len + i] = ss2[i];
		i++;
	}
	ss1[len + i] = '\0';
	return (ss1);
}
