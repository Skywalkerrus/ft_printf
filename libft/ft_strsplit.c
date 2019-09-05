/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:55:06 by bantario          #+#    #+#             */
/*   Updated: 2019/04/22 19:12:29 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strnew_mod(size_t size, char **arr, int y)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
	{
		while (y--)
			free(arr[y]);
		arr = NULL;
		free(arr);
		return (NULL);
	}
	return (str);
}

static int			c_sy(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (*s == c)
	{
		s++;
		i++;
	}
	while (*s != c && *s != '\0')
	{
		j++;
		s++;
	}
	return (j - i);
}

static int			c_w(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char			**ft_strnew_dv(size_t size)
{
	char			**str;
	unsigned int	i;

	i = 0;
	str = (char **)malloc(sizeof(char*) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = NULL;
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*wd;
	int		i;
	int		y;
	int		h;

	y = 0;
	if (s == NULL)
		return (NULL);
	h = c_w(s, c);
	arr = ft_strnew_dv(c_w(s, c));
	while (h--)
	{
		i = 0;
		while (*s == c)
			s++;
		if (!(wd = ft_strnew_mod(c_sy(s, c), arr, y)))
			return (NULL);
		while (*s != c && *s != '\0')
			wd[i++] = *s++;
		wd[i++] = '\0';
		arr[y++] = wd;
	}
	return (arr);
}
