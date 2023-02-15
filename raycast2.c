/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:56:49 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/14 21:47:13 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_local(t_loc *loc, int x, int mapx, int mapy)
{
	loc->x = x;
	loc->y = 0;
	loc->map_x = mapx;
	loc->map_y = mapy;
	loc->camera_x = 0;
	loc->raydir_x = 0;
	loc->raydir_y = 0;
	loc->sidedist_x = 0;
	loc->sidedist_y = 0;
	loc->deltadist_x = 0;
	loc->deltadist_y = 0;
	loc->perpwalldist = 0;
	loc->lineheight = 0;
	loc->step_x = 0;
	loc->step_y = 0;
	loc->hit = 0;
	loc->side = 0;
	loc->wall_x = 0;
	loc->tex_x = 0;
	loc->tex_y = 0;
	loc->step = 0;
	loc->texpos = 0;
	loc->color = 0;
}

void	raycast_help(t_data *img, int x, int mapx, int mapy)
{
	t_loc	loc;

	init_local(&loc, x, mapx, mapy);
	raycast_help1(img, &loc);
	raycast_help2(img, &loc);
	raycast_help3(img, &loc);
	raycast_help4(img, &loc);
	raycast_help5(img, &loc);
	raycast_help6(img, &loc);
}

void	put_imgs(t_data *img)
{
	int	max_size;
	int	with;
	int	skip;
	int	size;

	max_size = f_lline(img);
	with = ft_2dlen((void **)img->map);
	skip = first_space(img->map);
	size = 900 / (max_size - skip + with);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_put_image_to_window(img->mlx, img->win, img->img_alpha, 0, 0);
	ft_bzero(img->minimap_addr, with * size
		* ((max_size - skip) * size) * (img->bpp_line / 8));
	minimap(img);
	mlx_put_image_to_window(img->mlx, img->win, img->gun1, 450, 510);
	// draw_big_map(img);
	// mlx_put_image_to_window(img->mlx, img->win, img->bag_map, 0, 0);

}

void	raycast(t_data *img)
{
	static long	frame;
	int			x;
	int			map_x;
	int			map_y;

	map_x = 0;
	map_y = 0;
	x = 0;
	frame = 0;
	while (x < SCREENWIDTH)
	{
		raycast_help(img, x, map_x, map_y);
		x++;
	}
	put_imgs(img);
	frame++;
}
