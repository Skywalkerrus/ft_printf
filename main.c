/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:54:43 by bantario          #+#    #+#             */
/*   Updated: 2019/09/05 18:41:24 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include "stdlib.h"
#include <stdarg.h>

void	print_int(char *hu, va_list ap)
{
	int		dval;

	if (*hu == 'd')
	{
		dval = va_arg(ap, int);
		ft_putnbr(dval);
	}
}

void	print_str(char *hu, va_list ap)
{
	char	*str;

	if (*hu == 's')
	{
		str = va_arg(ap, char*);
		ft_putstr(str);
	}
}

void	print_symb(char *hu, va_list ap)
{
	char	cval;

	if (*hu == 'c')
	{
		cval = va_arg(ap, int);
		ft_putchar(cval);
	}
}

void	fundament(func *mass)
{
	mass[1] = print_int;
	mass[2] = print_str;
	mass[3] = print_symb;
}

void	ft_printf(char *hu, ...)
{
	func *mass;
	va_list ap;

	mass = (void *) malloc(sizeof(void) * 20);
	va_start(ap, hu);
	mass[0] = fundament;
	mass[0](mass);
	while(*hu)
	{
		if (*hu != '%')
			ft_putchar(*hu);
		else if (*hu == '%')
		{
			hu++;
			mass[1](hu, ap);
			mass[2](hu, ap);
			mass[3](hu, ap);
		}
		hu++;
	}
	return;
}

int		main(int ac, char **av)
{
	char a;
	int	d;

	a = 'r';
	d = 34343445;
	if (ac > 0)
	{
		av[0] = 0;
		ft_printf("bla-bla flags: int - %d, str - %s, char - %c.", d, "Hello, pidoer", a);
	}
	return (0);
}
