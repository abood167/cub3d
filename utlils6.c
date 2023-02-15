/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlils6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:07:45 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/04 20:12:30 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	frame_conter(void *data)
{
	t_data	*img;

	img = (t_data *)data;
	img->frame++;
	raycast(img);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	(void)img;
	if (keycode == 1)
		mlx_put_image_to_window(img->mlx, img->win, img->gun2, 450, 510);
	return (0);
}

void	raycast_help5(t_data *img, t_loc *loc)
{
	loc->y = 0;
	loc->step = 1.0 * TEXHEIGHT / loc->lineheight;
		loc->texpos = (img->drawstart
			- SCREENHEIGHT / 2 + loc->lineheight / 2) * loc->step;
	while (loc->y < SCREENHEIGHT)
	{
		if (loc->y >= img->drawstart && loc->y <= img->drawend)
		{
			loc->tex_y = (int)loc->texpos & (img->height[0] - 1);
			loc->texpos += loc->step;
			if (loc->side == 0 && loc->raydir_x > 0)
				raycast_f(img, loc, 0);
			else if (loc->side == 0 && loc->raydir_x < 0)
				raycast_f(img, loc, 1);
			else if (loc->side == 1 && loc->raydir_y > 0)
				raycast_f(img, loc, 2);
			else if (loc->side == 1 && loc->raydir_y < 0)
				raycast_f(img, loc, 3);
			if (loc->side == 1)
				loc->color = (loc->color >> 1) & 8355711;
			img->buffer[loc->y][loc->x] = loc->color;
		}
		loc->y++;
	}
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
