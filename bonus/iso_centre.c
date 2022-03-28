/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_centre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:45:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/27 18:01:55 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include "libft.h"
#include"fdf.h"

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2; // ??
}

void centre_fun(int **x_y_z_matrix,int min_x,int max_x , int min_y , int  max_y)
{
	int i;
	int add;
	int echelle_x;// add max because change in x after;
	int echelle_y;

	i =  0;
	add = max(abs(min_y),abs(min_x));
	echelle_x = 1000/(abs(min_x) + max_x);// add max because change in x after;
	echelle_y = 1000/(abs(min_y) + max_y);
	while (x_y_z_matrix[i])
	{
		// (2000 - (abs(min_x) + max_x) * echelle_x)/2
		//(1500 - (abs(min_y) + max_y) * echelle_y)/2
		x_y_z_matrix[i][1] = (x_y_z_matrix[i][1] + abs(min_x)) * echelle_x + (2000 - (abs(min_x) + max_x) * echelle_x)/2;//echlle in x
		x_y_z_matrix[i][2] = (x_y_z_matrix[i][2] + abs(min_y)) * echelle_y + (1500 - (abs(min_y) + max_y) * echelle_y)/2;//echlle in y
		i++;
	}
   	
}

void isometric_projection(int **x_y_z_matrix, int length_line, int n_points,t_data *img)
{
	int line_number;
	int **x_y_z_old;
	int x;
	int y;
	
	line_number = 0;
	int min_x,max_x,max_y,min_y;
	min_x = max_x = max_y = min_y = 0;
	printf(" n lasd %d ",n_points);
	img -> x_y_z_old = malloc(n_points * sizeof(int **));
	while (line_number < n_points)
	{ 
		img -> x_y_z_old[line_number] = malloc(5 * sizeof(int));
		img -> x_y_z_old[line_number][0] = x_y_z_matrix[line_number][0];
		img ->  x_y_z_old[line_number][1] = x_y_z_matrix[line_number][1];
		img ->  x_y_z_old[line_number][2] = x_y_z_matrix[line_number][2];
		img ->  x_y_z_old[line_number][3] = x_y_z_matrix[line_number][3];
		x = ((x_y_z_matrix[line_number][1] - x_y_z_matrix[line_number][2])); //* 10 + 300 for cancel negative number
		 if (x < min_x && x < 0)
			min_x = x; // +300
		 if (x > max_x)
			max_x = x;	 
		y = ((x_y_z_matrix[line_number][1] + (x_y_z_matrix[line_number][2])) - x_y_z_matrix[line_number][3]);
		if (y < min_y && y < 0)
			min_y = y;
		if (y > max_y)
			max_y = y;
		x_y_z_matrix[line_number][1] = x;
		x_y_z_matrix[line_number][2] = y;
		line_number++;
	}
	img -> x_y_z_matrix = x_y_z_matrix;
	centre_fun(img-> x_y_z_matrix, min_x, max_x, min_y, max_y);

}