/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:54:43 by bantario          #+#    #+#             */
/*   Updated: 2019/11/13 19:31:36 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include "stdlib.h"
#include <stdarg.h>

#define T1 0x0

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

void	print_ld(char *hu, va_list ap)
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

void	print_llu(char *hu, va_list ap)
{
	unsigned long long int llu;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'l')
		{
			hu++;
			if (*hu == 'u')
			{
				llu = va_arg(ap, unsigned long long int);
				ft_putnbr_2(llu);
			}
		}
	}
}

void	print_i(char *hu, va_list ap)
{
	signed int		chislo;
	char			*hex_to_numb;

	if (*hu == 'i')
	{
		chislo = va_arg(ap, signed int);
		hex_to_numb = ft_itoa(chislo);
		ft_putnbr(ft_atoi(hex_to_numb));
	}
}

void	Func(unsigned int n)
{
	if (n != 0)
		Func(n / 8);
	else
		return;
	ft_putnbr(n % 8);
	return;
}

void	print_o(char *hu, va_list ap)
{
	int oo;

	if (*hu == 'o')
	{
		oo = va_arg(ap, unsigned int);
		if (oo == 0)
			ft_putnbr(0);
		Func(oo);
	}
}

void	print_u(char *hu, va_list ap)
{
	int	uu;

	if (*hu == 'u')
	{
		uu = va_arg(ap, unsigned long long int);
		ft_putnbr(uu);
	}
}

void	print_procent(char *hu)
{
	if (*hu == '%')
		ft_putchar('%');
}

void	print_lu(char *hu, va_list ap)
{
	unsigned long lu;
	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'u')
		{
			lu = va_arg(ap, unsigned long);
			ft_putnbr(lu);
		}
	}
}

void	print_hu(char *hu, va_list ap)
{
	int val;
	
	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'u')
		{
			val = va_arg(ap, int);
			ft_putnbr(val);
		}
	}
}

void	print_hi(char *hu, va_list ap)
{
	signed short int val;

	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'i')
		{
			val = va_arg(ap, int);
			ft_putnbr(val);
		}
	}
}

void	print_hd(char *hu, va_list ap)
{
	short int hd;

	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'd')
		{
			hd = va_arg(ap, int);
			ft_putnbr(hd);
		}
	}
}

void	print_lli(char *hu, va_list ap)
{
	signed long long int lli;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'l')
		{
			hu++;
			if (*hu == 'i')
			{
				lli = va_arg(ap, signed long long int);
				ft_putnbr(lli);
			}
		}
	}
}

void	print_x(char *hu, va_list ap)
{
	int dec;
	char *hex;
	int i;

	i = 0;
	hex = (char *)malloc(sizeof(char) * 50);
	dec = 0;
	if (*hu == 'x')
	{
		//hex[i] = (char) (va_arg(ap, int));
		dec = va_arg(ap, int);
		printf(" %d ", dec);

	}
}

void	cast_func(char *hu, va_list ap, func *mass)
{
	mass[1](hu, ap);
	mass[2](hu, ap);
	mass[3](hu, ap);
	mass[5](hu, ap);
	mass[6](hu, ap);
	mass[7](hu, ap);
	mass[8](hu, ap);
	mass[9](hu, ap);
	mass[10](hu, ap);
	mass[11](hu);
	mass[12](hu, ap);
	mass[13](hu, ap);
	mass[14](hu, ap);
	mass[15](hu, ap);
	mass[16](hu, ap);
	mass[17](hu, ap);
}

void	fundament(func *mass)
{
	mass[1] = print_int;
	mass[2] = print_str;
	mass[3] = print_symb;
	mass[4] = cast_func;
	mass[5] = print_ld;
	mass[6] = print_long_l;
	mass[7] = print_i;
	mass[8] = print_llu;
	mass[9] = print_o;
	mass[10] = print_u;
	mass[11] = print_procent;
	mass[12] = print_lu;
	mass[13] = print_hu;
	mass[14] = print_hi;
	mass[15] = print_hd;
	mass[16] = print_lli;
	mass[17] = print_x;
}

void	ft_printf(char *hu, ...)
{
	func *mass;
	va_list ap;

	mass = (void *) malloc(sizeof(void) * 200);
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
			if (*hu == 'l' || *hu == 'h')
			{
				hu++;
				if (*hu == 'u' || *hu == 'i')
					hu--;
				if (*hu != 'd')
					hu++;
			}
		}
		hu++;
	}
	free(mass);
	va_end(ap);
	return;
}

int		main(int ac, char **av)
{
	char a;
	int	d;
	long long int l;

	a = 'r';
	d = -343434453;
	l = 9223372036854775807;
	//ll = −92233720368547;
	if (ac > 0)
	{
		av[0] = 0;
		printf("printf: %x\n", 0x64);
		//ft_printf("ft_printf: %x\n", 0xFF);
		ft_printf("ft_printf: %x\n", 0x64);
	}
	return (0);
}
