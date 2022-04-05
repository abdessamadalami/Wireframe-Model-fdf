/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/04 12:28:59 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"


int	key_hook(int keycode, t_data *vars)
{

	char	*relative_path = "./ds.xpm";
	int		img_width;
	int		img_height;


	vars -> img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
	if (keycode == 53)
		exit(0);
	if (keycode == 78)
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
				vars -> x_y_z_old[i][3] = vars -> x_y_z_old[i][3] - 1;
				vars -> x_y_z_matrix[i][3] = vars -> x_y_z_old[i][3];
			}
			i++;
		}
		 isometric_projection(vars);
	}
	if (keycode == 69)
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
				vars -> x_y_z_old[i][3] = vars -> x_y_z_old[i][3] + 1;
				vars -> x_y_z_matrix[i][3] = vars -> x_y_z_old[i][3];
			}
			i++;
		}
		isometric_projection(vars);
	}
	
	printf(" %d ______________________________________________________________________---\n",keycode); // + == 69 - = 78
	return (0);
}