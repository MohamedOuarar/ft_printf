/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:18:27 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/21 10:58:34 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int num, int up, int low)
{
	char	*base_up;
	int		count;
	int		check;

	check = 0;
	base_up = "0123456789ABCDEF";
	count = 0;
	if (num < 16 && low)
		return (ft_adress(num, 0));
	else if (num < 16 && up)
	{
		check = ft_putchar(base_up[num]);
		count += check;
		if (check == -1)
			return (-1);
	}
	else
	{
		check = ft_hex(num / 16, up, low);
		if (check == -1)
			return (-1);
		count += check;
		count += ft_hex(num % 16, up, low);
	}
	return (count);
}

int	ft_adress(unsigned long long num, int ox)
{
	char	*base_low;
	int		count;
	int		check;

	check = 0;
	count = 0;
	base_low = "0123456789abcdef";
	while (ox == 1 && ox++)
		count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	if (num < 16)
	{
		check = ft_putchar(base_low[num]);
		count += check;
		if (check == -1)
			return (-1);
	}
	else
	{
		count += ft_adress(num / 16, ox);
		count += ft_adress(num % 16, ox);
	}
	return (count);
}
