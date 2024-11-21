/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_and_putnbr_u.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:04:51 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/21 10:31:27 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		count;

	count = 0;
	if (nb == -2147483648)
	{
		count = ft_putstr("-2147483648");
		return (count);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		if (count == -1)
			return (-1);
		nb = nb * -1;
	}
	return (ft_putnbr_u(nb) + count);
}

int	ft_putnbr_u(unsigned int nb)
{
	char	x;
	int		count;
	int		check;

	count = 0;
	check = 0;
	if (nb > 9)
	{
		check = ft_putnbr_u(nb / 10);
		if (check == -1)
			return (-1);
		count += check;
		count += ft_putnbr_u(nb % 10);
	}
	else
	{
		x = nb + 48;
		check = ft_putchar(x);
		if (check == -1)
			return (-1);
		count += check;
	}
	return (count);
}
