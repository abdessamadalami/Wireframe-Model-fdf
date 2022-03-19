/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:44:37 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/19 11:13:33 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"


void print_matrix(int **x_y_z_matrix)
{
	int i;
	i = 0;
	while(x_y_z_matrix[i])
	{
		printf(" index  %d x %d y %d  z %d \n",x_y_z_matrix[i][0],x_y_z_matrix[i][1],x_y_z_matrix[i][2],x_y_z_matrix[i][3]);
		i++;
	}
}

int ft_strlen_d(char **arr_split)
{
	int index;

	index = 0;
	while(arr_split[index] != 0)
		index++;
	return index;
}

void plotLine(int x0, int y0, int x1, int y1)
  {  
		int dx = abs(x1 - x0);
    int sx = (x0 < x1) ? 1 : -1 ;
    int dy = -abs(y1 - y0);
   	int  sy = (y0 < y1) ? 1 : -1;
    int error = dx + dy;
    while(1)
      { 
		 //  plot(x0, y0);
        if( x0 == x1 && y0 == y1)
			break;
        int e2 = 2 * error;
        if (e2 >= dy)
           { 
			   if(x0 == x1)
			   		break;
            error = error + dy;
            x0 = x0 + sx;
			}
       
        if (e2 <= dx)
           {
			    if (y0 == y1)
					break;
            	error = error + dx;
            	y0 = y0 + sy;
			}
		}

  }

int *bre_algori(void *mlx,void *mlx_win,int x1, int y1, int x2, int y2, int coler)
{
	int dx;
	int dy;
	int p;
	int yi = 1;
	int **tab;
	
	if(x1 > x2)
		bre_algori(mlx,mlx_win, x2,y2, x1, y1,coler);
	dx = x2 - x1; //negative numbres 
	dy = y2 - y1;
	if (dy < 0)
	{
		yi = -1;
		dy = abs(dy);
	}
	p = 2 * dy - dx;
	printf("______________________________________ \nA (%d,%d) B(%d ,%d)\n",x1,y1,x2,y2);
	
	while(x1 <= x2)
	{
		mlx_pixel_put(mlx, mlx_win ,x1 ,y1 , coler);
		printf("( %d , %d ) p = %d \n", x1,y1,p);
		x1++;
		if (p < 0)
			p = p + 2 * dy;
		else
			{
				p = p + 2 * dy - 2 * dx;
				y1 = y1 + yi; 
			}
	}
	return 0;
}
void del(void *ptr)
{
//	*(int*)ptr = 5;
	 free(ptr);
}
void print_f(char **x_y_z_matrix)
{
	int i = 0;
	printf(" split of content \n");
	while(x_y_z_matrix[i])
	{
		printf(" %s ",x_y_z_matrix[i]);
		i++;
	}
}
int  **check_list(t_list *list, int *length_line)
{
	int line_nbr = 0;
	int length = 0;
	char **split_array = 0;
	char **array = 0;
	int nbr_lin = 0;
	int len = 0;
	int **x_y_z_c_array = 0;

	t_list *node;
	node = list;
	
	array = ft_split(node -> content, 32);
	length = ft_strlen_d(array);
	*length_line = length;
	line_nbr = ft_lstsize(list) - 1;
	x_y_z_c_array = malloc(length * line_nbr * sizeof(int **));
	 nbr_lin = 0;
	 while(list -> next)
	{
		split_array = ft_split(list -> content, 32);
		len = ft_strlen_d(split_array);
		if (len != length)
		{
			write(1,"error map\n ",12);
			exit(0);
		}
		 x_y_z_c_function(split_array, nbr_lin, x_y_z_c_array);
		nbr_lin++;
		node = list;
		list = list -> next;
	}
	 x_y_z_c_array[length * line_nbr] = 0;
	return x_y_z_c_array;
}

void	free_function(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}