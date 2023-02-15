/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:03:32 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/15 07:11:28 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put1(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_alpha(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr_alpha + (y * data->line_length
			+ x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game ->minimap_addr
		+ (y * game->size_line + x * (game->bpp_line / 8));
	*(unsigned int *)dst = color;
}
void	my_mlx_pixel_put3(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game ->add_bag_map
		+ (y * game->size_line + x * (game->bpp_line / 8));
	*(unsigned int *)dst = color;
}

void	white_box1(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game ->size)
	{
		j = 0;
		while (j < game ->size)
		{
			my_mlx_pixel_put(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	white_box2(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 500 )
	{
		j = 0;
		while (j < 500)
		{
			my_mlx_pixel_put3(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	white_box(t_data *game, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ft_max(3, game ->size / 5))
	{
		j = 0;
		while (j < ft_max(3, game ->size / 5))
		{
			my_mlx_pixel_put(game, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
