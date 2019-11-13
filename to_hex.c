/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantario <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:56:20 by bantario          #+#    #+#             */
/*   Updated: 2019/11/13 19:31:22 by bantario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int pow_(int num, int exp)
{
	int i;

	i = 0;
    if (exp == 0) {
        return 1;
    } if (exp > 0) {
        int result = 1;
    	while (i < exp)
		{
			result *= num;
			++i;
		}
        return result;
    }
    return -1;
}

unsigned int char2int_(char chr)
{
    if (chr >= '0' && chr <= '9')
        return chr - '0';
    else if (chr >= 'A' && chr <= 'F')
        return chr - 'A' + 10;
    else if (chr >= 'a' && chr <= 'f')
        return chr - 'a' + 10; 
    return -1;
}

int hex2dec_(const char *hex, int size)
{
    int dec = 0;
	int j;
	int i;

	j = 0;
	i = size - 1;
	while (j < size)
	{
		if (hex[j] == 'x')
		{
			++j;
			--i;
		}
		dec += char2int_(hex[j]) * pow_(16, i);
	++j;
	--i;
	}
    return dec;
}

// Проверка строки на соответствию формата десятичного числа
int is_valid_hex(const char *hex, unsigned int size)
{
    int i;

	i = 0;
	while (i < size)
	{
		if (!((hex[i] >= '0' && hex[i] <= '9')
					|| (hex[i] >= 'a' && hex[i] <= 'z')
					|| (hex[i] >= 'A' && hex[i] <= 'z')))
			return (0);
	}
    return 1;
}

int main(int argc, char *argv[])
{
	char *hex;

	hex = (char *)malloc(sizeof(char) * 100);
    if (argc == 2) {
        hex = argv[1];
    } else {
		return (0);
    }

    if (!is_valid_hex(hex, ft_strlen(hex))) {
        return 1;
    }
    int dec = hex2dec_(hex, ft_strlen(hex));

    printf("do: %d\n", dec);

    return 0;
}
