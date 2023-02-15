/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:47:03 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/04 21:43:25 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cheack_colore(t_data *data, int *n, int *j)
{
	int	i;
	int	k;

	i = *j;
	k = *n;
	while (data->data[i][k] == ' ' || data->data[i][k] == '\t')
			k++;
	if (data->data[i][k] == 'E' && data->data[i][k + 1] == 'A')
	{
		k += 3;
		while (data->data[i][k] == ' ' || data->data[i][k] == '\t')
			k++;
		data->ea = ft_strdup(data->data[i] + k);
	}
	else if (data->data[i][k] == 'S' && data->data[i][k + 1] == 'O')
	{
		k += 3;
		while (data->data[i][k] == ' ' || data->data[i][k] == '\t')
		{
			k++;
		}
		data->so = ft_strdup(data->data[i] + k);
	}
	return (1);
}

void	cheack_colo2(t_data *data, int *n, int *j)
{
	int	i;
	int	k;

	i = *j;
	k = *n;
	if (data->data[i][k] == 'W' && data->data[i][k + 1] == 'E')
	{
		k += 3;
		while (data->data[i][k] == ' ' || data->data[i][k] == '\t')
			k++;
		data->we = ft_strdup(data->data[i] + k);
	}
	else if (data->data[i][k] == 'N' && data->data[i][k + 1] == 'O')
	{
		k += 3;
		while (data->data[i][k] == ' ' || data->data[i][k] == '\t')
			k++;
		data->no = ft_strdup(data->data[i] + k);
	}
}

int	cheack_zero_helper(char **map, int *i, int *j)
{
	int	n;
	int	m;

	n = *i;
	m = *j;
	if (map[n][m] == '0' || map[n][m] == 'W'
			|| map[n][m] == 'S' || map[n][m] == 'E'
			|| map[n][m] == 'N' || map[n][m] == 'X'
			|| map[n][m] == 'C' || map[n][m] == 'O')
	{
		if (n > 0 && m > 0 && (n < ft_2dlen((void **)map) - 1)
			&& (m < (int)ft_strlen(map[n]) - 1))
		{
			if ((m > (int)ft_strlen(map[n - 1]) - 1
					&& (m > (int)ft_strlen(map[n + 1])) - 1))
				return (0);
			if (map[n + 1][m] == ' ' || map[n - 1][m] == ' '
				|| (map[n][m + 1] != '\0' && map[n][m + 1] == ' ')
					|| map[n][m - 1] == ' ')
				return (0);
		}
	}
	return (1);
}

int	cheack_zeros(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	j = 0;
	map = data->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (cheack_zero_helper(map, &i, &j) == 0)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

char	*arrtostr(char **arr)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (arr[i])
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = 0;
	len = 0;
	while (arr[i])
	{
		ft_strcpy(&str[len], arr[i]);
		len += ft_strlen(arr[i]);
		i++;
	}
	return (str);
}
