/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:13:56 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/21 12:25:28 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	centr_p(t_data *vars, int x, int y)
{
	int	d_x;
	int	d_y;

	d_x = vars->xyz_m[0][1] - x;
	d_y = vars->xyz_m[0][2] - y;
	zoom_fun(vars, 1, x, y);
	if (d_x > vars -> screnn.x_length)
		d_x = 0;
	if (d_y > vars -> screnn.y_length)
		d_y = 0;
	transf_fun(vars, 'x', d_x / 20);
	transf_fun(vars, 'y', d_y / 20);
}

void	come_to(int x, int y, t_data *vars)
{
	int			d_x;
	int			d_y;
	static int	i;

	d_x = x - vars->xyz_m[0][1];
	d_y = y - vars->xyz_m[0][2];
	if (i == 0)
	{
		transf_fun(vars, 'x', 1000);
		transf_fun(vars, 'y', 1000);
	}
	else
	{
		transf_fun(vars, 'x', d_x);
		transf_fun(vars, 'y', d_y);
	}
	i++;
}

static void	black_baground(t_data *p)
{
	int		i;
	int		j;

	i = 0;
	while (i < 60)
	{
		j = 0;
		while (j < 40)
		{
			mlx_pixel_put(p->mlx, p->m_win, 1800 + j, 1060 + i, 0);
			mlx_pixel_put(p->mlx, p->m_win, 1800 + j, 1060 + i + 30, 0);
			j++;
		}
		i++;
	}
}

int	mouse_move(int x, int y, t_data *p)
{
	int		i;
	char	*x1;
	char	*y1;

	i = 0;
	if (p -> d == 0)
		drawing_polyline(x, y, p);
	black_baground(p);
	x1 = ft_itoa(x);
	y1 = ft_itoa(y);
	mlx_string_put(p->mlx, p->m_win, 1800 - 40, 1060, 0xffffff, "x:");
	mlx_string_put(p->mlx, p->m_win, 1800, 1060, 0xffffff, x1);
	mlx_string_put(p->mlx, p->m_win, 1800 - 40, 1060 + 30, 0xffffff, "y:");
	mlx_string_put(p->mlx, p->m_win, 1800, 1060 + 30, 0xffffff, y1);
	free(x1);
	free(y1);
	return (0);
}

int	mouse_up(int button, int x, int y, t_data *vars)
{
	int		img_width;
	int		img_height;

	vars -> img = mlx_xpm_file_to_image(vars->mlx,
			"./dss.xpm", &img_width, &img_height);
	if (button == 2)
		z_hook(vars, -1);
	else if (button == 1)
		centr_p(vars, x, y);
	else if (button == 4)
		zoom_fun(vars, -1, x, y);
	else if (button == 5)
		zoom_fun(vars, 1, x, y);
	else if (button == 3)
		come_to(x, y, vars);
	isometric_projection(vars);
	return (0);
}
