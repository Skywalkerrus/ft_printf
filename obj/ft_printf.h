/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:36:21 by bantario          #+#    #+#             */
/*   Updated: 2019/11/28 15:30:31 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include "stdlib.h"
#include <stdarg.h>
typedef struct s_node
{
	int len;
	int	when_pr;
} t_node;
typedef unsigned long long int size_b;
typedef void (*func)();
double		part_int_ten(double n, int size);
int			int_part(double n, char *s, double mod);
int			float_part(double n, char *s, int i, int rigor);
void		float_to_str(double n, char *str, int rigor);
int			ft_printf(char *hu, ...);
#endif
