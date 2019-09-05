/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:25:02 by bantario          #+#    #+#             */
/*   Updated: 2019/04/20 18:07:23 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hast, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)hast);
	if (*needle == '\0')
		return ((char *)hast);
	while (hast[i] != '\0')
	{
		j = 0;
		while (hast[i + j] == needle[j])
		{
			if (hast[i + j] == '\0' || needle[j + 1] == '\0')
				return ((char *)hast + i);
			j++;
		}
		i++;
	}
	return (0);
}
