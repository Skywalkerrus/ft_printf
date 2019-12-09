#include "../includes/ft_printf.h"


uintmax_t	ft_get_nb_u(va_list args, t_flags flags)
{
	uintmax_t	nbr;

	nbr = va_arg(args, uintmax_t);
	if (flags.length_type == LENGTH_HH)
		nbr = (unsigned char)nbr;
	else if (flags.length_type == LENGTH_H)
		nbr = (unsigned short int)nbr;
	else if (flags.length_type == LENGTH_L)
		nbr = (unsigned long int)nbr;
	else if (flags.length_type == LENGTH_LL)
		nbr = (unsigned long long int)nbr;
	else if (flags.length_type == LENGTH_J)
		nbr = (uintmax_t)nbr;
	else if (flags.length_type == LENGTH_Z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

int print_o(va_list args, t_flags *flags)
{
	int size;
	int nb_size;
	uintmax_t nb;

	if (flags->precision != 0)
		flags->zero = 0;
	size = 0;
	nb = ft_get_nb_u(args, *flags);
	if (flags->precision >= 0 || nb > 0)
		ft_get_number_size_u(nb, 8, &size);
	if (flags->hash_key && (nb > 0 || flags->precision < 0))
		size += 1;
	nb_size = size;
	size = (flags->precision > size) ? flags->precision : size;
	if (flags->width && !flags->minus)
		size = ft_pad(flags, size);
	if (flags->hash_key && (nb > 0 || flags->precision < 0))
		ft_write("0", 1, flags);
	while (nb_size++ < flags->precision)
		ft_write("0", 1, flags);
	if (flags->precision >= 0 || nb > 0)
		ft_putnbr_base_intmax_t_u(nb, "01234567", 8, flags);
	if (flags->width && flags->minus)
		size = ft_pad(flags, size);
	return (size);
}



//void	Func(unsigned int n, t_node *list)
//{
//	if (n != 0)
//	{
//		Func(n / 8, list);
//		list->len++;
//	}
//	else
//		return;
//	ft_putnbr(n % 8);
//	return;
//}
//
//int	print_o(va_list ap, t_node *list)
//{
//	int oo;
//
//
//	oo = va_arg(ap, unsigned int);
//	if (oo == 0)
//	{
//		ft_putnbr(0);
//		list->len++;
//	}
//	Func(oo, list);
//	return (0);
//}