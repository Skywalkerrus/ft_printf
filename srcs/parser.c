/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglinda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:01:21 by bglinda           #+#    #+#             */
/*   Updated: 2019/12/02 17:01:25 by bglinda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"



void	edit_type(char **str, t_flags *flags, int flag_type, int size)
{
    *str += size;
    if (flags->length_type < flag_type)
        flags->length_type = flag_type;
}

void	init_flags(t_flags *flags)
{
    flags->precision = 0;
    flags->minus = 0;
    flags->plus = 0;
    flags->hash_key = 0;
    flags->zero = 0;
    flags->space = 0;
    flags->width = 0;
    flags->length_type = 0;
}

t_types	g_types[COUNT] = {
        {'d', print_d},
		{'i', print_d},
        {'f', print_f},
        {'s', print_str},
        {'c', print_symb},
        {'o', print_o},
        {'u', print_u},
        {'U', print_U},
        {'x', print_x},
        {'X', print_X},
        {'%', print_procent},
        {'p', print_p}
};

int	call_type(char **str, va_list args, t_flags *flags)
{
    int arg;
    int size;

    arg = 0;
    while (arg < COUNT)
    {
        if (**str == g_types[arg].type)
        {
            *str += 1;
            flags->type = g_types[arg].type;
            return (g_types[arg].f(args, flags));
        }
        arg++;
    }
    size = 1;
    if (!flags->minus)
        size = pad(flags, size);
    display(*str, 1, flags);
    if (flags->minus)
        size = pad(flags, size);
    *str += 1;
    return (size);
}

int	parser(char **str, va_list args, t_flags *flags)
{
    int			found;

    init_flags(flags);
    while (**str)
    {
        found = 0;
        while (define_length(str, flags) || define_flags(str, flags) ||
               define_width(str, flags, args) || define_precision(str, flags, args))
            found = 1;
        if (ft_isalpha(**str) || **str == '%')
            return (call_type(str, args, flags));
        else if (!*(*str + 1) || !found)
            return (0);
    }
    return (0);
}






