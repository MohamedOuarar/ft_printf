/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:02:01 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/21 10:59:06 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_putnbr(int nb);
int	ft_putnbr_u(unsigned int nb);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_hex(unsigned int num, int up, int low);
int	ft_adress(unsigned long long num, int ox);
int	for_d_i_u(const char *str, va_list argement);
int	for_s_c(const char *str, va_list argement);
int	for_x_p(const char *str, va_list argement);

#endif