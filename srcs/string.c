#include "../includes/ft_printf.h"

int	print_str(va_list ap,t_flags *flags)
{
    char	*str;
    int     size;

    str = va_arg(ap, char*);
    if (!str || str == NULL)
    {
        size = 6;
       // ft_write("(null)",size,flags);
    }
    else
        size = ft_strlen(str);
    size = (flags->precision == -1) ? 0 : size;
    if (flags->precision > 0 && flags->precision < size && size > 0)
        size = size - (size - flags->precision);
    if (flags->width)
    {
        if (flags->minus)
            ft_write(str, size, flags);
        ft_pad(flags, size);
    }
    if (!flags->width || !flags->minus)
        ft_write((str) ? str : "(null)", size, flags);
    if (flags->width - size > 0)
        return (size + flags->width -size);
    else
        return (size);
}

int	print_symb(va_list args, t_flags *flags)
{
    int	c;
    int	width;

    c = va_arg(args, int);
    width = 0;
    if (flags->width)
    {
        if (flags->minus)
            ft_write(&c, 1, flags);
        while (width++ < flags->width - 1)
            ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
    }
    if (!flags->width || !flags->minus)
        ft_write(&c, 1, flags);
    return ((flags->width) ? width : 1);
}

int	print_procent(va_list args, t_flags *flags)
{
    int		width;

    (void)args;
    if (flags->width)
    {
        if (flags->minus)
            ft_write("%", 1, flags);
        width = 0;
        while (width++ < flags->width - 1)
            ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
    }
    if (!flags->width || !flags->minus)
        ft_write("%", 1, flags);
    return ((flags->width) ? flags->width : 1);
}

int	print_p(va_list args, t_flags *flags)
{
    flags->length_type = LENGTH_L;
    flags->hash_key = 1;
    return (print_x(args, flags));
}

