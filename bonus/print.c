/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:16:49 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/03 17:19:58 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_matrix(int **x_y_z_matrix)
{
	int i;
	i = 0;
	while(x_y_z_matrix[i] != 0)
	{
		printf(" index  %d x %d y %d  z  %d color %d  \n",x_y_z_matrix[i][0],x_y_z_matrix[i][1],x_y_z_matrix[i][2],x_y_z_matrix[i][3] ,x_y_z_matrix[i][4]);
		i++;
	}
}

void print_f(char **x_y_z_matrix)
{
	int i = 0;
	printf(" split of content \n");
	while(x_y_z_matrix[i])
	{
		printf(" %s ",x_y_z_matrix[i]);
		i++;
	}
}