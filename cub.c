/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:31:44 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/14 15:10:25 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_help6(t_data *img, t_loc *loc)
{
	unsigned int	i;

	i = 0;
	while (i < SCREENHEIGHT)
	{
		if (i < SCREENHEIGHT / 2)
			my_mlx_pixel_put1(img, loc->x, i,
				make_color(0, img->c_color.r, img->c_color.g, img->c_color.b));
		else if (i > SCREENHEIGHT / 2)
			my_mlx_pixel_put1(img, loc->x, i,
				make_color(0, img->f_color.r, img->f_color.g, img->f_color.b));
		i++;
	}
	i = -1;
	while (++i < SCREENHEIGHT)
	{
		my_mlx_pixel_put_alpha(img, loc->x, i, 0xff000000);
		if (i >= img->drawstart && i <= img->drawend)
		{
			if (get_t(img->buffer[i][loc->x]) > 0)
				my_mlx_pixel_put_alpha(img, loc->x, i, img->buffer[i][loc->x]);
			else
				my_mlx_pixel_put1(img, loc->x, i, img->buffer[i][loc->x]);
		}
	}
}

void	raycast_framing_help(t_data *img, t_loc *loc, int t)
{
	if (get_t(t) == 0)
		loc->color = t;
	else
		loc->color = (int)(int)img->texture[0][(int)TEXHEIGHT
			*loc->tex_y + loc->tex_x] & 0xffffff;
}

void	raycast_framing(t_data *img, t_loc *loc)
{
	if (img->frame % 40)
		raycast_framing_help(img, loc, img->enemy0_texture[(int)TEXHEIGHT
			*loc->tex_y + loc->tex_x]);
	else if (img->frame % 30)
		raycast_framing_help(img, loc, img->enemy1_texture[(int)TEXHEIGHT
			*loc->tex_y + loc->tex_x]);
	else
		raycast_framing_help(img, loc, img->enemy2_texture[(int)TEXHEIGHT
			*loc->tex_y + loc->tex_x]);
}

void	raycast_f(t_data *img, t_loc *loc, int i)
{
	if (loc->hit == 1)
		loc->color = (int)img->texture[i]
		[(int)TEXHEIGHT * loc->tex_y + loc->tex_x] & 0xffffff;
	else if (loc->hit == 2)
		loc->color = (int)img->door_close_texture
		[(int)TEXHEIGHT * loc->tex_y + loc->tex_x] & 0xffffff;
	else if (loc->hit == 3)
		loc->color = (int)img->door_open_texture
		[(int)TEXHEIGHT * loc->tex_y + loc->tex_x] & 0xffffff;
	else if (loc->hit == 4)
		raycast_framing(img, loc);
}

void	change_speed(int keycode, t_data *img)
{
	if (keycode == 126)
	{
		if (img->walkspeed < 0.9)
			img->walkspeed += 0.1;
	}
	if (keycode == 125)
	{
		if (img->walkspeed > 0.1)
			img->walkspeed -= 0.1;
	}
}
