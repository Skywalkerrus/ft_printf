#include <stdio.h>
#include "libft/libft.h"

double	before_dot_ten(double n)// int *size)
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



int main()
{
    //int size = 1;
    printf("%f\n", before_dot_ten(11111.1));
   //char *s = ft_memalloc(sizeof(char) * 100);
  // printf("%s\n",float_to_str(10.3456,&s,2));
    return(0);
}