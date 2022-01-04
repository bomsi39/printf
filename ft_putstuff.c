/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:16:06 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/04 16:29:27 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	digit(ssize_t n, int base)
{
	int		i;

	i = 0;
	if (n < 0 || n == 0)
	{
		n *= -1;
		i++;
	}
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(ssize_t i, int base, char c)
{
	char		*asc;
	int			size;

	size = digit(i, base);
	asc = malloc(size + 1);
	if (!asc)
		return (0);
	if (i < 0)
	{
		i *= -1;
		asc[0] = '-';
	}
	asc[size] = '\0';
	if (i == 0)
		asc[0] = '0';
	while (0 < i)
	{
		if ((i % base) < 10)
			asc[size-- - 1] = (i % base) + 48;
		else if (base == 16 && (10 <= i % 16))
			asc[size-- - 1] = (i % 16) - 10 + c;
	i /= base;
	}
	return (asc);
}

int	digitp(unsigned long long n, int base)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoap_base(unsigned long long i, int base, char c)
{
	char		*asc;
	int			size;

	size = digitp(i, base);
	asc = malloc(size + 1);
	if (!asc)
		return (0);
	asc[size] = '\0';
	if (i == 0)
		asc[0] = '0';
	while (0 < i)
	{
		if ((i % base) < 10)
			asc[size-- - 1] = (i % base) + 48;
		else if (base == 16 && (10 <= i % 16))
			asc[size-- - 1] = (i % 16) - 10 + c;
	i /= base;
	}
	return (asc);
}

int	ft_putascii(ssize_t n, int base, char c, char a)
{
	char	*str;
	int		len;

	len = 0;
	if (a == 'p')
	{
		len += ft_putstr_ret("0x");
		str = ft_itoap_base(n, base, c);
	}
	else
		str = ft_itoa_base(n, base, c);
	len += ft_putstr_ret(str);
	free(str);
	return (len);
}
