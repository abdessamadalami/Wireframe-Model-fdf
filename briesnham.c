/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   briesnham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/17 18:11:35 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
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

int *bre_algori(void *mlx,void *mlx_win,int x1, int y1, int x2, int y2, int coler)
{
	int dx;
	int dy;
	int p;
	int yi = 1;
	int **tab;
	
	if(x1 > x2)
		bre_algori(mlx,mlx_win, x2,y2, x1, y1,coler);
	dx = x2 - x1; //negative numbres 
	dy = y2 - y1;
	if (dy < 0)
	{
		yi = -1;
		dy = abs(dy);
	}
	p = 2 * dy - dx;
	//printf("A (%d,%d) B(%d ,%d)\n",x1,y1,x2,y2);
	while(x1 <= x2)
	{
		mlx_pixel_put(mlx, mlx_win ,x1 ,y1 , coler);
		//printf("( %d , %d ) p = %d \n", x1,y1,p);
		x1++;
		if (p < 0)
			p = p + 2 * dy;
		else
			{
				p = p + 2 * dy - 2 * dx;
				y1 = y1 + yi; 
			}
	}
	return 0;
}

void x_y_z_array(char **split_line, int nbr_lin,int **x_y_z_matrix,t_list **points_list)
{
	static int i;
	int index;
	index = 0;
	
	while(split_line[index] != 0)
	{
		 x_y_z_matrix[i] = malloc(4 * sizeof(int));
		 x_y_z_matrix[i][0] = i; 
		 x_y_z_matrix[i][1] = index  ; //echelle
		 x_y_z_matrix[i][2]	= nbr_lin ;
		 x_y_z_matrix[i][3] = ft_atoi(split_line[index]);
		 i++;
		 index++;
	}
}

void print_matrix(int **x_y_z_matrix)
{
	int i = 0;
	
	while(x_y_z_matrix[i])
	{
		printf(" index  %d x %d y %d  z %d \n",x_y_z_matrix[i][0],x_y_z_matrix[i][1],x_y_z_matrix[i][2],x_y_z_matrix[i][3]);
		i++;
	}
}

int ft_strlen_d(char **arr_split)
{
	int index;

	index = 0;
	while(arr_split[index] != 0)
		index++;
	return index;
}

void print_f(char **x_y_z_matrix)
{
	int i = 0;
	
	while(x_y_z_matrix[i])
	{
		printf(" split of content  %s  \n",x_y_z_matrix[i]);
		i++;
	}
}
//we must call for use it
int  *array_split(char **split_arr ,int size) //split array in defirrent time u get the , for get coler
{
	int i = 0;
	int *z_array;
	
	
	while (split_arr[i])
	{
		z_array[i] = ft_atoi(split_arr[i]);
		i++;
	}
	return (z_array);
}
int	main(int argc ,char **argv)
{
	void	*mlx;
	int 	x_put= 0;
	int 	y_put = 0;
	void	*img;
	void	*mlx_win;
	char	*line;
	char 	**split_line;
	int		**x_y_z_matrix;
	int		**x_y_z_c_matrix;
	int		i;
	int		line_number;
	int		color;
	int		fd;
	int		nbr_lin;
	int		x;
	int		y;
	int 	size = 208;
	int		length_line;
	t_list	*list_line;
	
	color = 0x1cc738;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "FDF :)");
	x_y_z_matrix = malloc(210 * sizeof(int **)); // you need the numbers of points in the map for allocat arr or add pack to linked list ?  or the lined list + array
	fd = open(argv[1], O_RDONLY);
	nbr_lin = 0;
	t_list *lst;
	
	if (argc != 2)
	{
		printf("<>|<>\n");
		printf(" <i>\n");
		return (1);
	}
	list_line = 0;
	t_list *node;
	int index ;
	index = 0;
	while (1)
	{
		line = get_next_line(fd);
	    node = ft_lstnew(line);
		ft_lstadd_back(&list_line, node);
		if (line == 0)
			break ;
		split_line = ft_split(line, 32);//
		length_line = ft_strlen_d(split_line);
		x_y_z_array(split_line, nbr_lin, x_y_z_matrix, &list_line);
		nbr_lin++;
		index++;
	}
	line_number = 0;
//	check_list(list_line);
	//print_linked_list(list_line);
	while (line_number <= 208)
	{ 
		x = ((x_y_z_matrix[line_number][1] - x_y_z_matrix[line_number][2])) * 20 + 500;
		y = ((x_y_z_matrix[line_number][1] + x_y_z_matrix[line_number][2])) * 10 - x_y_z_matrix[line_number][3];
		//	printf("x %d y %d \n", x,y);
		x_y_z_matrix[line_number][1] = x;
		x_y_z_matrix[line_number][2] = y;
		line_number++;
	}
	line_number = 0;
	color = 0x1cc738;;
	while (line_number <= 208)
	{
		if( line_number > 0 && line_number % 19 != 0)
		{
			if (x_y_z_matrix[line_number][3] == 10 && x_y_z_matrix[line_number - 1][3] == 10)
				color = 0xed0c0c;
			else
				color = 0x1cc738;			
			bre_algori(mlx, mlx_win, x_y_z_matrix[line_number - 1][1],x_y_z_matrix[line_number - 1][2],x_y_z_matrix[line_number][1],x_y_z_matrix[line_number][2], color);
		}
		if (line_number <= 208 -19)
		{
			if (x_y_z_matrix[line_number][3] == 10 && x_y_z_matrix[line_number + 19][3] == 10)
				color = 0xed0c0c;
			else
				color = 0x1cc738;
			bre_algori(mlx, mlx_win, x_y_z_matrix[line_number][1],x_y_z_matrix[line_number][2], x_y_z_matrix[line_number + 19][1],x_y_z_matrix[line_number + 19][2],color);
		}
		line_number++;
	}
 mlx_loop(mlx);
}
