/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_centre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:45:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/05 14:39:18 by ael-oual         ###   ########.fr       */
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
		img ->  x_y_z_old[line_number] = malloc(6 * sizeof(int));
		img ->  x_y_z_old[line_number][0] = img -> x_y_z_matrix[line_number][0];
		img ->  x_y_z_old[line_number][1] = img -> x_y_z_matrix[line_number][1];
		img ->  x_y_z_old[line_number][2] = img -> x_y_z_matrix[line_number][2];
		img ->  x_y_z_old[line_number][3] = img -> x_y_z_matrix[line_number][3];
		img ->  x_y_z_old[line_number][4] = img -> x_y_z_matrix[line_number][4];
		img ->  x_y_z_old[line_number][5] = img -> x_y_z_matrix[line_number][5];

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
		img->x_y_z_matrix[i][1] = (img->x_y_z_matrix[i][1] + abs(img->screnn.min_x)) * echelle_x + (2000 - (abs(img->screnn.min_x) + img->screnn.max_x) * echelle_x)/2;//echlle in x
		img->x_y_z_matrix[i][2] = (img->x_y_z_matrix[i][2] + abs(img->screnn.min_y)) * echelle_y + (1500 - (abs(img->screnn.min_y) +img->screnn. max_y) * echelle_y)/2;//echlle in y
		i++;
	}
}

void isometric_projection(t_data *img)
{
	int line_number;
	int n_points;
	int x;
	int y;
	
	line_number = 0;
	while (line_number < img->n_points)
	{ 
		x = ((img->x_y_z_matrix[line_number][1] - img->x_y_z_matrix[line_number][2])); //* 10 + 300 for cancel negative number
		if (x < img -> screnn.min_x && x < 0)
			img -> screnn.min_x = x; // +300
		if (x > img -> screnn.max_x)
			img -> screnn.max_x = x;
		y = ((img->x_y_z_matrix[line_number][1] + (img->x_y_z_matrix[line_number][2])) - img->x_y_z_matrix[line_number][3]);
		if (y < img -> screnn.min_y && y < 0)
			img -> screnn.min_y = y;
		if (y > img -> screnn.max_y)
			img -> screnn.max_y = y;
		img->x_y_z_matrix[line_number][1] = x;
		img->x_y_z_matrix[line_number][2] = y;
		line_number++;
	}
	centre_fun(img);
	//print_matrix(img -> x_y_z_matrix);
	drawing_points(img);
}