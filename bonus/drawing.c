/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/06 15:00:13 by ael-oual         ###   ########.fr       */
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




t_point to_stract( t_data *img,int index,char type)
{
	t_point ab;

	if(type == 'l')
	{
		ab.x0 = img-> x_y_z_matrix[index -1][1];
		ab.y0 = img -> x_y_z_matrix[index - 1][2];//color
		ab.color_0 = img -> x_y_z_matrix[index - 1][4];
		ab.x1 = img  -> x_y_z_matrix[index][1];
		ab.y1 = img ->x_y_z_matrix[index][2];
		ab.color_1 = img -> x_y_z_matrix[index][4];
	}
	if(type == 'c')
	{
		ab.x0 = img-> x_y_z_matrix[index][1];
		ab.y0 = img -> x_y_z_matrix[index][2];//color
		ab.color_0 = img -> x_y_z_matrix[index][4];
		ab.x1 = img  -> x_y_z_matrix[index + img -> l_length][1];
		ab.y1 = img ->x_y_z_matrix[index + img -> l_length][2];
		ab.color_1 = img -> x_y_z_matrix[index + img -> l_length][4];
	}
	return ab;
}

void hory_point(int index, int l_line ,int **x_y_z_matrix ,t_data *img)
{
	t_point ab;

	if( index > 0 && index % l_line != 0)
	{
		ab = to_stract(img,index,'l');
		bre_algori(ab , img , x_y_z_matrix[index - 1][3],x_y_z_matrix[index][3]);
	}
	if (index < img->n_points -l_line)
	{
		ab = to_stract(img ,index,'c');
		bre_algori(ab,img, x_y_z_matrix[index][3], x_y_z_matrix[index + img -> l_length][3]);
	}
}

void drawing_points(t_data *img)
{
	int		index;

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,&img->endian);
	index = 0;

	while (img->x_y_z_matrix[index])
	{
		if( index > 0 && index % img -> l_length != 0)
			hory_point(index, img -> l_length , img->x_y_z_matrix ,img);
		if (index < img->n_points - img -> l_length)
			hory_point(index, img -> l_length, img->x_y_z_matrix ,img);
		index++;
		// if (index == 36)
		// 	break;	
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);	
}