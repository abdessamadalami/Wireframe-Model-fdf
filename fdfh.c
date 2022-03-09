/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/06 15:49:50 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>
#include<stdio.h>
#include <unistd.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include"get_next_line.h"
#include "libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void x_y_z_array(char **split_line, int nbr_lin,int **x_y_z_matrix)
{
	static int i;
	int index;
	index = 0;
	//printf(" %d %i ",nbr_lin, i);
	while(split_line[index] != 0)
	{
		// printf("< i %d x %d y %d z %d > \n",i ,index,nbr_lin,ft_atoi(split_line[index]));
		 x_y_z_matrix[i] = malloc(3 * sizeof(int));
		 x_y_z_matrix[i][0] = index * 30 ; //echelle
		 x_y_z_matrix[i][1]	= nbr_lin * 30 ;
		 x_y_z_matrix[i][2] = ft_atoi(split_line[index]);
		i++;
		index++;
	}
	//printf("_%d_" ,i);
	
}

void print_matrix(int **x_y_z_matrix)
{
	int i = 0;
	
	while(x_y_z_matrix[i])
	{
		printf("x %d y %d  z %d \n",x_y_z_matrix[i][0],x_y_z_matrix[i][1],x_y_z_matrix[i][2]);
		i++;
	}
}
int	main(void)
{
 void	*mlx;
//
// t_data img;

 	

	void	*img;
	char	*relative_path = "/Users/ael-oual/Desktop/fdf/test.xpm";
	int		img_width;
	int		img_height;
	void	*mlx_win;
	char	*line;
	char 	**split_line;
	int		**x_y_z_matrix;
	int i = 0;

	x_y_z_matrix = malloc(210 * sizeof(int **));

	int fd = open("42.txt", O_RDONLY);
	int nbr_lin = 0;
	while(1)
	{
		line = get_next_line(fd);
		split_line = ft_split(line, 32);
		if(line == 0)
			break;
		x_y_z_array(split_line, nbr_lin, x_y_z_matrix);
		nbr_lin++;
	}

	
	print_matrix(x_y_z_matrix);
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 900, 900, "Hello world!");
	int color,z;
	
	while(x_y_z_matrix[i])
	{
		color = 0xfbf5fd;
		z = x_y_z_matrix[i][2];
		if (z == 10)
			color = 0x9525ba;
		mlx_string_put(mlx, mlx_win, x_y_z_matrix[i][0], x_y_z_matrix[i][1] , color, ".");
		//mlx_pixel_put(mlx, mlx_win, x_y_z_matrix[i][0], x_y_z_matrix[i][1] , color);
		if(i % 2 == 0) 
		{
			int j;
			j= 0;
		}
		i++;
	}
	int j = 0;
	int y;
	 i = 0;
    int index = 0;
	int x_put= 0;
	int y_put = 0;
	int x_matrix = 0;
	int y_matrix = 0;
	int pix = 0;
//  while (y_put <= 300)
//  {
	color = 0xfbf5fd;
	x_matrix = 19 *2;
	//check_line(x_y_z_matrix, y_put/30);
	y_put = 0;
	while (j < 18 * 30)
	{
		// mlx_string_put(mlx, mlx_win,j, y_put , 0xfbf5fd, ".");
		    printf("matrix  %d ", x_y_z_matrix[j/30][0]);
			mlx_string_put(mlx, mlx_win, j, y_put  , 0x9525ba, ".");
		 
		//  else
	 	
		//mlx_string_put(mlx, mlx_win,y ,j , 0xfbf5fd, ".");
		//mlx_pixel_put(mlx, mlx_win,j ,y , color);
		j++;
	}
	pix = j;
	j = 0;
 	y_put = y_put + 30;
//}
// mlx_loop(mlx);
}
