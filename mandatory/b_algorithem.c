/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_algorithem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:18:28 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/23 21:23:32 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < data -> screnn.x_length && y < data -> screnn.y_length)
	{
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static int	bre(t_bre *var, t_point *ab)
{
	if (ab->x0 == ab->x1 && ab->y0 == ab->y1)
		return (0);
	var->e2 = 2 * var->error;
	if (var->e2 >= var->dy)
	{
		if (ab->x0 == ab->x1)
			return (0);
		var->error = var->error + var->dy;
		ab->x0 = ab->x0 + var->sx;
	}
	if (var->e2 <= var->dx)
	{
		if (ab->y0 == ab->y1)
			return (0);
		var->error = var->error + var->dx;
		ab->y0 = ab->y0 + var->sy;
	}
	return (1);
}

static	void	variable(t_point *ab, t_bre *var)
{
	if (ab->x0 < ab->x1)
		var->sx = 1;
	else
		var->sx = -1;
	if (ab->y0 < ab->y1)
		var->sy = 1;
	else
		var->sy = -1;
}

int	*bre_algori(t_point ab, t_data *img)
{
	static int	index;
	int			color;
	int			i;
	t_rgb		d_color;
	t_bre		var;

	var.dx = abs(ab.x1 - ab.x0);
	var.dy = -abs(ab.y1 - ab.y0);
	variable(&ab, &var);
	var.error = var.dx + var.dy;
	color = ab.color_0;
	d_color = get_deffrent(color, ab.color_1, max(abs(var.dx), abs(var.dy)));
	while (1)
	{
		get_color(&color, d_color);
		my_mlx_pixel(img, ab.x0, ab.y0, color);
		i = bre(&var, &ab);
		if (i == 0)
			break ;
	}
	index++;
	return (0);
}
