/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:30:56 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/14 21:46:50 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_helper(t_data *data, int i, int j, int skip)
{
	data->posx = j - skip + 0.5;
	data->posy = i + 0.5;
	if (data->map[i][j] == 'S')
		data->player_dir = M_PI / 2;
	else if (data->map[i][j] == 'N')
		data->player_dir = (3 * M_PI) / 2.0 ;
	else if (data->map[i][j] == 'W')
		data->player_dir = 2 * M_PI;
	else if (data->map[i][j] == 'E')
		data->player_dir = M_PI;
	data->map[i][j] = '0';
}

void	init2(t_data *img)
{
	int		max_size;
	int		with;

	max_size = f_lline(img);
	with = ft_2dlen((void **)img->map);
	img->size = 900 / ((max_size - first_space(img->map)) + with);
	img->frame = 0;
	img->pos_x = img->posx;
	img->pos_y = img->posy;
	img->drawstart = 0;
	img->drawend = 0;
	img->planex = 0;
	img->planey = 0;
	img->dirx = 0;
	img->diry = 0;
}

int	main(int ac, char **av)
{
	t_data	img;

	if (ac != 2)
	{
		printf("Error");
		return (0);
	}
	check_name(av[1]);
	read_map(av[1], &img);
	img.walkspeed = 0.1;
	printarr(img.data);
	cheack_error(&img);
	init(&img);
	init2(&img);
	set_pos(&img);
	creat_imgs(&img);
	minimap(&img);
	raycast(&img);
	mlx_hook(img.win, 2, 0, key_check, &img);
	mlx_hook(img.win, 6, 1L << 6, mouse, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_loop_hook(img.mlx, &frame_conter, &img);
	mlx_loop(img.mlx);
}
