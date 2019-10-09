/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:54:43 by bantario          #+#    #+#             */
/*   Updated: 2019/10/09 18:43:41 by bantario         ###   ########.fr       */
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

void	print_long(char *hu, va_list ap)
{
	long int lval;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'd')
		{
			lval = va_arg(ap, unsigned long long int);
			ft_putnbr(lval);
		}
	}
}

void	print_long_l(char *hu, va_list ap)
{
	long long int lval;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'l')
		{
			hu++;
			if (*hu == 'd')
			{
				lval = va_arg(ap, unsigned long long int);
				ft_putnbr(lval);
			}
		}
	}
}

void	cast_func(char *hu, va_list ap, func *mass)
{
	mass[1](hu, ap);
	mass[2](hu, ap);
	mass[3](hu, ap);
	mass[5](hu, ap);
	mass[6](hu, ap);
}

void	fundament(func *mass)
{
	mass[1] = print_int;
	mass[2] = print_str;
	mass[3] = print_symb;
	mass[4] = cast_func;
	mass[5] = print_long;
	mass[6] = print_long_l;
}

void	ft_printf(char *hu, ...)
{
	func *mass;
	va_list ap;

	mass = (void *) malloc(sizeof(void) * 50);
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
			mass[4](hu, ap, mass);
			if (*hu == 'l')
			{
				hu++;
				if (*hu != 'd')
					hu++;
			}
		}
		hu++;
	}
	return;
}

int		main(int ac, char **av)
{
	char a;
	int	d;
	long long int l;
	//signed long long int ll;

	a = 'r';
	d = -343434453;
	l = 9223372036854775807;
	//ll = −92233720368547;
	if (ac > 0)
	{
		av[0] = 0;
		//printf("Nmy printf:\n");
		//printf("bla-bla flags: int - %d, str - %s, char - %c., long int: %li", d, "Hello\n", a, l);
		//ft_printf("bla-bla int: %d, str: %s, char: %c.", d, "Hello, man\n", a);
		//printf("bla-bla flags: int: %d, str: %s, char: %c.", d, "Hello, man\n", a);
		//ft_printf("bla-bla flags: int: %d, str: %s, char: %c.", d, "Hello, man\n", a);
		//printf("bla-bla flags: int: %d, str: %s, char: %c, str: %s, long: %ld.\n", d, "Joe Barbaro", a, "Geralt of Rivia", l);
		//ft_printf("bla-bla flags: int: %d, str: %s, char: %c, str: %s, long: %ld.\n", d, "Joe Barbaro", a, "Geralt of Rivia", l);
		printf("\nlong: %lld allilya\n", l);
		ft_printf("long: %lld allilya\n", l);
		
		//ft_printf("sizeof : %d\n", sizeof(long int));
	}
	return (0);
}
