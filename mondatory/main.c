/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:26:45 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/27 08:44:15 by ael-oual         ###   ########.fr       */
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
	
	length_line = 0;
	int fd = check_file_argument(argv, argc);
	while (1)
	{
		line = get_next_line(fd);
		ft_lstadd_back(&list_line, ft_lstnew(line));
		if (line == 0)
			break ;
		nbr_lin++;
	}
	x_y_z_matrix = check_list(list_line , &length_line);
	n_points = length_line * nbr_lin;
	isometric_projection(x_y_z_matrix, length_line,n_points);
	drawing_points(x_y_z_matrix, length_line, n_points);
}
