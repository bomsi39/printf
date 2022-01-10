/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:55:34 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/10 01:28:13 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define SIG 's'
# define PTR 'p'
# define LHEX 'a'
# define UHEX 'A'
# define DEC 0
# define B_10 10
# define B_16 16
# define NO_FLAG 0

int			ft_printf(const char *str, ...);
void		ft_format(char c, va_list *arg, int *len);
int			ft_putchar_ret(char c);
size_t		ft_putstr_ret(char *s);
int			ft_putascii(ssize_t n, int base, char c, char a);
char		*ft_itoa_base(unsigned long long n, int base, char c);
int			digit(unsigned long long n, int base);

#endif