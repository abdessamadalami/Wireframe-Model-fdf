/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 08:26:45 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 07:31:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"

void erros_functions(char **argv)
{
	int length;
	
	length = ft_strlen(argv[1]) - 4;
	if (ft_strncmp(".fdf", argv[1] + length, 5) != 0)
	{
		ft_putstr_fd(" Error ./fdf", 2);
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
	erros_functions(argv);
	if (argc != 2)
	{
		ft_putstr_fd(" <error arrgument> \n", 2); 
		exit(1);
	}
	return fd;
}
void make_win(t_data *img)
{
	img -> mlx = mlx_init();
	img -> mlx_win = mlx_new_window(img->mlx, 2000,1150, "FDF :)");
	img -> img = mlx_new_image(img->mlx, 2000, 1150);
	img -> screnn.z_index = 4;
	img-> screnn.x_length = 2000;
	img->screnn.y_length = 1150;
	img->r.tr_x = img->screnn.x_length/2;
	img->r.tr_y = img->screnn.y_length/2;
	img->screnn.type_of = 'i';
}

int	main(int argc ,char **argv)
{
	int		nbr_lin;
	int		length_line;
	int		fd;
	char	*line;
	t_list	*list_line;
	t_data	img;
	
	length_line = 0;
	make_win(&img);
	fd = check_file_argument(argv, argc);
	while (1)
	{
		line = get_next_line(fd);
		ft_lstadd_back(&list_line, ft_lstnew(line));
		if (line == 0)
			break;
		nbr_lin++;
	}
	free(line);
	img.x_y_z_matrix = check_list(list_line , &length_line , nbr_lin);
	img.n_points = length_line * nbr_lin;
	img.l_length = length_line;
	copy_d(&img);
	isometric_projection(&img);
}
