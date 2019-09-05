/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 13:24:16 by bantario          #+#    #+#             */
/*   Updated: 2019/04/22 16:01:52 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		it_ng(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa(int n)
{
	char	*chs;
	int		size;
	int		y;
	int		neg;

	neg = 0;
	size = 2;
	y = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	it_ng(&n, &neg);
	while (y /= 10)
		size++;
	size = neg + size;
	if ((chs = (char *)malloc(sizeof(char) * (size))) == NULL)
		return (NULL);
	chs[--size] = '\0';
	while (size--)
	{
		chs[size] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		chs[0] = '-';
	return (chs);
}
