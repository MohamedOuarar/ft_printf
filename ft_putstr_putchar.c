/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarar <mouarar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:17:04 by mouarar           #+#    #+#             */
/*   Updated: 2024/11/21 10:17:48 by mouarar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;
	int	check;

	count = 0;
	i = 0;
	check = 0;
	if (!str)
	{
		count = ft_putstr("(null)");
		return (count);
	}
	while (str[i])
	{
		check = ft_putchar(str[i]);
		if (check == -1)
			return (-1);
		count += check;
		i++;
	}
	return (count);
}
