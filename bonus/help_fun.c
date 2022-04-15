/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:44:37 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 07:39:42 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"
#include "fdf.h"



int ft_strlen_d(char **arr_split)
{
	int index;

	index = 0;
	while(arr_split[index] != 0)
		index++;
	return index;
}


// void plotLine(int x0, int y0, int x1, int y1)

	
void del(void *ptr)
{
	 free(ptr);
}

void	copy_d(t_data *img)
{
	int line_number;

	line_number = 0;
	img -> x_y_z_old = malloc(img -> n_points * sizeof(int **));
	if (img -> x_y_z_old == NULL)
	{
		ft_putstr_fd("allocation problem\n", 2);
		return ;
	}
	while (line_number < img -> n_points)
	{ 
		img ->  x_y_z_old[line_number] = malloc(6 * sizeof(int));
		img ->  x_y_z_old[line_number][0] = img -> x_y_z_matrix[line_number][0];
		img ->  x_y_z_old[line_number][1] = img -> x_y_z_matrix[line_number][1];
		img ->  x_y_z_old[line_number][2] = img -> x_y_z_matrix[line_number][2];
		img ->  x_y_z_old[line_number][3] = img -> x_y_z_matrix[line_number][3];
		img ->  x_y_z_old[line_number][4] = img -> x_y_z_matrix[line_number][4];
		img ->  x_y_z_old[line_number][5] = img -> x_y_z_matrix[line_number][5];
		line_number++;
	}
}

void	free_function(void **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}