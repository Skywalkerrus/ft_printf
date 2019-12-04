/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:20:25 by bantario          #+#    #+#             */
/*   Updated: 2019/04/19 17:11:36 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*unio;
	size_t			len;
	unsigned long	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = -1;
	unio = (char *)malloc(sizeof(char) * (len + 1));
	if (unio == NULL)
		return (NULL);
	while (*s1)
		unio[++i] = *s1++;
	while (*s2)
		unio[++i] = *s2++;
	unio[++i] = '\0';
	return (unio);
}
