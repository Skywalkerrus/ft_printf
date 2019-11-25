/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:49:49 by bantario          #+#    #+#             */
/*   Updated: 2019/04/23 19:42:11 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblankss(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
			|| c == '\v' || c == '\t'
			|| c == '\r')
		return (1);
	return (0);
}

static int	ft_sign(int y)
{
	if (y < 0)
		return (0);
	return (-1);
}

int			ft_atoi(const char *str)
{
	int			sign;
	long int	result;
	long int	check;

	result = 0;
	sign = 1;
	check = 0;
	while (ft_isblankss(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		check = result;
		result = *str++ + result * 10 - '0';
		if (result / 10 != check)
			return (ft_sign(sign));
	}
	return (result * sign);
}
