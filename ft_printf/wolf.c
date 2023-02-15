/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:26:00 by abin-saa          #+#    #+#             */
/*   Updated: 2022/06/07 12:24:49 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkstr(char *str)
{
	int	num_chars;

	num_chars = 0;
	ft_putstr(str);
	if (str == NULL)
		num_chars += 6;
	else
	{
		num_chars += ft_strlen(str);
	}
	return (num_chars);
}

int	ft_checkint(int num)
{
	int	num_chars;

	num_chars = 0;
	ft_putnbr(num);
	num_chars += ft_countdigt(num);
	return (num_chars);
}

int	ft_checkptr(void *pp)
{
	int	num_chars;

	num_chars = 0;
	ft_putstr("0x");
	if (pp == 0)
	{
		num_chars += 3;
		ft_putstr("0");
	}
	else
	{
		ft_prinptr(pp);
		num_chars += 2;
		num_chars += ft_contptr((unsigned long)pp);
	}
	return (num_chars);
}

int	ft_checkhex(unsigned int nu, char format)
{
	int	num_chars;

	num_chars = 0;
	ft_print_hex_npr(nu, format);
	num_chars += ft_conthex(nu);
	return (num_chars);
}
