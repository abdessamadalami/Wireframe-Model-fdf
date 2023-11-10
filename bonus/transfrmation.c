/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfrmation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:49:09 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/21 12:01:15 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	transf_fun(t_data *vars, char c, int operator)
{
	int			i;
	static int	j;

	j = 0;
	i = 0;
	while (i < vars->n_points)
	{
		vars -> xyz_m[i][0] = vars -> xyz_old[i][0];
		vars -> xyz_m[i][1] = vars -> xyz_old[i][1];
		vars -> xyz_m[i][2] = vars -> xyz_old[i][2];
		vars -> xyz_m[i][3] = vars -> xyz_old[i][3];
		i++;
	}
	if (c == 'x')
		vars -> r.tr_x += operator;
	if (c == 'y')
		vars -> r.tr_y += operator;
	j++;
}
