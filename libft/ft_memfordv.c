/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfordv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 20:07:39 by bantario          #+#    #+#             */
/*   Updated: 2019/04/22 12:36:11 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_memfordv(size_t size)
{
	char			**str;
	unsigned int	i;

	i = 0;
	str = (char **)malloc(sizeof(char*) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = NULL;
	return (str);
}
