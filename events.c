/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:37:10 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/14 21:48:47 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_check_rightleft(int keycode, t_data *img)
{	
	double	nextp_x;
	double	nextp_y;
	int		skip;

	nextp_x = 0;
	nextp_y = 0;
	skip = first_space(img->map);
	if (keycode == 13)
		move_up(img, nextp_x, nextp_y, skip);
	else if (keycode == 1)
		move_down(img, nextp_x, nextp_y, skip);
}

void	key_check_rotate(int keycode, t_data *img)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 124)
	{
		olddirx = img->dirx;
		img->dirx = img->dirx * cos(-ROTSPEED) - img->diry * sin(-ROTSPEED);
		img->diry = olddirx * sin(-ROTSPEED) + img->diry * cos(-ROTSPEED);
		oldplanex = img->planex;
		img->planex = img->planex
			* cos(-ROTSPEED) - img->planey * sin(-ROTSPEED);
		img->planey = oldplanex * sin(-ROTSPEED) + img->planey * cos(-ROTSPEED);
		img->player_dir -= ROTSPEED;
	}
	else if (keycode == 123)
	{
		olddirx = img->dirx;
		img->dirx = img->dirx * cos(ROTSPEED) - img->diry * sin(ROTSPEED);
		img->diry = olddirx * sin(ROTSPEED) + img->diry * cos(ROTSPEED);
		oldplanex = img->planex;
		img->planex = img->planex * cos(ROTSPEED) - img->planey * sin(ROTSPEED);
		img->planey = oldplanex * sin(ROTSPEED) + img->planey * cos(ROTSPEED);
				img->player_dir += ROTSPEED;
	}
}

void	*play_music(void *arg)
{
	t_data	*img;

	img = arg;
	if (img->music_pid != 0)
	{
		kill(img->music_pid, SIGKILL);
		img->music_pid = 0;
	}
	img->music_pid = fork();
	if (img->music_pid == 0)
	{
		execlp("afplay", "afplay", "./songs/riselol.mp3", 0);
		exit(0);
	}
	return (NULL);
}

void	open_close_door(int keycode, t_data *img)
{
	int		skip;
	double	nextp_x;
	double	nextp_y;

	skip = first_space(img->map);
	nextp_x = img->posx - (cos(img->player_dir) * img->walkspeed);
	nextp_y = img->posy + (sin(img->player_dir) * img->walkspeed);
	if (keycode == 14)
	{
		if (img->s[(int)(nextp_y)][(int)(nextp_x + skip)] == 'C')
		{
			img->s[(int)(nextp_y)][(int)((nextp_x + skip))] = 'O';
			img->map[(int)(nextp_y)][(int)((nextp_x + skip))] = 'O';
		}
	}
	if (keycode == 15)
	{
		if (img->s[(int)(nextp_y)][(int)(nextp_x + skip)] == 'O')
		{
			img->s[(int)(nextp_y)][(int)((nextp_x + skip))] = 'C';
			img->map[(int)(nextp_y)][(int)((nextp_x + skip))] = 'C';
		}
	}
}

int	key_check(int keycode, t_data *img)
{
	pthread_t	music;

	key_check_updown(keycode, img);
	key_check_rightleft(keycode, img);
	key_check_rotate(keycode, img);
	if (keycode == 53)
	{
		kill(img->music_pid, SIGKILL);
		exit(1);
	}
	open_close_door(keycode, img);
	if (keycode == 46)
	{
		pthread_create(&music, NULL, play_music, img);
		pthread_detach(music);
	}
	// if (keycode == 3)
	// {
	// 	draw_big_map(img);
	// 	mlx_put_image_to_window(img->mlx, img->win, img->bag_map, 0, 0);
	// 	sleep(3);
	// 	// return (0);
	// }
	change_speed(keycode, img);
	raycast (img);
	return (0);
}
