/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 07:11:47 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/23 07:22:01 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**func_25(int length_line, int line_nbr)
{
	int	**x_y_z_c_array;

	x_y_z_c_array = malloc(length_line * line_nbr * sizeof(int **));
	if (x_y_z_c_array == NULL)
		allocation_problem();
	return (x_y_z_c_array);
}
