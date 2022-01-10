/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:50:03 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/10 01:23:54 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char c, va_list *arg, int *len)
{
	if (c == 'c')
		*len += ft_putchar_ret(va_arg(*arg, int));
	if (c == 's')
		*len += ft_putstr_ret(va_arg(*arg, char *));
	if (c == 'd' || c == 'i')
		*len += ft_putascii(va_arg(*arg, signed int), B_10, DEC, SIG);
	if (c == 'u')
		*len += ft_putascii(va_arg(*arg, unsigned int), B_10, DEC, NO_FLAG);
	if (c == 'p')
		*len += ft_putascii(va_arg(*arg, unsigned long long), B_16, LHEX, PTR);
	if (c == 'x')
		*len += ft_putascii(va_arg(*arg, unsigned int), B_16, LHEX, NO_FLAG);
	if (c == 'X')
		*len += ft_putascii(va_arg(*arg, unsigned int), B_16, UHEX, NO_FLAG);
	if (c == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(str[i], &arg, &len);
			i++;
		}
		else
			len += ft_putchar_ret(str[i++]);
	}
	return (len);
}
