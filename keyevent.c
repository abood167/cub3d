/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyevent.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:12:16 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/14 13:56:39 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_right(t_data *img, double nextp_x, double nextp_y, int skip)
{
	if (img->s[(int)(img->pos_x + img->planex * img->walkspeed)][(int)(img->pos_y)]
			&& img->s[(int)(img->pos_x + img->planex * img->walkspeed)]
			[(int)(img->pos_y)] != '1'
				&& img->s[(int)(img->pos_x + img->planex * img->walkspeed)]
				[(int)(img->pos_y)] != 'C' )
			img->pos_x += img->planex * img->walkspeed;
	if (img->s[(int)(img->pos_x)][(int)(img->pos_y + img->planey * img->walkspeed)]
			&& img->s[(int)(img->pos_x)]
			[(int)(img->pos_y + img->planey * img->walkspeed)] != '1'
				&& img->s[(int)(img->pos_x)]
				[(int)(img->pos_y + img->planey * img->walkspeed)] != 'C')
			img->pos_y += img->planey * img->walkspeed;
		nextp_x = img->posx
		- (cos(img->player_dir - (M_PI / 2)) * img->walkspeed / 1.5);
		nextp_y = img->posy
		+ (sin(img->player_dir - (M_PI / 2)) * img->walkspeed / 1.5);
	if (img->map[(int)nextp_y][(int)img->posx + skip] != '\0'
			&& img->map[(int)nextp_y]
				[(int)(img->posx + (skip))] != '1'
					&& img->map[(int)nextp_y][(int)(img->posx + (skip))] != 'C')
			img->posy = nextp_y;
	if (img->map[(int)img->posy][(int)nextp_x + skip] != '\0'
			&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != '1'
				&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != 'C')
			img->posx = nextp_x;
}

void	move_left_helper(t_data *img)
{
	if (img->s[(int)(img->pos_x - img->planex * img->walkspeed)]
			[(int)(img->pos_y)]
			&& img->s[(int)(img->pos_x - img->planex * img->walkspeed)]
			[(int)(img->pos_y)] != '1'
			&& img->s[(int)(img->pos_x - img->planex * img->walkspeed)]
				[(int)(img->pos_y)] != 'C')
			img->pos_x -= img->planex * img->walkspeed;
}

void	move_left(t_data *img, double nextp_x, double nextp_y, int skip)
{
	move_left_helper(img);
	if (img->s[(int)(img->pos_x)][(int)(img->pos_y - img->planey * img->walkspeed)]
			&& img->s[(int)(img->pos_x)]
				[(int)(img->pos_y - img->planey * img->walkspeed)] != '1'
				&& img->s[(int)(img->pos_x)]
					[(int)(img->pos_y - img->planey * img->walkspeed)] != 'C')
			img->pos_y -= img->planey * img->walkspeed;
		nextp_y = img->posy
		+ (sin(img->player_dir + (M_PI / 2)) * img->walkspeed / 1.5);
		nextp_x = img->posx
		- (cos(img->player_dir + (M_PI / 2)) * img->walkspeed / 1.5);
	if (img->map[(int)nextp_y][(int)img->posx + skip]
			&& img->map[(int)nextp_y]
			[(int)(img->posx + (skip))] != '1'
				&& img->map[(int)nextp_y]
				[(int)(img->posx + (skip))] != 'C')
			img->posy = nextp_y;
	if (img->map[(int)img->posy][(int)nextp_x + skip]
			&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != '1'
				&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != 'C')
			img->posx = nextp_x;
}

void	key_check_updown(int keycode, t_data *img)
{	
	int		skip;
	double	nextp_x;
	double	nextp_y;

	nextp_x = 0.0;
	nextp_y = 0.0;
	skip = first_space(img->map);
	if (keycode == 2)
		move_right(img, nextp_x, nextp_y, skip);
	else if (keycode == 0)
		move_left(img, nextp_x, nextp_y, skip);
}

void	move_up(t_data *img, double nextp_x, double nextp_y, int skip)
{
	if (img->s[(int)(img->pos_x + img->dirx * img->walkspeed)]
	[(int)(img->pos_y)] != '\0'
		&& img->s[(int)(img->pos_x + img->dirx * img->walkspeed)]
		[(int)(img->pos_y)] != '1' &&
			img->s[(int)(img->pos_x + img->dirx * img->walkspeed)]
			[(int)(img->pos_y)] != 'C' )
		img->pos_x += img->dirx * img->walkspeed;
	if (img->s[(int)(img->pos_x)]
		[(int)(img->pos_y + img->diry * img->walkspeed)] != '\0'
			&& img->s[(int)(img->pos_x)]
			[(int)(img->pos_y + img->diry * img->walkspeed)] != '1'
			&& img->s[(int)(img->pos_x)]
			[(int)(img->pos_y + img->diry * img->walkspeed)] != 'C')
		img->pos_y += img->diry * img->walkspeed;
	nextp_x = img->posx - (cos(img->player_dir) * img->walkspeed);
	nextp_y = img->posy + (sin(img->player_dir) * img->walkspeed);
	if (img->map[(int)nextp_y][(int)img->posx + skip] != '\0'
		&& img->map[(int)nextp_y]
			[(int)(img->posx + (skip))] != '1'
			&& img->map[(int)nextp_y][(int)(img->posx + (skip))] != 'C')
		img->posy = nextp_y;
	if (img->map[(int)img->posy][(int)nextp_x + skip] != '\0'
		&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != '1'
			&& img->map[(int)img->posy][(int)(nextp_x + (skip))] != 'C')
		img->posx = nextp_x;
}
