/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:26:45 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/26 13:13:25 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"

void	erros_functions(char **argv)
{
	int	length;

	length = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".fdf", argv[1] + length, 5) != 0)
	{
		ft_putstr_fd(" Error ./fdf", 2);
		exit(1);
	}
}

int	check_file_argument(char **argv, int argc)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(0);
	}
	erros_functions(argv);
	if (argc != 2)
	{
		ft_putstr_fd(" <error arrgument> \n", 2);
		exit(1);
	}
	return (fd);
}

void	make_win(t_data *img)
{
	img -> screnn.x_length = 2000;
	img -> screnn.y_length = 1500;
	img -> mlx = mlx_init();
	img -> m_win = mlx_new_window(img->mlx, img -> screnn.x_length,
			img -> screnn.y_length, "FDF :)");
	img -> img = mlx_new_image(img->mlx, img -> screnn.y_length,
			img -> screnn.y_length);
	img -> d = 1;
}

static void	make_env(int **xyz, int length_line, int nbr_lin)
{
	t_data	img;

	make_win(&img);
	img.xyz_m = xyz;
	img.n_points = length_line * nbr_lin;
	img.l_length = length_line;
	isometric_projection(&img);
}

int	main(int argc, char **argv)
{
	int		nbr_lin;
	int		length_line;
	t_parms	v;
	t_list	*list_line;

	nbr_lin = 0;
	length_line = 0;
	v.fd = check_file_argument(argv, argc);
	while (1)
	{
		v.line = get_next_line(v.fd);
		ft_lstadd_back(&list_line, ft_lstnew(v.line));
		if (v.line != 0 && v.line[0] == '\n')
			v.i++;
		if (v.line == 0)
			break ;
		nbr_lin++;
	}
	if (nbr_lin == 0 || v.i >= 1)
		check_file_argument(argv, 3);
	make_env(check_list(list_line, &length_line, nbr_lin),
		length_line, nbr_lin);
}
