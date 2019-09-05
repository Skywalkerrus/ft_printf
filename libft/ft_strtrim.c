/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:27:12 by bantario          #+#    #+#             */
/*   Updated: 2019/04/19 17:03:34 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*cell(const char *st)
{
	char		*opp;

	opp = (char *)malloc(sizeof(char) * ft_strlen(st));
	while (*st)
	{
		if (*st == '\x12' || *st == ' ' || *st == '\n' || *st == '\t')
			return (0);
		*opp++ = *st++;
	}
	return (opp);
}

static char		*ft_strcpy_mod(char *dst, const char *src, int i, int j)
{
	int			y;

	y = 0;
	while (j - i >= 0)
	{
		dst[y] = src[i];
		i++;
		y++;
	}
	dst[y] = '\0';
	return (dst);
}

static char		*ft_strnew_mod(size_t size)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		str[i] = 0;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s)
{
	char		*str;
	int			i;
	int			j;

	i = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	cell(s);
	while (s[i] && (s[i] == '\x12' || s[i] == ' '
				|| s[i] == '\n' || s[i] == '\t'))
		i++;
	while (j && (s[j] == ' ' || s[j] == '\x12'
				|| s[j] == '\n' || s[j] == '\t'))
		j--;
	if (j == 0)
	{
		str = ft_strnew_mod(1);
		return (str);
	}
	if ((str = ft_strnew(j - i + 1)) == NULL)
		return (NULL);
	str = ft_strcpy_mod(str, s, i, j);
	return (str);
}
