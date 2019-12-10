/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:36:21 by bantario          #+#    #+#             */
/*   Updated: 2019/10/18 15:00:20 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H


#include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

// scywalkers
typedef unsigned long long int size_b;
typedef int (*func)();


//defines
# define BUFF_SIZE 1024
# define STDOUT 1
# define ARGS_COUNT 21
# define LENGTH_HH 1
# define LENGTH_H 2
# define LENGTH_LL 4
# define LENGTH_L 3
# define LENGTH_J 6
# define LENGTH_Z 5

// structurs

typedef struct	s_flags
{
    int			hash_key;
    int			zero;
    int			minus;
    int			plus;
    int			space;
    int			width;
    int			precision;
    int			length_type;
    char		type;
    char		buffer[BUFF_SIZE];
    int			bytes;
    int			total_bytes;
}				t_flags;


typedef struct	s_types
{
    char		name;
    int			(*f)();
}				t_types;

typedef struct s_node
{
    int len;
    int	when_pr;
    int w_p2;
}   t_node;


//prototypes!!!!!!!!

//float
double	part_int_ten(double n, int *size);
void        int_part(double *n, char **str, double mod, int *i);
void        float_part(double n, char **str, int *i, int rigor);
int     float_to_str(double n, char **s, int rigor);
int     print_f(va_list args, t_flags *flags);


//write
int		ft_write(void *s, int size, t_flags *flags);
int     ft_pad(t_flags *flags, int size);
int		ft_write_char(char c, t_flags *flags);
int		ft_write_until_percentage(char **format, t_flags *flags);


//parser
void	ft_init_flags(t_flags *flags);
int		ft_handle_flags(char **str, t_flags *flags);
int		ft_handle_width(char **str, t_flags *flags, va_list args);
int		ft_handle_precision(char **str, t_flags *flags, va_list args);
void	ft_edit_length_type(char **str, t_flags *flags, int flag_type, int size);
int		ft_handle_length(char **str, t_flags *flags);
int	ft_call_type(char **str, va_list args, t_flags *flags);
uintmax_t	ft_get_nb_u(va_list args, t_flags flags);
int	ft_handle(char **str, va_list args, t_flags *flags);
int ft_printf(char *format, ...);
void	ft_putnbr_base_intmax_t_u(uintmax_t nbr, char *str,
								  uintmax_t str_length, t_flags *flags);
void	ft_get_number_size_u(uintmax_t nbr, uintmax_t str_length, int *size);
int			ft_handle_hash_key(uintmax_t nb, t_flags *flags, int *size,
								  char *hash_key_content);
void		ft_display_padding(t_flags *flags, uintmax_t nb, int *size,
							   char *base);


//functions scywalkers

int	print_d(va_list ap, t_flags *flags);
int	print_str(va_list ap, t_flags *flags);
int	print_symb(va_list args, t_flags *flags);
int	print_o(va_list ap, t_flags *flags);
int	print_u(va_list ap, t_flags *flags);
int	print_x(va_list ap, t_flags *flags);
int	print_procent(va_list args, t_flags *flags);
int	print_X(va_list ap, t_flags *flags);

//
//void	print_ld(char *hu, va_list ap, t_node *list);
//void	print_long_l(char *hu, va_list ap, t_node *list);
//void	print_llu(char *hu, va_list ap, t_node *list);
//void	Func(unsigned int n, t_node *list);
//void	print_lu(char *hu, va_list ap, t_node *list);
//void	print_hu(char *hu, va_list ap, t_node *list);
//void	print_hi(char *hu, va_list ap, t_node *list);
//void	print_hd(char *hu, va_list ap, t_node *list);
//void	print_lli(char *hu, va_list ap, t_node *list);
//void	Func2_next(long long n, t_node *list);
//void	Func2(long long n, t_node *list);
//void	Func3_next(long long int n, t_node *list);
//void    Func3(long long int n, t_node *list);
//void	one_proc(char *hu, t_node *list);
//void	cast_func(char *hu, va_list ap, func *mass, t_node *list);


#endif