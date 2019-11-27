/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:54:43 by bantario          #+#    #+#             */
/*   Updated: 2019/11/27 18:08:59 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_printf.h"
#include <stdio.h>
#include "stdlib.h"
#include <stdarg.h>

void	print_int(char *hu, va_list ap, t_node *list)
{
	int		dval;

	if (*hu == 'd')
	{
		dval = va_arg(ap, int);
		ft_putnbr(dval);
		list->len = (list->len) + ft_strlen(ft_itoa(dval));
	}
}

void	print_str(char *hu, va_list ap, t_node *list)
{
	char	*str;

	if (*hu == 's')
	{
		str = va_arg(ap, char*);
		ft_putstr(str);
		list->len = (list->len) + ft_strlen(str);
	}
}

void	print_symb(char *hu, va_list ap, t_node *list)
{
	char	cval;

	if (*hu == 'c')
	{
		cval = va_arg(ap, int);
		ft_putchar(cval);
		list->len++; 
	}
}

void	print_ld(char *hu, va_list ap, t_node *list)
{
	long int lval;

	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'd')
		{
			lval = va_arg(ap, unsigned long long int);
			ft_putnbr(lval);
			list->len = list->len + ft_strlen(ft_itoa(lval));
		}
	}
}

void	print_long_l(char *hu, va_list ap, t_node *list)
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
				list->len = list->len + ft_strlen(ft_itoa(lval));
			}
		}
	}
}

void	print_llu(char *hu, va_list ap, t_node *list)
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
				list->len = list->len + ft_strlen(ft_itoa(llu));
			}
		}
	}
}

void	print_i(char *hu, va_list ap, t_node *list)
{
	signed int		chislo;
	char			*hex_to_numb;

	if (*hu == 'i')
	{
		chislo = va_arg(ap, signed int);
		hex_to_numb = ft_itoa(chislo);
		ft_putnbr(ft_atoi(hex_to_numb));
		list->len = list->len + ft_strlen(hex_to_numb);
	}
}

void	Func(unsigned int n, t_node *list)
{
	if (n != 0)
	{
		Func(n / 8, list);
		list->len++;
	}
	else
		return;
	list->len++;
	ft_putnbr(n % 8);
	return;
}

void	print_o(char *hu, va_list ap, t_node *list)
{
	int oo;

	if (*hu == 'o')
	{
		oo = va_arg(ap, unsigned int);
		if (oo == 0)
		{
			ft_putnbr(0);
			list->len++;
		}
		Func(oo, list);
	}
}

void	print_u(char *hu, va_list ap, t_node *list)
{
	int	uu;

	if (*hu == 'u')
	{
		uu = va_arg(ap, unsigned long long int);
		ft_putnbr(uu);
		list->len = list->len + ft_strlen(ft_itoa(uu));
	}
}

void	print_procent(char *hu, t_node *list)
{
	if (*hu == '%')
	{
		list->len++;
		ft_putchar('%');
	}
}

void	print_lu(char *hu, va_list ap, t_node *list)
{
	unsigned long lu;
	if (*hu == 'l')
	{
		hu++;
		if (*hu == 'u')
		{
			lu = va_arg(ap, unsigned long);
			ft_putnbr(lu);
			list->len = list->len + ft_strlen(ft_itoa(lu));
		}
	}
}

void	print_hu(char *hu, va_list ap, t_node *list)
{
	int val;
	
	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'u')
		{
			val = va_arg(ap, int);
			ft_putnbr(val);
			list->len = list->len + ft_strlen(ft_itoa(val));
		}
	}
}

void	print_hi(char *hu, va_list ap, t_node *list)
{
	signed short int val;

	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'i')
		{
			val = va_arg(ap, int);
			ft_putnbr(val);
			list->len = list->len + ft_strlen(ft_itoa(val));
		}
	}
}

void	print_hd(char *hu, va_list ap, t_node *list)
{
	short int hd;

	if (*hu == 'h')
	{
		hu++;
		if (*hu == 'd')
		{
			hd = va_arg(ap, int);
			ft_putnbr(hd);
			list->len = list->len + ft_strlen(ft_itoa(hd));
		}
	}
}

void	print_lli(char *hu, va_list ap, t_node *list)
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
				list->len = list->len + ft_strlen(ft_itoa(lli));
			}
		}
	}
}

void	Func2(int n, t_node *list)
{
	if (n != 0)
	{
		list->len++;
		Func2(n / 16, list);
	}
	else
		return;
	if ((n % 16) == 15)
		ft_putchar('f');
	else if ((n % 16) == 10)
		ft_putchar('a');
	else if ((n % 16) == 11)
		ft_putchar('b');
	else if ((n % 16) == 12)
		ft_putchar('c');
	else if ((n % 16) == 13)
		ft_putchar('d');
	else if ((n % 16) == 14)
		ft_putchar('e');
	else
		ft_putnbr(n % 16);
	return;
}

void    Func3(int n, t_node *list)
{
	if (n != 0)
	{
		list->len++;
		Func3(n / 16, list);
	}
	else
		return;
	if ((n % 16) == 10)
		ft_putchar('A');
	else if ((n % 16) == 11)
		ft_putchar('B');
	else if ((n % 16) == 12)
		ft_putchar('C');
	else if ((n % 16) == 13)
		ft_putchar('D');
	else if ((n % 16) == 14)
		ft_putchar('E');
	else if ((n % 16) == 15)
		ft_putchar('F');
	else
		ft_putnbr(n % 16);
	return;
}

void	print_zero(t_node *list)
{
	ft_putchar('0');
	list->len++;
	return;
}

void	print_x(char *hu, va_list ap, t_node *list)
{
	int dec;

	dec = 0;
	if (*hu == 'x')
	{
		dec = va_arg(ap, int);
		if (dec == 0)
			print_zero(list);
		Func2(dec, list);
	}
}

void	print_X(char *hu, va_list ap, t_node *list)
{
	int dec;

	dec = 0;
	if (*hu == 'X')
	{
		dec = va_arg(ap, int);
		if (dec == 0)
			print_zero(list);
		Func3(dec, list);
	}
}

void	print_float(char *hu, va_list ap)
{
	char *str;
	double fl;

	if (*hu == 'f')
	{
		str = (char *)malloc(sizeof(int) *1000);
		fl = va_arg(ap, double);
		float_to_str(fl, str, 6);
	}
}

void	one_proc(char *hu, t_node *list)
{
	if (*hu == '\0')
		list->len = 0;
}

void	cast_func(char *hu, va_list ap, func *mass, t_node *list)
{
	mass[1](hu, ap, list);
	mass[2](hu, ap, list);
	mass[3](hu, ap, list);
	mass[5](hu, ap, list);
	mass[6](hu, ap, list);
	mass[7](hu, ap, list);
	mass[8](hu, ap, list);
	mass[9](hu, ap, list);
	mass[10](hu, ap, list);
	mass[11](hu, list);
	mass[12](hu, ap, list);
	mass[13](hu, ap, list);
	mass[14](hu, ap, list);
	mass[15](hu, ap, list);
	mass[16](hu, ap, list);
	mass[17](hu, ap, list);
	mass[18](hu, ap, list);
	mass[19](hu, ap);
	mass[20](hu, list);
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
	mass[18] = print_X;
	mass[19] = print_float;
	mass[20] = one_proc;
}

int			ft_printf(char *hu, ...)
{
	func *mass;
	va_list ap;
	t_node  *list;

	list = (t_node *)malloc(sizeof(t_node));
	list->len = 0;
	mass = (void *) malloc(sizeof(void) * 250);
	va_start(ap, hu);
	mass[0] = fundament;
	mass[0](mass);
	while(*hu)
	{
		if (*hu != '%')
		{
			ft_putchar(*hu);
			list->len++;
		}
		else if (*hu == '%')
		{
			//list->len++;
			hu++;
			mass[4](hu, ap, mass, list);
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
	return(list->len);
}

int		main(int ac, char **av)
{
	int	f;
	//char a;
	//int	d;
	//long long int l;

	//a = 'r';
	//d = -343434453;
	//l = 9223372036854775807;
	//ll = −92233720368547;
	if (ac > 0)
	{
		av[0] = 0;
		f = printf("%");
		printf("1F: %d\n", f);
		f = ft_printf("%");
		printf("2F: %d\n", f);
		/*f = printf("%s\n", "1234");
		printf("2F: %d\n", f);
		f = ft_printf("%s\n", "1234");
		printf("2iF: %d\n", f);
		f = printf("my string: %s, my int: %d\n", "syka blyat", 0);
		printf("3F: %d\n", f);
		f = ft_printf("my string: %s, my int: %d\n", "syka blyat", 0);
		printf("3iF: %d\n", f);
		f = printf("\\n");
		printf("4F: %d\n", f);
		f = ft_printf("\\n");
		printf("4iF: %d\n", f); */
	}
	return (0);
} 
