/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:57:12 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/04 19:08:51 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_close_map(char **map)
{
	int		i;
	char	*str;

	i = 0;
	while (map[i])
	{
		str = ft_strtrim(map[i], " \t");
		if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		{
			free(str);
			return (0);
		}
		free(str);
		i++;
	}
	return (1);
}

int	cheak_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S'
		&& c != 'E' && c != 'W' && c != ' ' && c != 'C' && c != 'X')
		return (0);
	return (1);
}

int	invalid_map(char **map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (cheak_char(map[i][j]) == 0)
				return (0);
			j++;
		}
		str = ft_strtrim(map[i], " \t");
		if (ft_strlen(str) == 0)
		{
			free(str);
			return (0);
		}
		free(str);
		j = 0;
		i++;
	}
	return (1);
}

int	cheack_all_img(t_data *data)
{
	if (invaild_img(data->ea) == 0)
		return (0);
	if (invaild_img(data->so) == 0)
		return (0);
	if (invaild_img(data->we) == 0)
		return (0);
	if (invaild_img(data->no) == 0)
		return (0);
	return (1);
}

int	cheack_if_dirc(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}
