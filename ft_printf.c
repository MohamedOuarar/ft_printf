/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:01:24 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/21 11:14:43 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_symbel(const char *str, va_list argement)
{
	int	count;
	int	check;

	count = 0;
	check = for_x_p(str, argement);
	if (check != 0)
		return (check);
	check = for_d_i_u(str, argement);
	if (check != 0)
		return (check);
	check = for_s_c(str, argement);
	if (check != 0)
		return (check);
	return (count);
}

int	serche(const char *str, va_list argement)
{
	int		count_print;
	int		check;

	check = 0;
	count_print = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = get_symbel(str + 1, argement);
			if (check == -1)
				return (-1);
			count_print += check;
			str++;
		}
		else
		{
			check = write(1, str, 1);
			if (check == -1)
				return (-1);
			count_print += check;
		}
		str++;
	}
	return (count_print);
}

int	ft_printf(const char *str, ...)
{
	int		count_print;
	int		check;
	va_list	argement;

	check = 0;
	va_start(argement, str);
	count_print = 0;
	count_print = serche(str, argement);
	va_end(argement);
	return (count_print);
}
