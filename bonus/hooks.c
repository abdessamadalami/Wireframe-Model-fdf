/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/14 18:06:46 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"




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

void color_space(t_data *vars,int keycode)
{
	int i;
	i = 0;
		while (i < vars -> n_points)
		{
			vars -> x_y_z_matrix[i][0] = vars -> x_y_z_old[i][0];
			vars -> x_y_z_matrix[i][1] = vars -> x_y_z_old[i][1];
			vars -> x_y_z_matrix[i][2] = vars -> x_y_z_old[i][2];
			vars -> x_y_z_matrix[i][3] = vars -> x_y_z_old[i][3];
			if(vars -> x_y_z_matrix[i][3] == 0)
				vars -> x_y_z_matrix[i][4] += 20;
			i++;
		}
}

void rotate(t_data *vars,int c)
{
	printf(" <%d> ", c);
	if (c == 7)
		rotate_x(vars);
	else if(c == 6)
		rotate_z(vars);
	else if (c == 16)
	{
		rotate_y(vars);
	}
	
		
}

void zoom_fun(t_data *vars, int operat,int x, int y)
{
	int i;
	int c_x;
	int c_y;
	
	i = 0;
	while (i < vars->n_points)
	{
		vars -> x_y_z_matrix[i][0] = vars -> x_y_z_old[i][0];
		vars -> x_y_z_matrix[i][1] = vars -> x_y_z_old[i][1];
		vars -> x_y_z_matrix[i][2] = vars -> x_y_z_old[i][2];
		vars -> x_y_z_matrix[i][3] = vars -> x_y_z_old[i][3];
		i++;
	}	
	vars -> screnn.z_index += operat;
	if (vars -> screnn.z_index <= 0)
		vars -> screnn.z_index = 1;
}

void transf_fun(t_data *vars , char c , int operator)
{
	int i;
	static int j = 0;
	
	i = 0;
	while (i < vars->n_points)
	{
		vars -> x_y_z_matrix[i][0] = vars -> x_y_z_old[i][0];
		vars -> x_y_z_matrix[i][1] = vars -> x_y_z_old[i][1];
		vars -> x_y_z_matrix[i][2] = vars -> x_y_z_old[i][2];
		vars -> x_y_z_matrix[i][3] = vars -> x_y_z_old[i][3];
		i++;
	}
	
	if(c == 'x')
		vars -> r.tr_x += operator;
	if(c == 'y')
		vars -> r.tr_y += operator;
	j++;
}


int	 key_hook(int keycode, t_data *vars)
{

	char	*relative_path = "./ds.xpm";
	int		img_width;
	int		img_height;
	int		i;

	vars -> img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
	i = 0;	
	if (keycode == 53)
		exit(0);
	else if (keycode == 78 && ++i)
		 z_hook(vars, -1);
	else if (keycode == 69 && ++i)
		 z_hook(vars, +1);
	else if (keycode == 84 && ++i)
		 color_space(vars,keycode);
	else if (keycode == 35 && ++i)
		vars -> screnn.type_of = 'p';
	else if (keycode == 34 && ++i)
		vars -> screnn.type_of = 'i';
	else if (keycode == 124 && ++i)
		transf_fun(vars, 'x' , 10);
	else if (keycode == 123 && ++i)
		transf_fun(vars, 'x' , -10);
	else if (keycode == 126 && ++i)
		transf_fun(vars, 'y' , -10);
	else if (keycode == 125 && ++i)
		transf_fun(vars, 'y' , 10);
	else if ((keycode == 6 || keycode == 16 || keycode == 7) && ++i ) 
		rotate(vars,keycode);
	printf(" key code :%d  %d \n", keycode, i);
	if(i)
		isometric_projection(vars);
	return (0);
}
