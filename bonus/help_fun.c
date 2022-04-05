/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:44:37 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/03 17:20:23 by ael-oual         ###   ########.fr       */
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

void	free_function(char **str)
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