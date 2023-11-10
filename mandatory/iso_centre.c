/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_centre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:45:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/26 13:12:48 by ael-oual         ###   ########.fr       */
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

void	inisialise(t_data *img, int x, int y)
{
	img -> screnn.max_x = x;
	img -> screnn.min_x = x;
	img -> screnn.max_y = y;
	img -> screnn.min_y = y;
}

void	min_max_fun(int *x, int *y, t_data *img)
{
	static int	i = 0;

	if (i == 0)
		inisialise(img, *x, *y);
	if (img-> screnn.max_x < *x)
		img->screnn.max_x = *x;
	if (img-> screnn.max_y < *y)
		img->screnn.max_y = *y;
	if (img-> screnn.min_x > *x)
		img->screnn.min_x = *x;
	if (img-> screnn.min_y > *y)
		img->screnn.min_y = *y;
	i++;
}

void	centre_fun(t_data *img)
{
	int	i;
	int	add;
	int	e_x;
	int	e_y;

	i = 0;
	add = max(abs(img->screnn.min_y), abs(img->screnn.min_x));
	e_x = 1000 / (abs(img->screnn.min_x) + img->screnn.max_x);
	e_y = 1000 / (abs(img->screnn.min_y) + img->screnn.max_y);
	while (i < img-> n_points)
	{
		img->xyz_m[i][1] = (img->xyz_m[i][1] + abs(img->screnn.min_x)) * e_x
			+(img -> screnn.x_length
				- (abs(img->screnn.min_x) + img->screnn.max_x) * e_x) / 2;
		img->xyz_m[i][2] = (img->xyz_m[i][2] + abs(img->screnn.min_y)) * e_y
			+ (img -> screnn.y_length
				- (abs(img->screnn.min_y) + img->screnn.max_y) * e_y) / 2;
		i++;
	}
}

void	isometric_projection(t_data *img)
{
	int	l_nbr;
	int	x;
	int	y;

	l_nbr = 0;
	while (l_nbr < img-> n_points)
	{
		x = ((img->xyz_m[l_nbr][1] - img->xyz_m[l_nbr][2]));
		y = ((img->xyz_m[l_nbr][1] + (img->xyz_m[l_nbr][2]))
				- img->xyz_m[l_nbr][3]);
		img->xyz_m[l_nbr][1] = x;
		img->xyz_m[l_nbr][2] = y;
		min_max_fun(&img->xyz_m[l_nbr][1], &img->xyz_m[l_nbr][2], img);
		l_nbr++;
	}
	centre_fun(img);
	drawing_points(img);
}
