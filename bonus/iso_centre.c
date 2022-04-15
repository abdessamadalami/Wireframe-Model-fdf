/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_centre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:45:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 07:57:37 by ael-oual         ###   ########.fr       */
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
	while (img->xyz_m[i])
	{
		img->xyz_m[i][1] = (img->xyz_m[i][1]) * img -> screnn.z_index + img -> r.tr_x;
		img->xyz_m[i][2] = (img->xyz_m[i][2]) * img -> screnn.z_index + img -> r.tr_y;
		i++;
	}
}

void isometric_projection(t_data *img)
{
	int l_nbr;
	int x;
	int y;
	
	l_nbr = 0;
	while ( img -> xyz_m[l_nbr])
	{ 
		if (img-> screnn.type_of == 'i')
		{
			x = ((img->xyz_m[l_nbr][1] - img->xyz_m[l_nbr][2])); 
			y = ((img->xyz_m[l_nbr][1] + (img->xyz_m[l_nbr][2])) - img->xyz_m[l_nbr][3]);
			img->xyz_m[l_nbr][1] = x;
			img->xyz_m[l_nbr][2] = y;
		}
		else if (img-> screnn.type_of == 'p')
		{
			img -> xyz_m[l_nbr][1] = img->xyz_m[l_nbr][1] - (img->xyz_m[l_nbr][3] * cos(0.7854));
		 	img -> xyz_m[l_nbr][2] = img->xyz_m[l_nbr][2] - (img->xyz_m[l_nbr][3] * sin(0.7854));
		}
		l_nbr++;
	}
	centre_fun(img);
	drawing_points(img);
}