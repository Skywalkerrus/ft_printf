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


void	ft_init_flags(t_flags *flags)
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


int		ft_handle_flags(char **str, t_flags *flags)
{
    if (*(*str) == '-')
        flags->minus = 1;
    else if (*(*str) == '+')
        flags->plus = 1;
    else if (*(*str) == ' ')
        flags->space = 1;
    else if (*(*str) == '0')
        flags->zero = 1;
    else if (*(*str) == '#')
        flags->hash_key = 1;
    else
        return (0);
    (*str)++;
    return (1);
}

int		ft_handle_width(char **str, t_flags *flags, va_list args)
{
    int width;

    if ((width = ft_atoi(*str)) > 0 || **str == '*')
    {
        if (**str == '*')
        {
            width = va_arg(args, int);
            if (width < 0)
                flags->minus = 1;
            flags->width = (width < 0 ? width * -1 : width);
            width = 1;
        }
        else
            flags->width = width;
        while (width > 0 && (*str += 1))
            width /= 10;
        return (1);
    }
    return (0);
}

int		ft_handle_precision(char **str, t_flags *flags, va_list args)
{
    int precision;

    if (**str == '.')
    {
        *str += 1;
        if (!ft_isdigit(**str) && **str != '*')
        {
            flags->precision = -1;
            return (1);
        }
        precision = (**str == '*') ? va_arg(args, int) : ft_atoi(*str);
        flags->precision = (precision == 0 ? -1 : precision);
        if (flags->precision < 0 && flags->precision != -1)
            flags->precision = 0;
        if (**str == '*')
            precision = 1;
        else if (precision == 0)
            *str += 1;
        while (precision > 0 && (*str = *str + 1))
            precision /= 10;
        return (1);
    }
    return (0);
}


void	ft_edit_length_type(char **str, t_flags *flags, int flag_type, int size)
{
    *str += size;
    if (flags->length_type < flag_type)
        flags->length_type = flag_type;
}

int		ft_handle_length(char **str, t_flags *flags)
{
    if (**str == 'h' && *(*str + 1) == 'h')
        ft_edit_length_type(str, flags, LENGTH_HH, 2);
    else if (**str == 'h')
        ft_edit_length_type(str, flags, LENGTH_H, 1);
    else if (**str == 'l' && *(*str + 1) == 'l')
        ft_edit_length_type(str, flags, LENGTH_LL, 2);
    else if (**str == 'l')
        ft_edit_length_type(str, flags, LENGTH_L, 1);
    else if (**str == 'j')
        ft_edit_length_type(str, flags, LENGTH_J, 1);
    else if (**str == 'z')
        ft_edit_length_type(str, flags, LENGTH_Z, 1);
    else if (**str == 'L')
        ft_edit_length_type(str, flags, LENGTH_L_UP, 1);
    else
        return (0);
    return (1);
}


t_types	g_types[ARGS_COUNT] = {
        {'d', print_d},
		{'i', print_d},
        {'f', print_f},
        {'s', print_str},
        {'c', print_symb},
        {'o', print_o},
        {'u',print_u},
        {'U',print_U},
        {'x',print_x},
        {'X',print_X},
        {'%',print_procent},
        {'p',print_p}
};

int	ft_call_type(char **str, va_list args, t_flags *flags)
{
    int arg;
    int size;
//    t_node *list;
//
//    list = (t_node *)malloc(sizeof(t_node));
    arg = 0;
    while (arg < ARGS_COUNT)
    {
        if (**str == g_types[arg].name)
        {
            *str += 1;
            flags->type = g_types[arg].name;
            return (g_types[arg].f(args, flags));
        }
        arg++;
    }
    size = 1;
    if (!flags->minus)
        size = ft_pad(flags, size);
    ft_write(*str, 1, flags);
    if (flags->minus)
        size = ft_pad(flags, size);
    *str += 1;
//    free(list);
    return (size);
}

int	ft_handle(char **str, va_list args, t_flags *flags)
{
    int			flags_found;

    ft_init_flags(flags);
    while (**str)
    {
        flags_found = 0;
        while (ft_handle_length(str, flags) ||
               ft_handle_flags(str, flags) ||
               ft_handle_width(str, flags, args) ||
               ft_handle_precision(str, flags, args))
            flags_found = 1;
        if (ft_isalpha(**str) || **str == '%')
            return (ft_call_type(str, args, flags));
        else if (!*(*str + 1) || !flags_found)
            return (0);
    }
    return (0);
}




int ft_printf(char *format, ...)
{
    t_flags flags;
    int bytes;
    va_list args;
    char *str;

    bytes = 0;
    flags.bytes = 0;
    flags.total_bytes = 0;
    va_start(args,format);
    str = (char *)format;
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            bytes += ft_handle(&str, args, &flags);
        }
        else
            bytes += ft_write_until_percentage(&str, &flags);
    }
    va_end(args);
    if (flags.bytes > 0)
        write(1, flags.buffer, (size_t)flags.bytes);
    return (bytes);
}


//int			ft_printf(char *hu, ...)
//{
//    func *mass;
//    va_list ap;
//    t_node  *list;
//
//    list = (t_node *)malloc(sizeof(t_node));
//    list->len = 0;
//    mass = (void *) malloc(sizeof(void) * 250);
//    va_start(ap, hu);
//    mass[0] = fundament;
//    mass[0](mass);
//    while(*hu)
//    {
//        if (*hu != '%')
//        {
//            ft_putchar(*hu);
//            list->len++;
//        }
//        else if (*hu == '%')
//        {
//            hu++;
//            mass[4](hu, ap, mass, list);
//            if (*hu == 'l' || *hu == 'h')
//            {
//                hu++;
//                if (*hu == 'u' || *hu == 'i' || *hu == 'x')
//                    hu--;
//                if (*hu != 'd')
//                    hu++;
//            }
//        }
//        hu++;
//    }
//    free(mass);
//    va_end(ap);
//    return(list->len);
//}


//int main()
//{
//    //int bytes;
//
//    printf("%0 d\n", -42);
//    ft_printf("%0 d\n", -42);
//
//    return (0);
//}

