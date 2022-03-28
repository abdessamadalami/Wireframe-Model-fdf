/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   briesnham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/28 06:43:25 by ael-oual         ###   ########.fr       */
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

void x_y_z_c_function(char **split_line, int nbr_lin,int **x_y_z_matrix)
{
	int index;
	char **split_z;
	static int i;
	
	index = 0;
	while(split_line[index] != 0)
	{
		 x_y_z_matrix[i] = malloc(5 * sizeof(int));
		 x_y_z_matrix[i][0] = i; 
		 x_y_z_matrix[i][1] = index ; //echelle
		 x_y_z_matrix[i][2]	= nbr_lin; 
		 split_z = ft_split(split_line[index],',');
		
		if (split_z[0] != 0)
			x_y_z_matrix[i][3] = ft_atoi(split_z[0]);
		if (split_z[1] != 0)
			x_y_z_matrix[i][4] = to_decimal(split_z[1]);
		else
			x_y_z_matrix[i][4] = 0x49eb34;
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

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		int i;
		i = 0;
		while (i < vars->n_points)
		{
			if (vars -> x_y_z_old[i][3] > 0)
			{
				vars -> x_y_z_old[i][3] = vars -> x_y_z_old[i][3] - 100;
				printf("%d \n",vars -> x_y_z_old[i][3]);
			}
			i++;
		}
		//u must change this rabish code
	
		// vars -> x_y_z_matrix = vars ->x_y_z_old;
		// isometric_projection(vars -> x_y_z_old ,vars -> line_length , vars -> n_points,vars);
		// drawing_points(vars -> x_y_z_old , vars -> line_length , vars -> n_points,vars);
		//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars -> img, 0, 0);
	}
	printf(" %d \n",keycode); // + == 69 - = 78
	return (0);
}
void drawing_points(int **x_y_z_matrix , int length_line , int n_points,t_data *img)
{
	int		color;
	int		index;

	
	
	
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,&img->endian);
	img->n_points = n_points;
	index = 0;
	color = 0x1cc738;
	img->x_y_z_matrix = x_y_z_matrix;
	while (x_y_z_matrix[index])
	{
		if( index > 0 && index % length_line != 0)
			hory_point(index, length_line, x_y_z_matrix , color,img);
		if (index < n_points -length_line)
			hory_point(index, length_line, x_y_z_matrix , color,img);
		index++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_loop(img->mlx);	
}