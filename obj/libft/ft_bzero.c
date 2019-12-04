/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:07:19 by bantario          #+#    #+#             */
/*   Updated: 2019/04/09 19:11:25 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t cif)
{
	unsigned long	i;

	i = 0;
	if (cif == 0)
		return (0);
	if (cif > 0)
	{
		while (i < cif)
		{
			((char *)str)[i] = 0;
			i++;
		}
		return (str);
	}
	return (0);
}
