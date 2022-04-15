/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 08:17:02 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/13 11:06:18 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"



void rotate_x(t_data *vars)
{
	int i;
	static double x = M_PI_2;
	i = 0;
	while (vars -> x_y_z_matrix[i])
	{
		int y = vars -> x_y_z_old[i][2];
		vars -> x_y_z_matrix[i][1] = vars -> x_y_z_old[i][1];
		vars -> x_y_z_matrix[i][2] = y * cos(x)  +  vars -> x_y_z_old[i][3] * sin(x);
		vars -> x_y_z_matrix[i][3] = (-y * sin(x) + vars -> x_y_z_old[i][3] * cos(x));
		i++;
	}
	x = x + M_PI_2;
}

void rotate_y(t_data *vars)
{
	int i;
	static double y = M_PI;
	i = 0;
	while (i < vars->n_points)
	{
		int a = vars -> x_y_z_old[i][1];
		vars -> x_y_z_matrix[i][1] = a * cos(y) + vars -> x_y_z_matrix[i][3] * sin(y);
		vars -> x_y_z_matrix[i][2] = vars -> x_y_z_old[i][2];
		vars -> x_y_z_matrix[i][3] = (-a * sin(y) + vars -> x_y_z_old[i][3] * cos(y));
		i++;
	}
	y = y + M_PI;
}
void rotate_z(t_data *vars)
{
	int i;
	static double z = M_PI_2;
	i = 0;
	while (i < vars->n_points)
	{
		int x = vars -> x_y_z_old[i][1];
		vars -> x_y_z_matrix[i][0] = vars -> x_y_z_old[i][0];
		vars -> x_y_z_matrix[i][1] = x * cos(z) - vars -> x_y_z_old[i][2] * sin(z);
		vars -> x_y_z_matrix[i][2] = x * sin(z)  +  vars -> x_y_z_old[i][2] * cos(z);
		vars -> x_y_z_matrix[i][3] =  vars -> x_y_z_old[i][3];
		i++;
	}
	z = z + M_PI_2; 
}