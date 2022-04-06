/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:49:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/06 14:14:41 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"
#include "fdf.h"

int to_decimal(char *str)
{
	int i;
	char c;
	int nbr;
	int len;
	char *hix="0123456789abcdef";
	
	i = 0; 
	c = 0;
	nbr = 0;
	if (str[0] == '0' && str[1] == 'x')
		str = str + 2;
 	len = ft_strlen(str) - 1;
	while(str[i] != '\0')
	{
		c =  ft_tolower(str[i]);
		nbr = nbr + ft_strchr_int(hix, c) * pow(16, len);
		i++;
		len--;
	}
	return nbr;
}

void x_y_z_c_function(char **split_line, int nbr_lin,int **x_y_z_matrix)
{
	int index;
	char **split_z;
	static int i;
	
	index = 0;
	while(split_line[index] != 0)
	{
		 x_y_z_matrix[i] = malloc(6 * sizeof(int));
		 x_y_z_matrix[i][0] = i; 
		 x_y_z_matrix[i][1] = index ; //echelle
		 x_y_z_matrix[i][2]	= nbr_lin; 
		 split_z = ft_split(split_line[index],',');
		
		if (split_z[0] != 0)
			x_y_z_matrix[i][3] = ft_atoi(split_z[0]);
		if (split_z[1] != 0)
			x_y_z_matrix[i][4] = to_decimal(split_z[1]);		
		else if (x_y_z_matrix[i][3] > 0)
			x_y_z_matrix[i][4] = 0x810202;
		else
			x_y_z_matrix[i][4] = 0xffffff;
		if (x_y_z_matrix[i][3] > 0)
			x_y_z_matrix[i][5] = 1;
		else
			x_y_z_matrix[i][5] = 0; 
		i++;
		index++;
	}
}

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