/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:08:13 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/05 14:55:51 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"
 
 t_rgb get_deffrent(int color,int color2,int div)
 {
	t_rgb a;

	a.d_r = (abs(color2/(256 * 256)) -  abs(color/(256 * 256)))/div;
	a.d_g = (abs((color2/256) % 256) - abs((color/256) % 256))/div;
	a.d_b = (abs(color2 % 256) - abs(color % 256))/div; //diffent

	return a;
 }

void get_color(int *color, t_rgb d)
{
	int r,g,b;
	r = abs(*color/(256 * 256)) + d.d_r;
	g = abs((*color/256) % 256) + d.d_g;
	b = abs(*color % 256) + d.d_b;

	*color = 256 * 256 * r + 256 * g + b;
}