/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:27:43 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/01 08:43:35 by ael-oual         ###   ########.fr       */
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

typedef struct	s_norm {
	int		x_length;
	int 	y_length;
	int		max_x;
	int		min_x;
	int		min_y;
	int		max_y;
	int		zoom_x;
	int		zoom_y;
}				t_norm;

typedef struct	s_data {
	void 	*mlx_win;
	void	*mlx;
	void	*img;
	char	*addr;
	t_norm  screnn;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		n_points;
	int		**x_y_z_matrix;
	int		**x_y_z_old;
}				t_data;

typedef struct s_point {
	int x0;
	int y0;
	int x1;
	int y1;
}		t_point;


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;



int		key_hook(int keycode, t_data *vars);
int		ft_printf(const char *n, ...);
int		convert_hex_long_ptr(size_t a, int address);
int		ft_print_memory(void *addr, int address);
void	ft_putchar_fd(char c, int fd);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_strlen_d(char **arr_split);
void	free_function(char **str);
int 	**check_list(t_list *list, int *length_line);
void	print_matrix(int **x_y_z_matrix);
void	x_y_z_c_function(char **split_line, int nbr_lin,int **x_y_z_matrix);
int		*bre_algori(t_point ab, int coler,t_data *img);
void	isometric_projection(int **x_y_z_matrix, int length_line, int n_points,t_data *img);
void	drawing_points(int **x_y_z_matrix , int length_line , int n_points,t_data *img);
void	erros_functions(char **argv);
int		check_file_argument(char **argv, int argc);
void	centre_fun(t_data *img);
int		to_decimal(char *str);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif