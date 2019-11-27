/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:14:19 by bglinda           #+#    #+#             */
/*   Updated: 2019/11/26 16:34:49 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



double	part_int_ten(double n, int size)
{
    double mod;

    mod = 1;
    while((int)(n /= 10) != 0)
    {
        mod = mod * 10;
        size++;
    }
    return(mod);
}

int        int_part(double n, char *s, double mod)
{

    int     rank;
	int i = 0;

    while ((int)n != 0)
    {
        rank = (int)(n / mod);
        s[i] = (char)(rank + '0');
        n -= rank * mod;
        mod = mod / 10;
        i++;
    }
	return(i);
}

int        float_part(double n, char *s, int i, int rigor)
{
    int j;
    int tmp;


    n = (n - (int)n) * 10;
    j = 0;
    s[i++] = '.';
    while(j < rigor)
    {
		tmp = ((int)n != 9) ? (int)(n + 0.01) : (int)n;
        s[i++] = (char)(tmp + '0');
        n = (n - tmp) * 10;
        j++;
    }
	return (i);
}

void float_to_str(double n, char *str, int rigor) {
	int i;
	int size;
	double mod;

	size = 1;
	mod = part_int_ten(n, size);
	i = int_part(n, str, mod);
	i = float_part(n, str, i, rigor);
	str[i++] = '\0';
	ft_putstr(str);
}

//
//void print_float(char *hu, va_list ap, char *str, int rigor)
//{
//    double n;
//
//    if (*hu == 'd')
//    {
//        hu++;
//        n = va_arg(ap,double);
//        float_to_str(n,str,rigor)
//    }
//}


//
//void	cast_func(char *hu, va_list ap, func *mass)
//{
//    mass[1](hu, ap);
//    mass[2](hu, ap);
//    mass[3](hu, ap);
//    mass[5](hu, ap);
//    mass[6](hu, ap);
//    mass[7](hu, ap);
//    mass[8](hu, ap);
//    mass[9](hu, ap);
//    mass[10](hu, ap);
//    mass[11](hu);
//}
//
//void	fundament(func *mass)
//{
//    mass[1] = print_int;
//    mass[2] = print_str;
//    mass[3] = print_symb;
//    mass[4] = cast_func;
//    mass[5] = print_ld;
//    mass[6] = print_long_l;
//    mass[7] = print_i;
//    mass[8] = print_llu;
//    mass[9] = print_o;
//    mass[10] = print_u;
//    mass[11] = print_procent;
//
//}

//
//void ft_printf(char *hu, ...)
//{
//    func *mass;
//    va_list ap;
//
//    mass = (void *)ft_memalloc(sizeof(void) * 10000);
//    va_start(ap,hu);
//    mass[0] = fundament;
//    mass[0](mass);
//    while(*hu)
//    {
//        if(*hu != '%')
//            ft_putchar(*hu);
//        else if (*hu == '%')
//        {
//            hu++;
//            mass[4](hu, ap, mass);
//            if(*hu == 'f')
//            {
//                hu++;
//
//            }
//        }
//
//    }
//}





/*int main() {
	char *str = (char *)malloc(sizeof(int) *1000);

	float_to_str(275.1234,str,100);
	ft_putchar('\n');
	printf("%.100f\n",275.1234);

	return(0);

} */
