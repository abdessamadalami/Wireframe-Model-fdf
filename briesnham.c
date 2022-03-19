/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   briesnham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/19 19:36:00 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void x_y_z_c_function(char **split_line, int nbr_lin,int **x_y_z_matrix)
{
	int index;
	static int i;
	index = 0;
	
	while(split_line[index] != 0)
	{
		 x_y_z_matrix[i] = malloc(4 * sizeof(int));
		 x_y_z_matrix[i][0] = i; 
		 x_y_z_matrix[i][1] = index  ; //echelle
		 x_y_z_matrix[i][2]	= nbr_lin ;
		 x_y_z_matrix[i][3] = ft_atoi(split_line[index]);
		 x_y_z_matrix[i][4] = 0;
		 i++;
		 index++;
	}
}

void isometric_projection(int **x_y_z_matrix, int length_line, int n_points)
{
	int line_number;
	int x;
	int y;
	
	line_number = 0;
	int w = n_points / length_line;
	//printf("t <%d> L <%d> ",w ,length_line);
	while (line_number < n_points)
	{ 
		x = ((x_y_z_matrix[line_number][1] - x_y_z_matrix[line_number][2])) * 10 * 3  + 800; // we must change this to index for get a dynamically  f logic thanks :) 
		y = ((x_y_z_matrix[line_number][1] + (x_y_z_matrix[line_number][2])) * 11 + 300) - x_y_z_matrix[line_number][3];
		printf("x %d y %d \n", x,y);
		x_y_z_matrix[line_number][1] = x;
		x_y_z_matrix[line_number][2] = y;
		line_number++;
	}
}

void drawing_points(int **x_y_z_matrix , int length_line , int n_points)
{
	int		color;
	int		line_number;
	void 	*mlx_win;
	void	*mlx;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2000,1020, "FDF :)");
	line_number = 0;
	color = 0x1cc738;;
	while (x_y_z_matrix[line_number])
	{
		if( line_number > 0 && line_number % length_line != 0)
		{
			if (x_y_z_matrix[line_number][3] > 0 && x_y_z_matrix[line_number - 1][3] > 0)
				color = 0xed0c0c;
			else
				color = 0x1cc738;
			bre_algori(mlx, mlx_win, x_y_z_matrix[line_number - 1][1],x_y_z_matrix[line_number - 1][2],x_y_z_matrix[line_number][1],x_y_z_matrix[line_number][2], color);
		}
		if (line_number < n_points -length_line)
		{
			if (x_y_z_matrix[line_number][3] > 0 && x_y_z_matrix[line_number + length_line][3] > 0)
				color = 0xed0c0c;
			else
				color = 0x1cc738;
			bre_algori(mlx, mlx_win, x_y_z_matrix[line_number][1],x_y_z_matrix[line_number][2], x_y_z_matrix[line_number + length_line][1],x_y_z_matrix[line_number + length_line][2],color);
		}
		line_number++;
	}
	 mlx_loop(mlx);
}

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
	int		**x_y_z_matrix;
	int		line_number;
	int		fd;
	int		nbr_lin;
	int		length_line;
	char *line;
	t_list	*list_line;
	t_list	*node;
	
	fd = open(argv[1], O_RDONLY);
	nbr_lin = 0;
	
	if (argc != 2)
	{
		printf("<>|<>\n");
		printf(" <i>\n");
		return (1);
	}
	list_line = 0;
	
	nbr_lin	  = 0;
	while (1)
	{
		line = get_next_line(fd);
	    node = ft_lstnew(line);
		ft_lstadd_back(&list_line, node);
		if (line == 0)
			break ;
		nbr_lin++;
	}
	line_number = 0;
	length_line = 0;
	x_y_z_matrix = check_list(list_line , &length_line);
	//print_matrix(x_y_z_matrix);
	//printf("  __________ %d", length_line * nbr_lin);
	int n_points = length_line * nbr_lin;
	isometric_projection(x_y_z_matrix, length_line,n_points);
	drawing_points(x_y_z_matrix, length_line, n_points);
}
