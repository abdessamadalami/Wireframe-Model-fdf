/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 08:17:02 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/21 21:45:44 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	rotate_x(t_data *vars)
{
	int				i;
	int				y;
	static double	x = M_PI_2;

	i = 0;
	while (vars -> xyz_m[i])
	{
		y = vars -> xyz_old[i][2];
		vars -> xyz_m[i][1] = vars -> xyz_old[i][1];
		vars -> xyz_m[i][2] = y * cos(x) + vars -> xyz_old[i][3] * sin(x);
		vars -> xyz_m[i][3] = (-y * sin(x) + vars -> xyz_old[i][3] * cos(x));
		i++;
	}
	x = x + M_PI_2;
}

void	rotate_y(t_data *vars)
{
	int				i;
	int				a;
	static double	y = M_PI_2;

	i = 0;
	while (i < vars->n_points)
	{
		a = vars -> xyz_old[i][1];
		vars -> xyz_m[i][1] = a * cos(y) + vars -> xyz_m[i][3] * sin(y);
		vars -> xyz_m[i][2] = vars -> xyz_old[i][2];
		vars -> xyz_m[i][3] = (-a * sin(y) + vars -> xyz_old[i][3] * cos(y));
		i++;
	}
	y = y + M_PI_2;
}

void	rotate_z(t_data *vars)
{
	int				i;
	int				x;
	static double	z = M_PI_2;

	i = 0;
	while (i < vars->n_points)
	{
		x = vars -> xyz_old[i][1];
		vars -> xyz_m[i][0] = vars -> xyz_old[i][0];
		vars -> xyz_m[i][1] = x * cos(z) - vars -> xyz_old[i][2] * sin(z);
		vars -> xyz_m[i][2] = vars -> xyz_old[i][1] * sin(z)
			+ vars -> xyz_old[i][2] * cos(z);
		vars -> xyz_m[i][3] = vars -> xyz_m[i][3];
		i++;
	}
	z = z + M_PI_2;
}

void	rotate(t_data *vars, int c)
{
	if (c == 7)
		rotate_x(vars);
	else if (c == 6)
		rotate_z(vars);
	else if (c == 16)
		rotate_y(vars);
}
