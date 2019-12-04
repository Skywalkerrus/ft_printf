/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:40:53 by bantario          #+#    #+#             */
/*   Updated: 2019/04/21 17:08:18 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (((unsigned char)*s1) == ((unsigned char)*s2))
	{
		if (((unsigned char)*s1) == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (((unsigned char)*s1) - ((unsigned char)*s2));
}
