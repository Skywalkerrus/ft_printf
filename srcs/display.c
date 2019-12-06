#include "../includes/ft_printf.h"



int		ft_write_until_percentage(char **format, t_flags *flags)
{
    int	next;

    if (ft_strchr(*format, '%'))
        next = (int)(ft_strchr(*format, '%') - *format);
    else
        next = (int)ft_strlen(*format);
    ft_write(*format, next, flags);
    *format += next;
    return (next);
}


int	ft_pad(t_flags *flags, int size)
{
    int width;

    if (flags->width <= 0)
        return (size);
    width = 0;
    while (width++ < flags->width - size)
        ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
    return (size + width - 1);
}

int		ft_write(void *s, int size, t_flags *flags)
{
    int		i;
    char	*str;

    i = 0;
    str = s;
    while (i < size)
        flags->buffer[flags->bytes++] = str[i++];
    flags->total_bytes += size;
    return (size);
}