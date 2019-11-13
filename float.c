#include <stdio.h>
#include "libft/libft.h"

//void reverse(char *str, int len)
//{
//    int j = len - 1;
//    int i = 0;
//    char tmp;
//
//    while(i < j)
//    {
//        tmp = str[i];
//        str[i] = str[j];
//        str[j] = tmp;
//        i++; j--;
//    }
//}

double	before_dot_ten(double nb)
{
    double mod;

    mod = 1;
    while((int)(nb) != 0)
    {
        mod = mod * 10;
        nb = nb / 10;
    }
    return(mod);
}

char	*float_to_str(double nb, char **s, int precission)
{
    char *str;
    int mod;
    int tmp;
    int j;
    int i;

    tmp = 0;
    i = 0;
    mod = (int)(before_dot_ten(nb));
    str = ft_memalloc(sizeof(char) * 100);
    while((int)(nb) != 0)
    {
        str[i++] = (char)((nb / mod) + '0');
        nb = nb - (int)(nb / mod) * mod;
        mod = mod /10;
    }
    s[i++] = '.';
    j = 0;
    while(j <= precission)
    {
        tmp = int(nb + 0.01);
        s[i++] = char(tmp + '0');
        nb = (nb- tmp) * 10;
    }
   // s[i--] = '\0';
    *s = str;

    return(*s);

}

int main()
{
    int size = 1;
   // printf("%f\n", before_dot_ten(11111.1));
   char *s = ft_memalloc(sizeof(char) * 100);
   printf("%s\n",float_to_str(10.3456,&s,2));
    return(0);
}