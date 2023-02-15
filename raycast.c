/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:52:06 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/04 19:04:15 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycast_help1(t_data *img, t_loc *loc)
{
	loc->camera_x = 2 * loc->x / (double)(SCREENWIDTH) - 1;
	loc->raydir_x = img->dirx + img->planex * loc->camera_x;
	loc->raydir_y = img->diry + img->planey * loc->camera_x;
	loc->map_x = (int)(img->pos_x);
	loc->map_y = (int)(img->pos_y);
	if (loc->raydir_x == 0)
		loc->deltadist_x = 1e30;
	else
		loc->deltadist_x = fabs(1 / loc->raydir_x);
	if (loc->raydir_y == 0)
		loc->deltadist_y = 1e30;
	else
		loc->deltadist_y = fabs(1 / loc->raydir_y);
}

void	raycast_help2(t_data *img, t_loc *loc)
{
	if (loc->raydir_x < 0)
	{
		loc->step_x = -1;
		loc->sidedist_x = (img->pos_x - loc->map_x) * loc->deltadist_x;
	}
	else
	{
		loc->step_x = 1;
		loc->sidedist_x = (loc->map_x + 1.0 - img->pos_x) * loc->deltadist_x;
	}
	if (loc->raydir_y < 0)
	{
		loc->step_y = -1;
		loc->sidedist_y = (img->pos_y - loc->map_y) * loc->deltadist_y;
	}
	else
	{
		loc->step_y = 1;
		loc->sidedist_y = (loc->map_y + 1.0 - img->pos_y) * loc->deltadist_y;
	}
}

void	raycast_help3help(t_data *img, t_loc *loc)
{
	if (img->s[loc->map_x][loc->map_y] == '1')
		loc->hit = 1;
	else if (img->s[loc->map_x][loc->map_y] == 'C')
		loc->hit = 2;
	else if (img->s[loc->map_x][loc->map_y] == 'O')
		loc->hit = 3;
	else if (img->s[loc->map_x][loc->map_y] == 'X')
		loc->hit = 4;
}

void	raycast_help3(t_data *img, t_loc *loc)
{
	while (loc->hit == 0)
	{
		if (loc->sidedist_x < loc->sidedist_y)
		{
			loc->sidedist_x += loc->deltadist_x;
			loc->map_x += loc->step_x;
			loc->side = 0;
		}
		else
		{
			loc->sidedist_y += loc->deltadist_y;
			loc->map_y += loc->step_y;
			loc->side = 1;
		}
		if (ft_strlen(img->s[loc->map_x]) > (size_t)loc->map_y)
			raycast_help3help(img, loc);
	}
}

void	raycast_help4(t_data *img, t_loc *loc)
{
	if (loc->side == 0)
		loc->perpwalldist = loc->sidedist_x - loc->deltadist_x;
	else
		loc->perpwalldist = loc->sidedist_y - loc->deltadist_y;
	loc->lineheight = (int)(SCREENHEIGHT / loc->perpwalldist);
	img->drawstart = -loc->lineheight / 2 + SCREENHEIGHT / 2;
	img->drawend = loc->lineheight / 2 + SCREENHEIGHT / 2;
	if (img->drawend >= SCREENHEIGHT)
		img->drawend = SCREENHEIGHT - 1;
	if (img->drawstart >= SCREENHEIGHT)
		img->drawstart = 0;
	if (loc->side == 0)
		loc->wall_x = img->pos_y + loc->perpwalldist * loc->raydir_y;
	else
		loc->wall_x = img->pos_x + loc->perpwalldist * loc->raydir_x;
	loc->wall_x -= floor((loc->wall_x));
	loc->tex_x = (int)(loc->wall_x * (double)(TEXWIDTH));
	if (loc->side == 0 && loc->raydir_x > 0)
		loc->tex_x = TEXWIDTH - loc->tex_x - 1;
	if (loc->side == 1 && loc->raydir_y < 0)
		loc->tex_x = TEXWIDTH - loc->tex_x - 1;
}
