#include "../includes/ft_printf.h"

int	print_str(va_list ap,t_flags *flags)
{
    char	*str;
    int     size;

    str = va_arg(ap, char*);
    if (!str)
    {
        size = 6;
        ft_write("(null)",size,flags);
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
    if (flags->width - size > 0)
        return (size + flags->width -size);
    else
        return (size);
}

