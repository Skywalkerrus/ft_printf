#include "./includes/ft_printf.h"
//#include "/libft/libft.h"
int main()
{
    ft_printf("%-10s is a string", "this");
    ft_putchar('\n');
    printf("%-10s is a string", "this");
    ft_putchar('\n');
    return (0);
}