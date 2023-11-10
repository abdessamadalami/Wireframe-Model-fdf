/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:46:04 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/21 11:55:49 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	zoom_fun(t_data *vars, int operat, int x, int y)
{
	int	i;

	i = 0;
	while (i < vars->n_points)
	{
		vars -> xyz_m[i][0] = vars -> xyz_old[i][0];
		vars -> xyz_m[i][1] = vars -> xyz_old[i][1];
		vars -> xyz_m[i][2] = vars -> xyz_old[i][2];
		vars -> xyz_m[i][3] = vars -> xyz_old[i][3];
		i++;
	}	
	vars -> screnn.z_index += operat;
	if (vars -> screnn.z_index <= 0)
		vars -> screnn.z_index = 1;
	x = 0;
	y = 0;
}

void	z_hook(t_data *vars, int operat)
{
	int	i;

	i = 0;
	while (i < vars->n_points)
	{
		vars -> xyz_m[i][0] = vars -> xyz_old[i][0];
		vars -> xyz_m[i][1] = vars -> xyz_old[i][1];
		vars -> xyz_m[i][2] = vars -> xyz_old[i][2];
		if (vars -> xyz_old[i][5] > 0)
		{
			vars -> xyz_old[i][3] = vars -> xyz_old[i][3] + operat;
			vars -> xyz_m[i][3] = vars -> xyz_old[i][3];
		}
		i++;
	}
}
