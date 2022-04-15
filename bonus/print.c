/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:16:49 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 07:44:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void print_matrix(int **xyz_m)
{
	int i;
	i = 0;
	while(xyz_m[i] != 0)
	{
		printf(" index  %d x %d y %d  z  %d color %d  \n",xyz_m[i][0],xyz_m[i][1],xyz_m[i][2],xyz_m[i][3] ,xyz_m[i][4]);
		i++;
	}
}

void print_f(char **xyz_m)
{
	int i = 0;
	printf(" split of content \n");
	while(xyz_m[i])
	{
		printf(" %s ",xyz_m[i]);
		i++;
	}
}