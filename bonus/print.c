/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:16:49 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/21 11:58:36 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

// void print_f(char **xyz_m)
// {
// 	int i = 0;
// 	printf(" split of content \n");
// 	while(xyz_m[i])
// 	{
// 		printf(" %s ",xyz_m[i]);
// 		i++;
// 	}
// }

void	print_in(t_data *vars)
{
	mlx_string_put(vars->mlx, vars->m_win, 5, 1160,
		0xffffff, " I: Isometric projection.");
	mlx_string_put(vars->mlx, vars->m_win, 5, 1190, 0xffffff,
		" P: Parallel projection.");
	mlx_string_put(vars->mlx, vars->m_win, 350, 1160, 0xffffff,
		" X: X rotation.");
	mlx_string_put(vars->mlx, vars->m_win, 350, 1190, 0xffffff,
		" Z: Z rotation.");
	mlx_string_put(vars->mlx, vars->m_win, 645, 1160, 0xffffff,
		" +,-: change  z coordinate.");
	mlx_string_put(vars->mlx, vars->m_win, 645, 1190, 0xffffff,
		" P: draw on & off.");
	mlx_string_put(vars->mlx, vars->m_win, 990, 1160, 0xffffff,
		" Left mouse click: zooming in specific point.");
	mlx_string_put(vars->mlx, vars->m_win, 990, 1190, 0xffffff,
		" Scroll up: zoom in.");
	mlx_string_put(vars->mlx, vars->m_win, 990, 1220, 0xffffff,
		" Scroll down: zoom out.");
	mlx_string_put(vars->mlx, vars->m_win, 1490, 1160, 0xffffff,
		" Middle click: transformation to mouse position.");
	mlx_string_put(vars->mlx, vars->m_win, 1490, 1190, 0xffffff,
		" Fleche direction: transformation by x & y.");
	mlx_string_put(vars->mlx, vars->m_win, 1490, 12100, 0xffffff,
		" Esc : close.");
}
