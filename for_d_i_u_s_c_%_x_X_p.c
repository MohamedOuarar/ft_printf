/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_d_i_u_s_c_%_x_X_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:59:04 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/21 10:40:52 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_d_i_u(const char *str, va_list argement)
{
	int	count;

	count = 0;
	if (*str == 'd' || *str == 'i')
	{
		count = ft_putnbr(va_arg(argement, int));
		if (count == -1)
			return (-1);
	}
	else if (*str == 'u')
	{
		count = ft_putnbr_u(va_arg(argement, unsigned int));
		if (count == -1)
			return (-1);
	}
	return (count);
}

int	for_s_c(const char *str, va_list argement)
{
	int	count;

	count = 0;
	if (*str == 's')
	{
		count = ft_putstr(va_arg(argement, char *));
		if (count == -1)
			return (-1);
	}
	else if (*str == 'c')
	{
		count = ft_putchar(va_arg(argement, int));
		if (count == -1)
			return (-1);
	}
	if (*str == '%')
	{
		count = ft_putchar('%');
		if (count == -1)
			return (-1);
	}
	return (count);
}

int	for_x_p(const char *str, va_list argement)
{
	int	count;

	count = 0;
	if (*str == 'x')
	{
		count = ft_hex(va_arg(argement, unsigned int), 0, 1);
		if (count == -1)
			return (-1);
	}
	else if (*str == 'X')
	{
		count = ft_hex(va_arg(argement, unsigned int), 1, 0);
		if (count == -1)
			return (-1);
	}
	else if (*str == 'p')
	{
		count = ft_adress(va_arg(argement, unsigned long long), 1);
		if (count == -1)
			return (-1);
	}
	return (count);
}
