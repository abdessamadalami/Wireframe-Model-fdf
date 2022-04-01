/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_centre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:45:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/01 08:46:21 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include "libft.h"
#include"fdf.h"

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2; // ??
}

void copy_d(t_data *img)
{
	int line_number;

	line_number = 0;
	img -> x_y_z_old = malloc(img -> n_points * sizeof(int **));
	while (line_number < img -> n_points)
	{ 
		img ->  x_y_z_old[line_number] = malloc(5 * sizeof(int));
		img ->  x_y_z_old[line_number][0] = img -> x_y_z_matrix[line_number][0];
		img ->  x_y_z_old[line_number][1] = img -> x_y_z_matrix[line_number][1];
		img ->  x_y_z_old[line_number][2] = img -> x_y_z_matrix[line_number][2];
		img ->  x_y_z_old[line_number][3] = img -> x_y_z_matrix[line_number][3];
		line_number++;
	}
}
void centre_fun(t_data *img)
{
	int i;
	int add;
	int echelle_x;// add max because change in x after;
	int echelle_y;

	i =  0;
	add = max(abs(img->screnn.min_y),abs(img->screnn.min_x));
	echelle_x = img->screnn.zoom_x/(abs(img->screnn.min_x) + img->screnn.max_x);// add max because change in x after;
	echelle_y = img->screnn.zoom_y/(abs(img->screnn.min_y) + img->screnn.max_y);
	while (img->x_y_z_matrix[i])
	{
		// (2000 - (abs(min_x) + max_x) * echelle_x)/2
		// (1500 - (abs(min_y) + max_y) * echelle_y)/2 / the other thinks oppsit
		img->x_y_z_matrix[i][1] = (img->x_y_z_matrix[i][1] + abs(img->screnn.min_x)) * echelle_x + (2000 - (abs(img->screnn.min_x) + img->screnn.max_x) * echelle_x)/2;//echlle in x
		img->x_y_z_matrix[i][2] = (img->x_y_z_matrix[i][2] + abs(img->screnn.min_y)) * echelle_y + (1500 - (abs(img->screnn.min_y) +img->screnn. max_y) * echelle_y)/2;//echlle in y
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
	copy_d(img);
	printf(" n lasd %d ",n_points);
	while (line_number < n_points)
	{ 
		x = ((x_y_z_matrix[line_number][1] - x_y_z_matrix[line_number][2])); //* 10 + 300 for cancel negative number
		if (x < img -> screnn.min_x && x < 0)
			img -> screnn.min_x = x; // +300
		if (x > img -> screnn.max_x)
			img -> screnn.max_x = x;
		y = ((x_y_z_matrix[line_number][1] + (x_y_z_matrix[line_number][2])) - x_y_z_matrix[line_number][3]);
		if (y < img -> screnn.min_y && y < 0)
			img -> screnn.min_y = y;
		if (y > img -> screnn.max_y)
			img -> screnn.max_y = y;
		x_y_z_matrix[line_number][1] = x;
		x_y_z_matrix[line_number][2] = y;
		line_number++;
	}
	img -> x_y_z_matrix = x_y_z_matrix;
	centre_fun(img);
}