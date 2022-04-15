/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   briesnham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 08:09:01 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include"fdf.h"


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

void x_y_z_c_function(char **split_line, int nbr_lin,int **xyz_m)
{
	int index;
	char **split_z;
	static int i;
	
	index = 0;
	while(split_line[index] != 0)
	{
		 xyz_m[i] = malloc(5 * sizeof(int));
		 xyz_m[i][0] = i; 
		 xyz_m[i][1] = index ; //echelle
		 xyz_m[i][2]	= nbr_lin; 
		 split_z = ft_split(split_line[index],',');
		
		if (split_z[0] != 0)
			xyz_m[i][3] = ft_atoi(split_z[0]);
		if (split_z[1] != 0)
			xyz_m[i][4] = to_decimal(split_z[1]);
		else
			xyz_m[i][4] = 0x49eb34;
		i++;
		index++;
	}
}
t_point to_stract( int x1, int y1 ,int x2 ,int y2)
{
	t_point ab;

	ab.x0 = x1;
	ab.y0 = y1;
	ab.x1 = x2;
	ab.y1 = y2;
	return ab;
}

void hory_point(int index, int l_line ,int **xyz_m ,int color ,t_data *img)
{
	t_point ab;

	if( index > 0 && index % l_line != 0)
	{
		if (xyz_m[index][3] > 0 && xyz_m[index - 1][3] > 0 && xyz_m[index][4] == 0x49eb34)
			color = 0xe3091b ;
		else
			color = xyz_m[index][4];
		ab = to_stract(xyz_m[index - 1][1],xyz_m[index - 1][2], xyz_m[index][1],xyz_m[index][2]);
		bre_algori(ab, color , img);
	}
	if (index < img->n_points -l_line)
	{
		if (xyz_m[index][3] > 0 && xyz_m[index + l_line][3] > 0 && xyz_m[index][4] == 0x49eb34)
			color = 0xe3091b;
		else
			color = xyz_m[index][4];
		ab = to_stract(xyz_m[index][1],xyz_m[index][2],xyz_m[index + l_line][1],xyz_m[index + l_line][2]);
		bre_algori(ab,color,img);
	}
}

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 53)
		exit(0);
	printf(" %d \n",keycode); // + == 69 - = 78
	return (0);
}
void drawing_points(int **xyz_m , int length_line , int n_points)
{
	int		color;
	int		index;
	t_data	img;
	
	img.mlx = mlx_init();
	img.m_win = mlx_new_window(img.mlx, 2000,1500, "FDF :)");
	img.img = mlx_new_image(img.mlx, 2000, 1500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	img.n_points = n_points;
	index = 0;
	color = 0x1cc738;
	img.xyz_m = xyz_m;
	while (xyz_m[index])
	{
		if( index > 0 && index % length_line != 0)
			hory_point(index, length_line, xyz_m , color,&img);
		if (index < n_points -length_line)
			hory_point(index, length_line, xyz_m , color,&img);
		index++;
	}
	mlx_put_image_to_window(img.mlx, img.m_win, img.img, 0, 0);
	mlx_key_hook(img.m_win, key_hook, &img);
	mlx_loop(img.mlx);	
}