/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:49:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 07:44:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include "fdf.h"

int	to_decimal(char *str)
{
	int		i;
	char	c;
	int		nbr;
	int		len;
	char	*hix = "0123456789abcdef";
	
	i = 0;
	c = 0;
	nbr = 0;
	if (str[0] == '0' && str[1] == 'x')
		str = str + 2;
	len = ft_strlen(str) - 1;
	while (str[i] != '\0')
	{
		c = ft_tolower(str[i]);
		nbr = nbr + ft_strchr_int(hix, c) * pow(16, len);
		i++;
		len--;
	}
	return (nbr);
}

static void	color_split(char **split_z, int **xyz_m, int i)
{
	if (split_z[0] != 0)
		xyz_m[i][3] = ft_atoi(split_z[0]);
	if (split_z[1] != 0)
		xyz_m[i][4] = to_decimal(split_z[1]);
	else if (xyz_m[i][3] > 0)
		xyz_m[i][4] = 0xff0000;
	else
		xyz_m[i][4] = 0xffffff;
}

void	x_y_z_c_function(char **split_line, int nbr_lin, int **xyz_m)
{
	int			index;
	char		**split_z;
	static int	i;

	index = 0;
	while (split_line[index] != 0)
	{
		xyz_m[i] = malloc(6 * sizeof(int));
		xyz_m[i][0] = i;
		xyz_m[i][1] = index;
		xyz_m[i][2] = nbr_lin;
		split_z = ft_split(split_line[index], ',');
		color_split(split_z, xyz_m, i);
		if (xyz_m[i][3] > 0)
			xyz_m[i][5] = 1;
		else
			xyz_m[i][5] = 0;
		i++;
		index++;
	}
}

int	ft_strlen_space(char *str)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (str[i])
	{
		if (str[i] != 32 && str[i + 1] == 32)
			index++;
		i++;
	}
	return (index);
}

int	**check_list(t_list *list, int *length_line, int line_nbr)
{
	char	**split_array;
	int		nbr_lin;
	int		**x_y_z_c_array;
	t_list	*node;

	node = list;
	*length_line = ft_strlen_space(list -> content) + 1;
	x_y_z_c_array = malloc(*length_line * line_nbr * sizeof(int **));
	nbr_lin = 0;
	while (list -> next)
	{
		split_array = ft_split(list -> content, 32);
		if (ft_strlen_d(split_array) != *length_line)
		{
			write(1, "error map\n ", 12);
			exit(0);
		}
		x_y_z_c_function(split_array, nbr_lin++, x_y_z_c_array);
		list = list -> next;
		free_function((void *)split_array);
	}
	x_y_z_c_array[*length_line * line_nbr] = 0;
	ft_lstclear(&node, del);
	return (x_y_z_c_array);
}
