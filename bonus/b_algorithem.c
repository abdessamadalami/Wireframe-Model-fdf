/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_algorithem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:18:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/05 15:27:50 by ael-oual         ###   ########.fr       */
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


int *bre_algori(t_point ab, int color ,t_data *img)
  { 
	static int index;
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
	d_color = get_deffrent(color ,0x0b32de ,max(abs(dx) ,abs(dy)));
//	printf(" ------- dx %d dy %d color_0 %d color_1 %d \n",dx,dy,ab.color_0,ab.color_1);
printf("%d %d %d c %d t %d\n",d_color.d_r,d_color.d_g,d_color.d_b,color,0x49eb34);
//exit(0);
    while(1)
    {   
		//my_mlx_pixel(img, ab.x0, ab.y0, color);
		//printf("i %d x %d y %d \n",i,ab.x0, ab.y0);
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
			get_color(&color,d_color);
	}
	return 0;
}