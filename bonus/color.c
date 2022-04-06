/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:08:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/06 14:14:20 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"
 
 t_rgb get_deffrent(int color,int color2,int div)
 {
	t_rgb a;

	a.d_r = ((color2/(256 * 256)) -  (color/(256 * 256)))/div;
	a.d_g = (((color2/256) % 256) - ((color/256) % 256))/div;
	a.d_b = ((color2 % 256) - (color % 256))/div; //diffent

	return a;
 }

void get_color(int *color, t_rgb d)
{
	float r,g,b;
	r = (*color/(256 * 256)) + d.d_r;
	g = ((*color/256) % 256) + d.d_g;
	b = (*color % 256) + d.d_b;

	*color = 256 * 256 * r + 256 * g + b;
}