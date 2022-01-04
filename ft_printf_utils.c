/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:44:38 by dfranke           #+#    #+#             */
/*   Updated: 2021/12/31 10:46:20 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

int	ft_putchar_ret(char c)
{
	write (1, &c, 1);
	return (1);
}

size_t	ft_putstr_ret(char *s)
{
	size_t		len;

	if (!s)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	if (s)
		write(1, s, len);
	return (len);
}
