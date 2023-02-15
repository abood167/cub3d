/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 07:01:22 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/15 07:21:46 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cheack_error(t_data *img)
{
	fill_data(img);
	if (cheack(img->data) == 0)
		ft_error();
	if (fill_the_colore(img) == 0)
		ft_error();
	if (check_color_range(img) == 0)
		ft_error();
	if (exist_image(img) == 0)
		ft_error();
	if (cheack_all_img(img) == 0)
		ft_error();
	if (invalid_map(img->map) == 0)
		ft_error();
	if (cheack_if_dirc(img->map) == 0)
		ft_error();
	if (cheack_zeros(img) == 0)
		ft_error();
	if (check_close_map(img->map) == 0)
		ft_error();
	return (1);
}

void	init(t_data	*img)
{
	int	max_size;
	int	with;
	int	size;
	int	skip;

	img->mlx = mlx_init();
	max_size = f_lline(img);
	with = ft_2dlen((void **)img->map);
	img->music_pid = 0;
	size = 900 / ((max_size - first_space(img->map)) + with);
	skip = first_space(img->map);
	img->img_minimap = mlx_new_image(img->mlx, size
			* (max_size - skip), (with + 1) * size);
	img->minimap_addr = mlx_get_data_addr(img->img_minimap,
			&img->bpp_line, &img->size_line, &img->endian);
	img->s = roted_array(img->map);
	img->win = mlx_new_window(img->mlx,
			SCREENWIDTH, SCREENHEIGHT, "Hello world!");
	img->img = mlx_new_image(img->mlx, SCREENWIDTH, SCREENHEIGHT);
	img->bag_map = mlx_new_image(img->mlx, SCREENWIDTH, SCREENHEIGHT);
	img->img_alpha = mlx_new_image(img->mlx, SCREENWIDTH, SCREENHEIGHT);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->add_bag_map = mlx_get_data_addr(img->bag_map,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->addr_alpha = mlx_get_data_addr(img->img_alpha,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	draw_player(img);
}

void	set_direction(t_data *img, int j, int k)
{
	if (img->s[j][k] == 'S')
	{
		img->dirx = 1;
		img->planey = -0.66;
	}
	else if (img->s[j][k] == 'E')
	{
		img->diry = 1;
		img->planex = 0.66;
	}
	else if (img->s[j][k] == 'W')
	{
		img->diry = -1;
		img->planex = -0.66;
	}
	else
	{
		img->dirx = -1;
		img->planey = 0.66;
	}
}

void	set_pos(t_data *img)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (img->s[j])
	{
		k = 0;
		while (img->s[j][k])
		{
			if (img->s[j][k] == 'W' || img->s[j][k] == 'N'
			|| img->s[j][k] == 'S' || img->s[j][k] == 'E')
			{
				img->pos_x = j + 0.5;
				img->pos_y = k + 0.5;
				set_direction(img, j, k);
				break ;
			}
			k++;
		}
		j++;
	}
}
