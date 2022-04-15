/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_centre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:45:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 07:41:20 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include "libft.h"
#include"fdf.h"

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2; // ??
}

void centre_fun(t_data *img)
{
	int i;

	i = 0;
	while (img->x_y_z_matrix[i])
	{
		img->x_y_z_matrix[i][1] = (img->x_y_z_matrix[i][1]) * img -> screnn.z_index + img -> r.tr_x;
		img->x_y_z_matrix[i][2] = (img->x_y_z_matrix[i][2]) * img -> screnn.z_index + img -> r.tr_y;
		i++;
	}
}

void isometric_projection(t_data *img)
{
	int line_number;
	int n_points;
	int x;
	int y;
	char c;
	double angle;
	
	// if (c == 'i')
	// 	angle = 1;
	// else
	// 	angle = 0.790211;
	
	c = 'p';
	line_number = 0;
	while ( img -> x_y_z_matrix[line_number])
	{ 
		if (img-> screnn.type_of == 'i')
		{
			x = ((img->x_y_z_matrix[line_number][1] - img->x_y_z_matrix[line_number][2])); 
			y = ((img->x_y_z_matrix[line_number][1] + (img->x_y_z_matrix[line_number][2])) - img->x_y_z_matrix[line_number][3]);
			img->x_y_z_matrix[line_number][1] = x ;
			img->x_y_z_matrix[line_number][2] = y ;
		}
		else if (img-> screnn.type_of == 'p')
		{
				// *x = (*x - z * cos(0.7854)) * data.zoom + data.start_x;
				// *y = (*y - z * sin(0.7854)) * data.zoom + data.start_y;
			img -> x_y_z_matrix[line_number][1] = img->x_y_z_matrix[line_number][1] - (img->x_y_z_matrix[line_number][3] * cos(0.7854));
		 	img -> x_y_z_matrix[line_number][2] = img->x_y_z_matrix[line_number][2] - (img->x_y_z_matrix[line_number][3] * sin(0.7854));
			
		    //img->x_y_z_matrix[line_number][2] = x ;
		}
		
		line_number++;
	}
	// norminette
	// library
	// futer me
	// printf

	// int i;
	// int s;
	// i = 0;
	// y = 0;
	// while (img -> x_y_z_matrix[i])
	// {
	//      s  = (img->x_y_z_matrix[line_number][1] - img->x_y_z_matrix[line_number][2]) * cos(0.790211);
	// 	img -> x_y_z_matrix[i][3] = ((img->x_y_z_matrix[line_number][1] + img->x_y_z_matrix[line_number][2]) * sin(0.790211) - img->x_y_z_matrix[line_number][3]);
	// 	i++;  
	// }
	// img->x_y_z_matrix[line_number][2] = s;
	centre_fun(img);
	drawing_points(img);
}