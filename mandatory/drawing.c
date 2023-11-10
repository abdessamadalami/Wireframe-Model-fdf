/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:10:25 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/24 22:53:37 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"

void	allocation_problem(void)
{
	ft_putstr_fd("allocation problem\n", 2);
	exit(1);
}

t_point	to_stract(t_data *img, int index, char type)
{
	t_point	ab;

	if (type == 'l')
	{
		ab.x0 = img->xyz_m[index - 1][1];
		ab.y0 = img->xyz_m[index - 1][2];
		ab.color_0 = img -> xyz_m[index - 1][4];
		ab.x1 = img->xyz_m[index][1];
		ab.y1 = img->xyz_m[index][2];
		ab.color_1 = img->xyz_m[index][4];
	}
	if (type == 'c')
	{
		ab.x0 = img-> xyz_m[index][1];
		ab.y0 = img -> xyz_m[index][2];
		ab.color_0 = img -> xyz_m[index][4];
		ab.x1 = img -> xyz_m[index + img -> l_length][1];
		ab.y1 = img -> xyz_m[index + img -> l_length][2];
		ab.color_1 = img -> xyz_m[index + img -> l_length][4];
	}
	return (ab);
}

void	h_v_point(int index, int l_line, t_data *img)
{
	t_point	ab;

	if (index > 0 && index % l_line != 0)
	{
		ab = to_stract(img, index, 'l');
		bre_algori(ab, img);
	}
	if (index < img -> n_points - l_line)
	{
		ab = to_stract(img, index, 'c');
		bre_algori(ab, img);
	}
}

void	drawing_points(t_data *img)
{
	int	index;

	index = 0;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	while (index < img->n_points)
	{
		if (index > 0 && index % img -> l_length != 0)
			h_v_point(index, img -> l_length, img);
		if (index < img-> n_points - img -> l_length)
			h_v_point(index, img -> l_length, img);
		index++;
	}
	mlx_put_image_to_window(img->mlx, img->m_win, img->img, 0, 0);
	mlx_key_hook(img->m_win, key_hook, img);
	mlx_hook(img->m_win, 17, 1L << 0, close_d, img);
	mlx_loop(img->mlx);
}
