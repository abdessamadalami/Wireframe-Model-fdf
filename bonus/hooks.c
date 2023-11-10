/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/25 07:28:38 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include "libft.h"

void	other_hooks(int keycode, t_data *vars, int *i)
{
	if (keycode == 34 && ++(*i))
		vars -> screnn.type_of = 'i';
	else if (keycode == 124 && ++(*i))
		transf_fun(vars, 'x', 10);
	else if (keycode == 123 && ++(*i))
		transf_fun(vars, 'x', -10);
	else if (keycode == 126 && ++(*i))
		transf_fun(vars, 'y', -10);
	else if (keycode == 125 && ++(*i))
		transf_fun(vars, 'y', 10);
	else if ((keycode == 6 || keycode == 16 || keycode == 7) && ++(*i))
		rotate(vars, keycode);
	else if (keycode == 2 && ++(*i))
	{
		if (vars -> d != 0)
			vars -> d = 0;
		else
			vars -> d = 1;
		mlx_hook(vars -> m_win, 6, 0L, mouse_move, vars);
	}
}

int	key_hook(int keycode, t_data *vars)
{
	int		img_width;
	int		img_height;
	int		i;

	vars -> img = mlx_xpm_file_to_image(vars->mlx,
			"./dss.xpm", &img_width, &img_height);
	i = 0;
	if (keycode == 53)
		exit(1);
	else if (keycode == 78 && ++i)
		z_hook(vars, -1);
	else if (keycode == 69 && ++i)
		z_hook(vars, +1);
	else if (keycode == 35 && ++i)
		vars -> screnn.type_of = 'p';
	other_hooks(keycode, vars, &i);
	if (i)
		isometric_projection(vars);
	return (0);
}
