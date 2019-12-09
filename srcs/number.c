#include "../includes/ft_printf.h"


int			ft_handle_hash_key(uintmax_t nb, t_flags *flags, int *size,
								  char *hash_key_content)
{
	int precision;

	precision = 0;
	if (nb == 0 && flags->type != 'p')
		flags->hash_key = 0;
	if (flags->hash_key && (!flags->width || flags->minus || flags->zero ||
							(precision = flags->precision > *size)))
		ft_write(hash_key_content, (int)ft_strlen(hash_key_content), flags);
	if (flags->hash_key && ((flags->width) && !precision) && flags->type != 'p')
		*size += (int)ft_strlen(hash_key_content);
	return (precision);
}

void	ft_putnbr_base_intmax_t_u(uintmax_t nbr, char *str,
                                  uintmax_t str_length, t_flags *flags)
{
    if (nbr >= str_length)
        ft_putnbr_base_intmax_t_u(nbr / str_length, str, str_length, flags);
    ft_write_char(str[nbr % str_length], flags);
}

intmax_t	ft_get_nb(va_list args, t_flags flags)
{
    intmax_t	nbr;

    nbr = va_arg(args, intmax_t);
    if (flags.length_type == LENGTH_HH)
        nbr = (char)nbr;
    else if (flags.length_type == LENGTH_H)
        nbr = (short int)nbr;
    else if (flags.length_type == LENGTH_L)
        nbr = (long int)nbr;
    else if (flags.length_type == LENGTH_LL)
        nbr = (long long int)nbr;
    else if (flags.length_type == LENGTH_J)
        nbr = (intmax_t)nbr;
    else if (flags.length_type == LENGTH_Z)
        nbr = (size_t)nbr;
    else
        nbr = (int)nbr;
    return (nbr);
}

void		ft_display_sign(intmax_t nb, t_flags *flags)
{
    if (nb < 0)
        ft_write("-", 1, flags);
    if (flags->plus && nb >= 0)
        ft_write("+", 1, flags);
    else if (flags->space && nb >= 0)
        ft_write(" ", 1, flags);
}

int			ft_display_d(t_flags *flags, int size, int precision, intmax_t nb) {
    int width_size;
    int width;

    width = 0;
    width_size = 0;
    if (!flags->minus) {
        if (flags->width && flags->zero)
            ft_display_sign(nb, flags);
        width_size = ft_pad(flags, size) - size;
    }
    if ((flags->width && (flags->minus || !flags->zero)) || !flags->width)
        ft_display_sign(nb, flags);
    while (width++ < precision)
        ft_write("0", 1, flags);
    if (size > 0)
        ft_putnbr_base_intmax_t_u((uintmax_t) (nb < 0 ? -nb : nb), "0123456789",
                                  10, flags);
    return (size + width_size);
}

void	ft_get_number_size_u(uintmax_t nbr, uintmax_t str_length, int *size)
{
    *size += 1;
    while (nbr >= str_length)
    {
        nbr /= str_length;
        *size += 1;
    }
}


int	print_d(va_list ap, t_flags *flags)
{
    intmax_t		nb;
    int     precision;
    int     size;

    size = 0;
    if (flags->precision != 0)
        flags->zero = 0;
    nb = ft_get_nb(ap, *flags);
    ft_get_number_size_u((uintmax_t)(nb < 0 ? -nb : nb),10,&size);
    precision = flags->precision - size;
    size = (flags->precision > size) ? flags->precision : size;
    size = (flags->precision == -1 && nb == 0) ? 0 : size;
    size += (nb >= 0 && (flags->plus || flags->space));
    if (nb < 0)
        size += 1;
    size = ft_display_d(flags,size,precision,nb);
    size = (flags->minus) ? ft_pad(flags,size):size;
    return (size);
}
