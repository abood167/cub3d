/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-saa <abin-saa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:05:27 by abin-saa          #+#    #+#             */
/*   Updated: 2023/02/14 20:34:01 by abin-saa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <pthread.h>
# include <signal.h>

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define SCREENWIDTH 1800
# define SCREENHEIGHT 960
# define ROTSPEED 0.1

typedef struct f_color
{
	char	*f;
	int		r;
	int		g;
	int		b;
}		t_fcolor;

typedef struct c_color
{
	char	*c;
	int		r;
	int		g;
	int		b;
}t_ccolor;

typedef struct s_data
{
	void				*img;
	void				*img_minimap;
	void				*win;
	void				*mlx;
	void				*ptr[4];
	unsigned int		*texture[4];
	int					bpp[4];
	int					ll[4];
	int					en[4];
	int					door_open_bpp;
	int					door_open_ll;
	int					door_open_en;
	int					door_close_bpp;
	int					door_close_ll;
	int					door_close_en;				
	int					enemy0_bpp;
	int					enemy0_ll;
	int					enemy0_en;
	char				*first_line;
	char				*addr;
	double				pos_x;
	double				pos_y;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	char				**s;
	unsigned int		buffer[SCREENHEIGHT][SCREENWIDTH];
	int					width[4];
	int					height[4];
	int					door_open_width;
	int					door_open_height;
	int					door_close_width;
	int					door_close_height;
	int					*door_open_texture;
	int					*door_close_texture;
	unsigned int		*enemy0_texture;
	unsigned int		*enemy1_texture;
	unsigned int		*enemy2_texture;
	int					enemy0_width;
	int					enemy0_height;
	char				**data;
	char				**map;
	unsigned int		drawstart;
	unsigned int		drawend;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					bpp_line;
	int					size_line;
	void				*minimap_addr;
	void				*img_alpha;
	void				*addr_alpha;
	float				posx;
	float				posy;
	float				player_dir;
	char				*ea;
	char				*so;
	char				*we;
	char				*no;
	t_ccolor			c_color;
	t_fcolor			f_color;
	void				*door_open_ptr;
	void				*door_close_ptr;
	void				*enemy0_prt;
	void				*enemy1_prt;
	void				*enemy2_prt;
	unsigned long long	frame;
	void				*gun1;
	void				*gun2;
	void				*aim;
	int					size;
	float				var1;
	float				var2;
	float				var3;
	float				var4;
	float				dx;
	float				dy;
	float				walkspeed;
	int					music_pid;
	void				*bag_map;
	void				*add_bag_map;
}	t_data;

typedef struct s_loc
{
	unsigned int	y;
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	double			wall_x;
	double			step;
	double			texpos;
	int				x;
	int				map_x;
	int				map_y;
	int				lineheight;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				tex_x;
	int				tex_y;
	int				color;
}					t_loc;

int		fill_data(t_data *data);
int		cheack(char **data);
int		start_one(char *str);
void	raycast(t_data *img);
int		key_check(int keycode, t_data *img);
int		ft_2dlen(void **arr);
void	printarr(char **arr);
t_list	*ft_arrtolst(char **arr);
void	ft_freearray(void **arr);
char	**ft_lsttoarr(t_list *list);
void	read_map(char *str, t_data *data);
void	draw_player(t_data *data);
int		first_space(char **line);
void	draw_map( t_data *data);
void	draw_line(t_data *data);
void	my_mlx_pixel_put(t_data *game, int x, int y, int color);
int		f_lline(t_data *data);
void	white_box(t_data *game, int x, int y, int color);
void	my_mlx_pixel_put1(t_data *data, int x, int y, int color);
void	minimap(t_data *data);
char	**roted_arr(char **arr);
char	**roted_array(char **arr);
void	key_check_rotate(int keycode, t_data *img);
int		ft_max(int a, int b);
void	save_dir(t_data *data);
void	ft_error(void);
void	printarr(char **arr);
void	printlist(t_list *list);
t_list	*ft_arrtolst(char **arr);
char	**ft_lsttoarr(t_list *list);
char	**ft_copyarr(char **arr);
char	*listtostr(t_list *arr);
char	*arrtostr(char **arr);
int		ft_2dlen(void **arr);
int		check_color_range(t_data *data);
int		fill_the_colore(t_data *data);
int		exist_image(t_data *data);
int		cheack_exist_img(char *str);
int		cheack_all_img(t_data *data);
int		invaild_img(char *str);
char	**ft_remove_new_line(char **arr);
int		invalid_map(char **map);
int		check_whitespaces_in_map(t_data *data);
int		cheack_zeros(t_data *data);
int		cheack_if_dirc(char **map);
int		check_close_map(char **map);
int		make_color(int t, int r, int g, int b);
void	my_mlx_pixel_put_alpha(t_data *data, int x, int y, int color);
int		cheack_error(t_data *img);
void	init(t_data	*img);
void	set_pos(t_data *img);
int		cheak_char(char c);
int		cheack_colore(t_data *data, int *k, int *i);
void	cheack_colo2(t_data *data, int *n, int *j);
void	cheack_colo3(t_data *data, int *n, int *j);
char	*ft_strcpy(char *dest, char const *src);
void	creat_imgs(t_data *img);
void	creat_imgs2(t_data *img);
void	creat_imgs3(t_data *img);
int		mouse(int x, int y, t_data *img);
void	draw_player_helper(t_data *data, int i, int j, int skip);
int		frame_conter(void *data);
int		mouse_hook(int keycode, int x, int y, t_data *img);
void	move_up(t_data *img, double nextp_x, double nextp_y, int skip);
void	move_down(t_data *img, double nextp_x, double nextp_y, int skip);
void	key_check_updown(int keycode, t_data *img);
char	*read_first_line(int fd);
char	*remove_empty_lines(char *line, int fd);
t_list	*get_lines(int fd, t_data *data);
void	make_map(t_list *list, t_data *data);
void	read_map(char *str, t_data *data);
int		open_file(char *str);
char	*read_meta_data(int fd, t_data *data, char *line);
void	move_down(t_data *img, double nextp_x, double nextp_y, int skip);
void	check_name(char *str);
int		get_t(int trgb);
void	raycast_help1(t_data *img, t_loc *loc);
void	raycast_help2(t_data *img, t_loc *loc);
void	raycast_help3(t_data *img, t_loc *loc);
void	raycast_help4(t_data *img, t_loc *loc);
void	raycast_help5(t_data *img, t_loc *loc);
void	raycast_help6(t_data *img, t_loc *loc);
void	init_local(t_loc *loc, int x, int mapx, int mapy);
void	raycast_help(t_data *img, int x, int mapx, int mapy);
void	put_imgs(t_data *img);
void	raycast(t_data *img);
void	raycast_framing(t_data *img, t_loc *loc);
void	raycast_f(t_data *img, t_loc *loc, int i);
void	raycast_help5(t_data *img, t_loc *loc);
void	white_box1(t_data *game, int x, int y, int color);
void	change_speed(int keycode, t_data *img);
void	white_box2(t_data *game, int x, int y, int color);
void	draw_big_map(t_data *data);
void	my_mlx_pixel_put3(t_data *game, int x, int y, int color);
#endif