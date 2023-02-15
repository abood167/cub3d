/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:50:23 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/02 10:02:20 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_lsttoarr(t_list *list)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	i = 0;
	while (list)
	{
		arr[i++] = ft_strdup((char *)list->content);
		list = list->next;
	}
	arr[i] = NULL;
	ft_lstclear(&list, free);
	return (arr);
}

char	**ft_copyarr(char **arr)
{
	char	**copy;
	int		len;

	len = ft_2dlen((void **)arr);
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	copy[len] = NULL;
	while (len--)
		copy[len] = ft_strdup(arr[len]);
	return (copy);
}

char	*listtostr(t_list *arr)
{
	char	*str;
	int		len;
	t_list	*start;

	len = 0;
	start = arr;
	while (arr)
	{
		len += ft_strlen((char *)arr->content);
		arr = arr->next;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len = 0;
	while (start)
	{
		ft_strcpy(&str[len], (char *)start->content);
		len += ft_strlen((char *)start->content);
		start = start->next;
	}
	return (str);
}

void	ft_error(void)
{
	printf("Error	:	Invalid map");
	exit(1);
}

void	ft_freearray(void **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}
