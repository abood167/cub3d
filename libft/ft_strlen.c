/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:40:16 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/04 20:14:41 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (s[0] == '\0')
	{
		return (0);
	}
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

/*int main ()
{
    printf("%zu",ft_strlen("lord"));
    return(0);
}
*/