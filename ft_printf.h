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
//

// structurs
# define BUFF_SIZE 1024

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




#endif
