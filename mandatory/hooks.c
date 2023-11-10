/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:59:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/24 22:54:43 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	key_hook(int keycode, t_data *vars)
{
	vars = 0;
	if (keycode == 53)
		exit(1);
	keycode = 0;
	return (0);
}

int	close_d(t_data *vars)
{
	exit(1);
	vars = 0;
	return (0);
}
