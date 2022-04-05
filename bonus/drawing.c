/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/05 16:44:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include"fdf.h"



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




t_point to_stract( int x1, int y1 ,int x2 ,int y2)
{
	t_point ab;

	ab.x0 = x1;
	ab.y0 = y1;//color
	ab.x1 = x2;
	ab.y1 = y2;
	return ab;
}

void hory_point(int index, int l_line ,int **x_y_z_matrix ,int color ,t_data *img)
{
	t_point ab;

	if( index > 0 && index % l_line != 0)
	{
		if (x_y_z_matrix[index][3] > 0 && x_y_z_matrix[index - 1][3] > 0 && x_y_z_matrix[index][4] == 0x49eb34)
			color = 0xe3091b ;
		else
			color = x_y_z_matrix[index][4];
		ab = to_stract(x_y_z_matrix[index - 1][1],x_y_z_matrix[index - 1][2], x_y_z_matrix[index][1],x_y_z_matrix[index][2]);
		bre_algori(ab, color , img);
	}
	if (index < img->n_points -l_line)
	{
		if (x_y_z_matrix[index][3] > 0 && x_y_z_matrix[index + l_line][3] > 0 && x_y_z_matrix[index][4] == 0x49eb34)
			color = 0xe3091b;
		else
			color = x_y_z_matrix[index][4];
		ab = to_stract(x_y_z_matrix[index][1],x_y_z_matrix[index][2],x_y_z_matrix[index + l_line][1],x_y_z_matrix[index + l_line][2]);
		bre_algori(ab,color,img);
	}
}

void drawing_points(t_data *img)
{
	int		color;
	int		index;

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,&img->endian);
	index = 0;
	color = 0x1cc738;

	while (img->x_y_z_matrix[index])
	{
		if( index > 0 && index % img -> l_length != 0)
			hory_point(index, img -> l_length , img->x_y_z_matrix , color,img);
		if (index < img->n_points - img -> l_length)
			hory_point(index, img -> l_length, img->x_y_z_matrix , color,img);
		index++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);	
}