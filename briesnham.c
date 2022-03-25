/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   briesnham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/24 15:20:58 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include <math.h>



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_strchr_int(const char *str, int c)
{
	const char	*s;
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}	
		return (0);
}

int to_decimal(char *str)
{
	int i;
	char c;
	int nbr;
	int len;
	char *hix="0123456789abcdef";
	
	i = 0; 
	c = 0;
	nbr = 0;
	if (str[0] == '0' && str[1] == 'x')
		str = str + 2;
 	len = ft_strlen(str) - 1;
	while(str[i] != '\0')
	{
		c =  ft_tolower(str[i]);
		nbr = nbr + ft_strchr_int(hix, c) * pow(16, len);
		i++;
		len--;
	}
	return nbr;
}

void x_y_z_c_function(char **split_line, int nbr_lin,int **x_y_z_matrix)
{
	int index;
	char **split_z;
	static int i;
	
	index = 0;
	while(split_line[index] != 0)
	{
		 x_y_z_matrix[i] = malloc(5 * sizeof(int));
		 x_y_z_matrix[i][0] = i; 
		 x_y_z_matrix[i][1] = index ; //echelle
		 x_y_z_matrix[i][2]	= nbr_lin; 
		 split_z = ft_split(split_line[index],',');
		
		if (split_z[0] != 0)
			x_y_z_matrix[i][3] = ft_atoi(split_z[0]);
		if (split_z[1] != 0)
		{
			x_y_z_matrix[i][4] = to_decimal(split_z[1]);
		}	
		else
			x_y_z_matrix[i][4] = 0x49eb34;
		i++;
		index++;
	}
	//print_matrix(x_y_z_matrix);
}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2; // ??
}

void isometric_projection(int **x_y_z_matrix, int length_line, int n_points)
{
	int line_number;
	int x;
	int y;
	
	line_number = 0;
	int w = n_points / length_line;
	//printf("t <%d> L <%d> ",w ,length_line);
	int min_x,max_x,max_y,min_y;
	min_x = max_x = max_y = min_y = 0;
	int rotation_index = 1;
	int cam = 12;
	while (line_number < n_points)
	{ 
		x = ((x_y_z_matrix[line_number][1] - x_y_z_matrix[line_number][2])); //* 10 + 300 for cancel negative number
		 if (x < min_x && x < 0)
			min_x = x; // +300
		 if (x > max_x)
			max_x = x;	 
	 // we must change this to index for get a dynamically  f logic thanks :) 
		y = ((x_y_z_matrix[line_number][1] + (x_y_z_matrix[line_number][2]) * -12) - x_y_z_matrix[line_number][3]); //+300 for to down in y * 11 and tjpd lmap 
		 if (y < min_y && y < 0)
			min_y = y; // +300
		 if (y > max_y)
			max_y = y;
		x_y_z_matrix[line_number][1] = x;
		x_y_z_matrix[line_number][2] = y;
		line_number++;
	}
	printf("max x  %d max y %d \n", max_x ,max_y);
	
	int add = max(abs(min_y),abs(min_x));
	int echelle_x = 1000/(abs(min_x) + max_x);// add max because change in x after;
	int echelle_y = 1000/(abs(min_y) + max_y);
	printf("max x  %d max y %d \n", (2000 - (abs(min_x) + max_x) * echelle_x)/2 ,(1500 - (abs(min_y) + max_y) * echelle_y)/2);
	line_number = 0;
	while (line_number < n_points)
	{ 
		x_y_z_matrix[line_number][1] = (x_y_z_matrix[line_number][1] + abs(min_x)) * echelle_x + (2000 - (abs(min_x) + max_x) * echelle_x)/2;//echlle in x
		x_y_z_matrix[line_number][2] = (x_y_z_matrix[line_number][2] + abs(min_y)) * echelle_y + (1500 - (abs(min_y) + max_y) * echelle_y)/2;//echlle in y
		line_number++;
	}
	print_matrix(x_y_z_matrix);
}

void drawing_points(int **x_y_z_matrix , int length_line , int n_points)
{
	int		color;
	int		line_number;
	void 	*mlx_win;
	void	*mlx;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2000,1500, "FDF :)");
	line_number = 0;
	color = 0x1cc738;;
	while (x_y_z_matrix[line_number])
	{
		if( line_number > 0 && line_number % length_line != 0)
		{
			if (x_y_z_matrix[line_number][3] > 0 && x_y_z_matrix[line_number - 1][3] > 0  && x_y_z_matrix[line_number][4] == 0x49eb34)
				color = 0xe3091b ;
			else
				color = x_y_z_matrix[line_number][4];
			bre_algori(mlx, mlx_win, x_y_z_matrix[line_number - 1][1],x_y_z_matrix[line_number - 1][2],x_y_z_matrix[line_number][1],x_y_z_matrix[line_number][2], color);
		}
		if (line_number < n_points -length_line)
		{
			if (x_y_z_matrix[line_number][3] > 0 && x_y_z_matrix[line_number + length_line][3] > 0 && x_y_z_matrix[line_number][4] == 0x49eb34)
				color = 0xe3091b;
			else
				color = x_y_z_matrix[line_number][4];
			bre_algori(mlx, mlx_win, x_y_z_matrix[line_number][1],x_y_z_matrix[line_number][2], x_y_z_matrix[line_number + length_line][1],x_y_z_matrix[line_number + length_line][2],color);
		}
		line_number++;
	}
	mlx_loop(mlx);
}


void erros_functions(char **argv)
{
	int length;
	
	length = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".fdf",argv[1] + length,5) != 0 )
	{
		ft_putstr_fd(" Error ./fdf",2);
		exit(1);
	}
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
	if (fd == -1)
	{
		perror(argv[1]);
		exit(0);
	}
	nbr_lin = 0;
	if (argc != 2)
	{
		printf(" <filename .fdf> \n");
		return (1);
	}
	erros_functions(argv);
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
	length_line = 0;
	x_y_z_matrix = check_list(list_line , &length_line);
	//print_matrix(x_y_z_matrix);
	// printf("  __________ %d", length_line * nbr_lin);
	int n_points = length_line * nbr_lin;
	isometric_projection(x_y_z_matrix, length_line,n_points);
	drawing_points(x_y_z_matrix, length_line, n_points);
}
