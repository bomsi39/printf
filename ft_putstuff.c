/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:44:38 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/10 01:21:31 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_ret(char c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_putstr_ret(char *s)
{
	size_t		len;

	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[len] != '\0')
		len++;
	if (s)
		write(1, s, len);
	return (len);
}

int	digit(unsigned long long n, int base)
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

char	*ft_itoa_base(unsigned long long i, int base, char c)
{
	char		*asc;
	int			size;

	size = digit(i, base);
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
		len += ft_putstr_ret("0x");
	if (base == 10 && a == 's' && n < 0)
	{
		n *= -1;
		len += write(1, "-", 1);
	}
	str = ft_itoa_base(n, base, c);
	len += ft_putstr_ret(str);
	free(str);
	return (len);
}
