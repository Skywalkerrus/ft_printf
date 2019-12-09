#include "../includes/ft_printf.h"

void		ft_display_padding(t_flags *flags, uintmax_t nb, int *size,
							   char *base)
{
	int			width;
	int			precision;

	if (flags->precision <= 0 && flags->width <= 0)
	{
		if (flags->type == 'p' && *size > 0)
			*size += 2;
		return ;
	}
	width = 0;
	precision = flags->precision - *size;
	*size = (flags->precision > *size) ? flags->precision : *size;
	while (flags->minus && width++ < precision)
		ft_write("0", 1, flags);
	if (flags->minus && flags->precision != -1)
		ft_putnbr_base_intmax_t_u(nb, base, ft_strlen(base), flags);
	width = 0;
	while (width++ < flags->width - (*size + (flags->type == 'p' ? 2 : 0)))
		ft_write((flags->zero && !flags->minus) ? "0" : " ", 1, flags);
	width = 0;
	while (!flags->minus && width++ < precision)
		ft_write("0", 1, flags);
	if (*size > 0 && flags->type == 'p')
		*size += 2;
}


int		ft_write_char(char c, t_flags *flags)
{
    return (ft_write(&c, 1, flags));
}

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