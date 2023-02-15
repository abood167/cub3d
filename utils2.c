/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:00:55 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/02 10:04:58 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_2dlen(void **arr)
{
	long long	i;

	i = 0;
	if (!arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char const *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

void	printarr(char **arr)
{
	while (*arr)
	{
		ft_printf("%s\n", *arr);
		arr++;
	}
}

void	printlist(t_list *list)
{
	while (list)
	{
		ft_printf("%s\n", (char *)list->content);
		list = list->next;
	}
}

t_list	*ft_arrtolst(char **arr)
{
	t_list	*list;

	list = NULL;
	while (*arr)
	{
		ft_lstadd_back(&list, ft_lstnew((void *)ft_strdup(*arr)));
		arr++;
	}
	return (list);
}
