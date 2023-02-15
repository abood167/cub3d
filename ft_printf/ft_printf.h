/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:34:55 by abin-saa          #+#    #+#             */
/*   Updated: 2022/07/27 13:03:35 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_countdigt(int n);
void	ft_putstr(const char *s);
size_t	ft_strlen(const char *s);
int		ft_unscountdigt(unsigned int n);
void	ft_putunsnbr(unsigned int unnb);
void	ft_print_hex_npr(unsigned int n, char format);
void	ft_prinptr(void *p);
int		ft_contptr(unsigned long n);
int		ft_conthex(unsigned int n);
int		ft_checkhex(unsigned int nu, char format);
int		ft_checkptr(void *pp);
int		ft_checkint(int num);
int		ft_checkstr(char *str);
#endif