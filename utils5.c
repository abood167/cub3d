/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:57:28 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/14 14:51:44 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data)
{
	int	i;
	int	j;
	int	count;
	int	skip;

	i = 0;
	j = 0;
	count = 0;
	skip = first_space(data->map);
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				draw_player_helper(data, i, j, skip);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	creat_imgs2(t_data *img)
{
	int	i;

	i = 400;
	img->enemy2_texture = (unsigned int (*))mlx_get_data_addr(img->enemy2_prt,
			&img->enemy0_bpp,
			&img->enemy0_ll, &img->enemy0_en);
	img->gun1 = mlx_xpm_file_to_image(img->mlx,
			"./img/gun4c.xpm", &i, &i);
	img->gun2 = mlx_xpm_file_to_image(img->mlx,
			"./img/gun4b.xpm", &i, &i);
	img->aim = mlx_xpm_file_to_image(img->mlx, "./img/aim21.xpm",
			&img->enemy0_width, &img->enemy0_height);
}

void	creat_imgs3(t_data *img)
{
	img->door_open_ptr = mlx_xpm_file_to_image(img->mlx, "./img/door_open.xpm",
			&img->door_open_width, &img->door_open_height);
	img->door_open_texture = (int (*))mlx_get_data_addr(img->door_open_ptr,
			&img->door_open_bpp,
			&img->door_open_ll, &img->door_open_en);
	img->door_close_ptr = mlx_xpm_file_to_image(img->mlx,
			"./img/door_close.xpm",
			&img->door_close_width, &img->door_close_height);
	img->door_close_texture = (int (*))mlx_get_data_addr(img->door_close_ptr,
			&img->door_close_bpp,
			&img->door_close_ll, &img->door_close_en);
	img->enemy0_prt = mlx_xpm_file_to_image(img->mlx, "./img/enemy0.xpm",
			&img->enemy0_width, &img->enemy0_height);
	img->enemy0_texture = (unsigned int (*))mlx_get_data_addr(img->enemy0_prt,
			&img->enemy0_bpp,
			&img->enemy0_ll, &img->enemy0_en);
	img->enemy1_prt = mlx_xpm_file_to_image(img->mlx, "./img/cobraatt1.xpm",
			&img->enemy0_width, &img->enemy0_height);
	img->enemy1_texture = (unsigned int (*))mlx_get_data_addr(img->enemy1_prt,
			&img->enemy0_bpp,
			&img->enemy0_ll, &img->enemy0_en);
	img->enemy2_prt = mlx_xpm_file_to_image(img->mlx, "./img/cobraatt2.xpm",
			&img->enemy0_width, &img->enemy0_height);
}

void	creat_imgs(t_data *img)
{
	img->ptr[0] = mlx_xpm_file_to_image(img->mlx, img->no,
			&img->width[0], &img->height[0]);
	img->texture[0] = (unsigned int (*))mlx_get_data_addr(img->ptr[0],
			&img->bpp[0], &img->ll[0], &img->en[0]);
	img->ptr[1] = mlx_xpm_file_to_image(img->mlx, img->so,
			&img->width[1], &img->height[1]);
	img->texture[1] = (unsigned int (*))mlx_get_data_addr(img->ptr[1],
			&img->bpp[1], &img->ll[1], &img->en[1]);
	img->ptr[2] = mlx_xpm_file_to_image(img->mlx, img->ea,
			&img->width[2], &img->height[2]);
	img->texture[2] = (unsigned int (*))mlx_get_data_addr(img->ptr[2],
			&img->bpp[2], &img->ll[2], &img->en[2]);
	img->ptr[3] = mlx_xpm_file_to_image(img->mlx, img->we,
			&img->width[3], &img->height[3]);
	img->texture[3] = (unsigned int (*))mlx_get_data_addr(img->ptr[3],
			&img->bpp[3],
			&img->ll[3], &img->en[3]);
	creat_imgs3(img);
	creat_imgs2(img);
}

int	mouse(int x, int y, t_data *img)
{
	(void)y;
	mlx_mouse_hide();
	if (x > SCREENWIDTH / 2)
	{
		key_check_rotate(124, img);
	}
	else
	{
		key_check_rotate(123, img);
	}
	raycast(img);
	mlx_mouse_move(img->win, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	return (0);
}
