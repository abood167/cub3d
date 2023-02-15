/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:40:59 by abin-saa          #+#    #+#             */
/*   Updated: 2022/06/07 12:24:49 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prinptr(void *p)
{
	int				mod;
	unsigned long	n;

	mod = 0;
	n = (unsigned long)p;
	if (n >= 16)
	{
		ft_prinptr((void *)(n / 16));
	}
	mod = n % 16;
	if (mod >= 10)
	{
		ft_putchar(mod - 10 + 'a');
	}
	else if (mod < 10)
	{
		ft_putchar(mod + '0');
	}
}
