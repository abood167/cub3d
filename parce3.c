/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:04:23 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/04 19:09:36 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color_range(t_data *data)
{
	if (data->f_color.r > 255 || data->f_color.r < 0)
		return (0);
	if (data->f_color.g > 255 || data->f_color.g < 0)
		return (0);
	if (data->f_color.b > 255 || data->f_color.b < 0)
		return (0);
	if (data->c_color.r > 255 || data->c_color.r < 0)
		return (0);
	if (data->c_color.g > 255 || data->c_color.g < 0)
		return (0);
	if (data->c_color.b > 255 || data->c_color.b < 0)
		return (0);
	return (1);
}

int	invaild_img(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (str[i - 1] != 'm' || str[i - 2] != 'p'
		|| str[i - 3] != 'x' || str[i - 4] != '.')
		return (0);
	return (1);
}

int	exist_image(t_data *data)
{
	if (cheack_exist_img(data->ea) == 0)
		return (0);
	if (cheack_exist_img(data->so) == 0)
		return (0);
	if (cheack_exist_img(data->we) == 0)
		return (0);
	if (cheack_exist_img(data->no) == 0)
		return (0);
	return (1);
}

int	cheack_exist_img(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	cheack(char **data)
{
	int	i;

	i = ft_2dlen((void **)data);
	if (i != 6)
		return (0);
	return (1);
}
