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
# include "libft/libft.h"

// scywalkers
typedef unsigned long long int size_b;
typedef void (*func)();


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




//prototypes
double	part_int_ten(double n, int *size);
void        int_part(double *n, char **str, double mod, int *i);
void        float_part(double n, char **str, int *i, int rigor);
int     float_to_str(double n, char **s, int rigor);




#endif