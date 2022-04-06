/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/06 17:44:16 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	rotate_x(int *y, int *z, double teta)
{
	int		tmp_y;

	tmp_y = *y;
	*y = tmp_y * cos(teta) + *z * sin(teta);
	*z = -tmp_y * sin(teta) + *z * cos(teta);
}

void tran_fun(t_data *vars)
{
	int i;
	i = 0;
// 		vars -> x_y_z_matrix[i][0] = vars -> x_y_z_old[i][1] + 20;
 }

void z_hook(t_data *vars,int operat)
{
	int i;
	i = 0;
		
		while (i < vars->n_points)
		{
			vars -> x_y_z_matrix[i][0] = vars -> x_y_z_old[i][0];
			vars -> x_y_z_matrix[i][1] = vars -> x_y_z_old[i][1];
			vars -> x_y_z_matrix[i][2] = vars -> x_y_z_old[i][2];
			if (vars -> x_y_z_old[i][5] > 0)
			{
				vars -> x_y_z_old[i][3] = vars -> x_y_z_old[i][3] + operat;
				vars -> x_y_z_matrix[i][3] = vars -> x_y_z_old[i][3];
			}
			i++;
		}
	
}

void rotate(t_data *vars)
{
	int i;
	i = 0;
		int y;
		while (i < vars->n_points)
		{
			y = vars ->x_y_z_old[i][2];
			printf("xa %d",vars -> x_y_z_old[i][2]);
			printf(" za %d ",vars -> x_y_z_old[i][3]);
			vars -> x_y_z_old[i][2] = vars -> x_y_z_old[i][2] * cos(3.14) +  vars -> x_y_z_old[i][3] * sin(3.14);
			vars -> x_y_z_old[i][3] = ( -y  * sin(3.14) + vars -> x_y_z_old[i][3] * cos(3.14));
			printf("x %d",vars -> x_y_z_old[i][2]);
			printf(" z %d \n",vars -> x_y_z_old[i][3]);
			i++;
		}
}
int	key_hook(int keycode, t_data *vars)
{

	char	*relative_path = "./ds.xpm";
	int		img_width;
	int		img_height;


	vars -> img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
	if (keycode == 53)
		exit(0);
	if (keycode == 78)
		 z_hook(vars, -1);
	if (keycode == 69)
		 z_hook(vars, +1);
	if (keycode == 15)
		rotate(vars);
	if (keycode == 17)
	{
		//tran_fun(vars);
		//print_matrix(vars -> x_y_z_old);
		//isometric_projection(vars);
	}
	isometric_projection(vars);
	printf(" %d ______________________________________________________________________---\n",keycode); // + == 69 - = 78
	return (0);
}