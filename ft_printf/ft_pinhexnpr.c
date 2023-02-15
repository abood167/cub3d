/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pinhexnpr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:29:18 by abin-saa          #+#    #+#             */
/*   Updated: 2022/06/07 12:24:49 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_npr(unsigned int n, char format)
{
	int	mod;

	mod = 0;
	if (n >= 16)
	{
		ft_print_hex_npr(n / 16, format);
	}
	mod = n % 16;
	if (mod >= 10)
	{
		if (format == 'x')
			ft_putchar(mod - 10 + 'a');
		if (format == 'X')
			ft_putchar(mod - 10 + 'A');
	}
	else if (mod < 10)
	{
		ft_putchar(mod + '0');
	}
}

// #include <stdio.h>

// int main()
// {
//     ft_print_hex_npr(16, 'x');
// }