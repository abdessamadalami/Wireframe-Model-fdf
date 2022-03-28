/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:26:45 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/28 08:28:34 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
#include <math.h>
#include "fdf.h"

void erros_functions(char **argv)
{
	int length;
	
	length = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".fdf",argv[1] + length,5) != 0 )
	{
		ft_putstr_fd(" Error ./fdf",2);
		exit(1);
	}
}

int check_file_argument(char **argv, int argc)
{
	int fd;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[1]);
		exit(0);
	}
	if (argc != 2)
	{
		ft_putstr_fd(" < error arrgument> \n",2); 
		exit(1);
	}
	erros_functions(argv);
	return fd;
}

int	main(int argc ,char **argv)
{
	int		**x_y_z_matrix;
	int		nbr_lin;
	int		length_line;
	char	*line;
	int		n_points;
	t_list	*list_line;
	t_data	img;
	
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 2000,1500, "FDF :)");
	img.img = mlx_new_image(img.mlx, 2000, 1500);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,&img.endian);
	length_line = 0;
	int fd = check_file_argument(argv, argc);
	while (1)
	{
		line = get_next_line(fd);
		ft_lstadd_back(&list_line, ft_lstnew(line));
		if (line == 0)
			break;
		nbr_lin++;
	}
	x_y_z_matrix = check_list(list_line , &length_line);
	n_points = length_line * nbr_lin;
	img.x_y_z_matrix = x_y_z_matrix;
	img.n_points = n_points;
	img.line_length = length_line;
	isometric_projection(x_y_z_matrix, length_line,n_points,&img);
	drawing_points(img.x_y_z_matrix, length_line, n_points,&img);
	
	// mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	 mlx_key_hook(img.mlx_win, key_hook, &img);
	// mlx_loop(img.mlx);
}
