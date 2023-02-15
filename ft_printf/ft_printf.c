/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 10:12:54 by abin-saa          #+#    #+#             */
/*   Updated: 2022/06/07 12:24:49 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkchar(int c)
{
	ft_putchar(c);
	return (1);
}

int	ft_checkunint(unsigned int numnum)
{
	int	num_chars;

	num_chars = 0;
	ft_putunsnbr(numnum);
	num_chars = ft_unscountdigt(numnum);
	return (num_chars);
}

int	ft_checkprint(va_list args, char format, int num_chars)
{
	if (format == 's')
		num_chars = ft_checkstr(va_arg(args, char *));
	if (format == 'd' || format == 'i')
		num_chars = ft_checkint(va_arg(args, int));
	if (format == 'c')
		num_chars = ft_checkchar(va_arg(args, int));
	if (format == '%')
		num_chars = ft_putchar('%');
	if (format == 'u')
		num_chars = ft_checkunint(va_arg(args, unsigned int));
	if (format == 'x' || format == 'X')
		num_chars = ft_checkhex(va_arg(args, unsigned int), format);
	if (format == 'p')
		num_chars = ft_checkptr(va_arg(args, void *));
	return (num_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		num_chars;

	va_start(args, format);
	num_chars = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			num_chars += ft_checkprint(args, format[i + 1], num_chars);
			i++;
		}
		else
			num_chars += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (num_chars);
}

// int main()
// {
// 	//     // ft_putstr("YOUR FUNCTION: ");

// 	//     // printf("\nORIGINAL FUNCTION: ");
// 	//     // printf("RET VAL == %d\n", ret);

// 	//     // printf("%d\n", ft_countdigt(-12));
// 	void *n;
// 	// int no = 23456;
// 	n = "NULL";
// 	int ret = ft_printf(" %s ", NULL);
// 	printf("RET == %d\n", ret);
// 	ret = printf(" %s ", NULL);
// 	printf("RET == %d\n", ret);
// 	ft_printf("%d%%%%x%u%s%s\n", 0, 0, 0, "lakeNULL");
// 	ft_printf("%%LIFE %x%dIS NIFITY %s\n", -1, 0, "lakeNULL");
// 	printf("%%LIFE %x%dIS NIFITY %s\n", -1, 0, "lakeNULL");
// 	   printf("%d\n", ft_contptr(85125252525));
// }