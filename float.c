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
        (*size)++;
    }
    return(mod);
}

void        int_part(double *n, char **str, double mod, int *i)
{
    //int     rank;
    char *s;

    s = *str;
    while ((int)*n != 0)
    {
       // rank = (int)(*n / mod);
        s[(*i)++] = (char)((*n / mod) + '0');
        *n -= (int)(*n / mod) * mod;
        mod = mod / 10;
    }
}

void        float_part(double n, char **str, int *i, int rigor)
{
    int j;
    int tmp;
    char *s;


    n = (n - (int)n) * 10;
    j = 0;
    s = *str;
    s[(*i)++] = '.';
    while(j++ < rigor)
    {
        if ((int)n == 0) {
            s[(*i)++] = '0';
            continue;
        }
		tmp = ((int)n != 9) ? (int)(n + 0.01) : (int)n;
        s[(*i)++] = (char)(tmp + '0');
        n = (n - tmp) * 10;
    }
}

int     float_to_str(double n, char **s, int rigor)
{
	int i;
	double mod;
    int size;
    char *str;
    int minus;

    i = 0;
    size = 1;
    minus = 0;
	if (n < 0 && size++ &&(minus = 1) == 1)
	    n = -n;
	mod = part_int_ten(n, &size);
	size += rigor;
	str = ft_memalloc(sizeof(char) * (size + 1));
	if (minus)
	    str[i++] = '-';
	int_part(&n, &str, mod, &i);
	float_part(n, &str, &i, rigor);
	str[--i] = '\0';
	*s = str;
    return (size);
}



//
//int main()
//{
//
//	float_to_str(275.1234,&str,7);
//	ft_putchar('\n');
//	printf("%.7f\n",275.1234);
//	return(0);
//}
