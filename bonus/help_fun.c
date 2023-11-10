/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:44:37 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/26 13:18:31 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include "fdf.h"

int	ft_strchr_int(const char *str, int c)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}	
	return (0);
}

void	copy_d(t_data *img)
{
	int	l_nbr;

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

int	ft_strlen_space(char *str)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != 32 && str[i + 1] == 32)
			index++;
		i++;
	}
	return (index);
}

void	free_function(char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = 0;
}

int	close_d(t_data *vars)
{
	exit(1);
	vars = 0;
	return (0);
}
