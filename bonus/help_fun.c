/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:44:37 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 11:37:29 by ael-oual         ###   ########.fr       */
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
	
void del(void *ptr)
{
	 free(ptr);
}

void	copy_d(t_data *img)
{
	int l_nbr;

	l_nbr = 0;
	img -> xyz_old = malloc(img -> n_points * sizeof(int **));
	if (img -> xyz_old == NULL)
	{
		ft_putstr_fd("allocation problem\n", 2);
		return ;
	}
	while (l_nbr < img -> n_points)
	{ 
		img -> xyz_old[l_nbr] = malloc(6 * sizeof(int));
		img -> xyz_old[l_nbr][0] = img -> xyz_m[l_nbr][0];
		img -> xyz_old[l_nbr][1] = img -> xyz_m[l_nbr][1];
		img -> xyz_old[l_nbr][2] = img -> xyz_m[l_nbr][2];
		img -> xyz_old[l_nbr][3] = img -> xyz_m[l_nbr][3];
		img -> xyz_old[l_nbr][4] = img -> xyz_m[l_nbr][4];
		img -> xyz_old[l_nbr][5] = img -> xyz_m[l_nbr][5];
		l_nbr++;
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