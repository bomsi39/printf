/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfranke <dfranke@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:55:34 by dfranke           #+#    #+#             */
/*   Updated: 2022/01/04 12:01:25 by dfranke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *s);
int			ft_putchar_ret(char c);
int			digitp(unsigned long long n, int base);
char		*ft_itoap_base(unsigned long long n, int base, char c);
int			digit(ssize_t n, int base);
char		*ft_itoa_base(ssize_t n, int base, char c);
int			ft_putaddy(unsigned long long n);
int			ft_printf(const char *str, ...);
size_t		ft_putstr_ret(char *s);
int			ft_putascii(ssize_t n, int base, char c, char a);

#endif