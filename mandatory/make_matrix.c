/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:49:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/27 08:50:11 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"
#include "fdf.h"

int  **check_list(t_list *list, int *length_line)
{
	int line_nbr;
	char **split_array;
	char **array;
	int nbr_lin;
	int len;
	int **x_y_z_c_array;

	t_list *node;
	node = list;
	array = ft_split(node -> content, 32);
	*length_line = ft_strlen_d(array);
	line_nbr = ft_lstsize(list) - 1;
	x_y_z_c_array = malloc(*length_line * line_nbr * sizeof(int **));
	nbr_lin = 0;
	while(list -> next)
	{
		split_array = ft_split(list -> content, 32);
		len = ft_strlen_d(split_array);
		if (len != *length_line)
		{
			write(1,"error map\n ",12);
			//free
			exit(0);
		}
		x_y_z_c_function(split_array, nbr_lin, x_y_z_c_array);
		nbr_lin++;
		node = list;
		list = list -> next;
	}
	 x_y_z_c_array[*length_line * line_nbr] = 0;
	return x_y_z_c_array;
}