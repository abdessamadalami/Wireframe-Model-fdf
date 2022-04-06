/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_algorithem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:18:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/06 15:01:28 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

void	my_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int get_coler(int a,int index)
// {}


int *bre_algori(t_point ab ,t_data *img , int z1,int z2)
  { 
	static int index;
	int color;
	int dx;
	int sx ;
	int dy;
	int sy;
	int error;
	int i = 0;
	t_rgb	d_color;
	
	dx = abs(ab.x1 - ab.x0);
    sx = (ab.x0 < ab.x1) ? 1 : -1;
    dy = -abs(ab.y1 - ab.y0);
   	sy = (ab.y0 < ab.y1) ? 1 : -1;
    error = dx + dy;
	color = ab.color_0;
	d_color = get_deffrent(color ,ab.color_1,max(abs(dx) ,abs(dy)));
	
	printf(" ------- dx %d dy %d color_0 %d color_1 %d d_r %f\n",dx,dy,ab.color_0,ab.color_1,d_color.d_r);
//exit(0);//489 point
int is = 0;

    while(1)
    {
		if(z1 == 0 && z2 != 0)
		{
			// get_color(&color,d_color);
			// printf(" %d ",ab.color_1);
			color = 0xfff585;
		}
		my_mlx_pixel(img, ab.x0, ab.y0, color);
		if( ab.x0 == ab.x1 && ab.y0 == ab.y1)
			break;
		int e2 = 2 * error;
		if (e2 >= dy)
		{ 
			if (ab.x0 == ab.x1)
				break;
			error = error + dy;
			ab.x0 = ab.x0 + sx;
			}
		if (e2 <= dx)
		{
			if (y0 == y1)
				break;
			error = error + dx;
			ab.y0 = ab.y0 + sy;
		}
			i++;
	}
	index++;
//	printf(" i: %d %f %f %f \n ",i,d_color.d_r,d_color.d_g,d_color.d_b);
	return 0;
}