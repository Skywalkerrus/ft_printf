/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:14:09 by bglinda           #+#    #+#             */
/*   Updated: 2019/10/21 17:14:12 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

void ft_printf(char *fmt, ...)
{
    va_list ap; /* points to each unnamed arg in turn */
    char *p;
    char *sval;
    int ival;
   // double dval;
    va_start(ap, fmt); /* make ap point to 1st unnamed arg */
    p = fmt;
    while (*p)
    {
        if (*p == '%')
        {
            switch (*++p)
            {
                case 'd':
                    ival = va_arg(ap, int);
                    ft_putnbr(ival);
                    break;
                case 's':
                    sval = va_arg(ap, char*);
                    ft_putstr(sval);
                    break;
                default:
                    ft_putchar(*p);
                    break;
            }
        }
        else
            ft_putchar(*p);
        p++;
    }
   va_end(ap); /* clean up when done */
}

int main()
{
    ft_printf("d = %d,c =  %c,string = %s",5,'a',"dfjknvkjdf");
   // printf("d = %d,c =  %c,str = %s,float = %f",5,'c',"dfkvjf",54.32);
}