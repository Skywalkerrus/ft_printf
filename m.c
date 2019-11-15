#include <stdio.h>
#include "libft/libft.h"

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
//}

// C program for implementation of ftoa()
#include <stdio.h>
#include <math.h>

// reverses a string 'str' of length 'len'
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

// Converts a given integer x to string str[].  d is the number
// of digits required in output. If d is more than the number
// of digits in x, then 0s are added at the beginning.
int intToStr(int x, char *str, int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x % 10) + 48;
        x = x/10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
    str[i] = '\0';
    reverse(str, i);
    return (i);
}

// Converts a floating point number to string.
void ftoa(float n, char *res, int afterpoint)
{
    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, res+ i + 1, afterpoint);
    }
}

int main()
{
    char *res = ft_memalloc(sizeof(int) * 1000);
    float n = 233.127;//4564564564564564564564;
    ftoa(n, res, 3);
    printf("%s\n", res);
    printf("%.3f\n",n);
    printf("%d\n",(int)(345.564));
    //printf("%d\n",8546);
   // ft_putstr("res\n");
    return 0;
}

