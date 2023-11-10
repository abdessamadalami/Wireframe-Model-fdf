/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:27:43 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/26 13:13:54 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include <fcntl.h>
# include <string.h>
# include<math.h>
# include<sys/wait.h>
# include <mlx.h>
# include "get_next_line.h"
# include "libft.h"
# define HIX "0123456789abcdef"

typedef struct s_norm {
	char	type_of;
	int		x_length;
	int		y_length;
	int		z_index;
	int		zoom_y;
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
}				t_norm;

typedef struct s_tra {
	int	tr_x;
	int	tr_y;
}				t_tra;

typedef struct s_data {
	void	*m_win;
	void	*mlx;
	t_tra	r;
	int		l_length;
	void	*img;
	char	*addr;
	t_norm	screnn;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		n_points;
	int		**xyz_m;
	int		**xyz_old;
	int		d;
	int		polyline;
}				t_data;

typedef struct s_point {
	int	x0;
	int	y0;
	int	color_0;
	int	x1;
	int	y1;
	int	color_1;
}		t_point;

typedef struct s_bre {
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	error;
	int	e2;
}		t_bre;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_rgb {
	float		d_r;
	float		d_g;
	float		d_b;
}				t_rgb;

typedef struct s_parms {
	int		i;
	int		fd;
	char	*line;
}				t_parms;
void	allocation_problem(void);
void	rotate(t_data *vars, int c);
void	transf_fun(t_data *vars, char c, int operator);
int		mouse_up(int button, int x, int y, t_data *vars);
void	print_in(t_data *vars);
int		mouse_move(int x, int y, t_data *p);
void	del(void *ptr);
void	transf_fun(t_data *vars, char c, int operator);
void	zoom_fun(t_data *vars, int operat, int x, int y);
void	z_hook(t_data *vars, int operat);
int		mouse_hook( int keycode, t_data *img);
void	rotate_x(t_data *vars);
void	rotate_y(t_data *vars);
void	rotate_z(t_data *vars);
int		ft_strchr_int(const char *str, int c);
int		max(int num1, int num2);
int		ft_strlen_space(char *str);
t_rgb	get_deffrent(int color, int color2, int div);
void	get_color(int *color, t_rgb d);
void	copy_d(t_data *img);
int		key_hook(int keycode, t_data *vars);
int		convert_hex_long_ptr(size_t a, int address);
int		ft_print_memory(void *addr, int address);
void	ft_putchar_fd(char c, int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_strlen_d(char **arr_split);
void	free_function(char **str);
int		**check_list(t_list *list, int *length_line, int line_nbr);
void	print_matrix(int **xyz_m);
void	x_y_z_c_function(char **split_line, int nbr_lin, int **xyz_m);
int		*bre_algori(t_point ab, t_data *img);
void	h_v_point(int index, int l_line, t_data *img);
void	isometric_projection(t_data *img);
void	drawing_points(t_data *img);
void	erros_functions(char **argv);
int		check_file_argument(char **argv, int argc);
void	centre_fun(t_data *img);
int		to_decimal(char *str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	put_image(t_data *vars);
void	free_pram(t_data *img);
void	free_ptr(int **ptr);
void	make_win(t_data *img);
int		close_d(t_data *vars);
void	print_matrixx(t_data *vars);
void	print_ma(int **xyz_m, int nbr);
#endif