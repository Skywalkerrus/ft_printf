/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:14:19 by bglinda           #+#    #+#             */
/*   Updated: 2019/11/18 17:14:36 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double	part_int_ten(double n, int *size)
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

void        int_part(double *n, char **str, int *i, double mod)
{
    char    *s;
    int     rank;

    s = *str;
    while ((int)*n != 0)
    {
        rank = (int)(*nb / mod);
        s[(*i)] = (char)(rank + '0');
        *n -= rank * mod;
        mod = mod / 10;
        *i++;
    }
}

void        float_part(double n, char **str, int *i, int rigor)
{

    int j;
    int tmp;
    char *s;

    n = n * 10;
    j = 0;
    s = *str;
    s[(*i)++] = '.';
    while(j < rigor)
    {
        tmp = (int)(nb);
        s[(*i)++] = (char)(tmp + '0');
        nb = (nb - tmp) * 10;
    }
}

int float_to_str(double n, char **res, int rigor)
{
    int i;
    int size;
    char *str;
    double mod;

    i = 0;
    size = 1;
    mod = part_int_ten(b, &size);
    str = ft_memalloc(sizeof(char) * (size + rigor));
    int_part(&n, &str, &i, mod);
    float_part(n, &str,&i, rigor);
    str[--i] = '\0';
    *res = str;
    return (size);
}

int write_f(void *s, int size,t_flags *flags)
{
    int i;
    char *str;

    i = 0;
    str = s;
    while (i < size)
        flags->buffer[flags->bytes++] = str[i++];
    flags->total_bytes += size;
    return (size);
}

int type_f(va_list ap,t_flags *flags)
{
    char *nb;
    int size;

    size = float_to_str(va_arg(ap, double), &nb, 7);
    write_f(nb,size,flags);
    ft_memdel(nb);
    return (size);
}


void print_float(char *hu, va_list ap)
{
    int size;

    if(*hu == 'f')
        size =  float_to_str(va_arg(ap,double), &nb,5);
    write_f(nb,size,fl)

}

//void	cast_func(char *hu, va_list ap, func *mass)
//{
//    m
//}

int ft_printf()

int main()
{

    int size;

    size = ft_put_float_to_string(va_arg(args, double), &nb, flags->precision);
    return(0);
}
