#include "../includes/ft_printf.h"

int			print_base(va_list args, t_flags *flags, char *base,
						 char *hash_key_content)
{
	int			size;
	uintmax_t	nb;
	int			precision;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = ft_get_nb_u(args, *flags);
	ft_get_number_size_u(nb, ft_strlen(base), &size);
	precision = ft_handle_hash_key(nb, flags, &size, hash_key_content);
	if (flags->precision == -1 && nb == 0)
		size = 0;
	ft_display_padding(flags, nb, &size, base);
	if (flags->hash_key && flags->width && !flags->minus && !flags->zero &&
		!precision)
		ft_write(hash_key_content, (int)ft_strlen(hash_key_content), flags);
	if ((!flags->width || !flags->minus) && size > 0)
		ft_putnbr_base_intmax_t_u(nb, base, ft_strlen(base), flags);
	if (flags->hash_key && size > 0 && ((!flags->width || flags->minus) ||
										precision) && flags->type != 'p')
		size += (int)ft_strlen(hash_key_content);
	if (size == 0 && flags->type == 'p')
		size = 2;
	return (flags->width - size > 0 ? flags->width : size);
}

int print_u(va_list ap, t_flags *flags)
{
	return (print_base(ap, flags, "0123456789", NULL));
}


int print_U(va_list ap, t_flags *flags)
{
    flags->length_type = LENGTH_L;
    return (print_u(ap, flags));
}

int print_x(va_list ap, t_flags *flags)
{
	return (print_base(ap,flags,"0123456789abcdef","0x"));
}


int print_X(va_list ap, t_flags *flags)
{
	return (print_base(ap,flags,"0123456789ABCDEF","0X"));
}