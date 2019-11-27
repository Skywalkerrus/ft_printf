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

int        int_part(double n, char *s, double mod, int i)
{

    int     rank;

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
	double mod;
	int minus;
    int size;

    i = 0;
    size = 1;
    minus = 0;
	if (n < 0)
    {
	    n = -n;
	    minus = 1;
        str[i++] = '-';
    }
	mod = part_int_ten(n, size);
	//if(minus)
	  //  str[i++] = '-';
	i = int_part(n, str, mod, i);
	i = float_part(n, str, i, rigor);
	str[i++] = '\0';
	ft_putstr(str);
}

int main() {
	char *str = (char *)malloc(sizeof(int) *1000);

	float_to_str(275.1234,str,7);
	ft_putchar('\n');
	printf("%+0.6f\n",-275.1234);
	return(0);
}
