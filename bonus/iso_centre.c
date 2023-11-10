/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_centre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:45:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/23 06:27:54 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include"fdf.h"

int	max(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

void	parallel_fun(int *x, int *y, int *z)
{
	*x = *x - *z * cos(0.7854);
	*y = *y - *z * sin(0.7854);
}

void	isometric_projection(t_data *img)
{
	int	l_nbr;
	int	x;
	int	y;

	l_nbr = 0;
	while (l_nbr < img -> n_points)
	{
		if (img-> screnn.type_of == 'i')
		{
			x = ((img->xyz_m[l_nbr][1] - img->xyz_m[l_nbr][2]) * cos(0.523599)
					* img -> screnn.z_index + img -> r.tr_x);
			y = ((img->xyz_m[l_nbr][1] + (img->xyz_m[l_nbr][2]))
					- img->xyz_m[l_nbr][3])
				* sin(0.523599) * img -> screnn.z_index + img -> r.tr_y;
			img->xyz_m[l_nbr][1] = x;
			img->xyz_m[l_nbr][2] = y;
		}
		else if (img-> screnn.type_of == 'p')
			parallel_fun(&img->xyz_m[l_nbr][1], &img -> xyz_m[l_nbr][2],
				&img->xyz_m[l_nbr][3]);
		l_nbr++;
	}
	drawing_points(img);
}
