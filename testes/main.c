#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <math.h>

#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int a;
}				t_vars;

int	clos_e(int keycode, t_vars *vars)
{
	printf("sd");
	mlx_destroy_window(vars->mlx, vars->win);

	exit(1);
	return (0);
}
int	clos_ex(int button, int x, int y, t_vars *param)
{
	static int i = 0;
	printf(" %d ",param -> a);
	printf("%d ",button);
	mlx_string_put(param->mlx,param->win, 150 ,150 + i, 0x810202,ft_itoa(x));
	i +=20;
	mlx_string_put(param->mlx,param->win, 150 + i,150 + i, 0x810202,ft_itoa(y));
	i +=20;
//	exit(0);
	return 0;
}
int	mouse_move(int x, int y, t_vars *param)
{
	static int i = 0;
	// printf("%d ",button);
	mlx_string_put(param->mlx,param->win, 150 ,150 + i,0x810202,ft_itoa(x));
	i +=20;
	mlx_string_put(param->mlx,param->win, 150 + i,150 + i,0x810202,ft_itoa(y));
	i +=20;
//	exit(0);
	return 0;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.a = 0x810202;
	mlx_hook(vars.win, 4, 0L, clos_ex, &vars);
	mlx_hook(vars.win, 5, 0L, clos_ex, &vars);
	mlx_hook(vars.win, 6, 0L, mouse_move, &vars);
	mlx_loop(vars.mlx);
}
// #include <mlx.h>

// typedef struct	s_data {

// 	void	*img;
// 	char	*addr;
// 	void	*mlx;
// 	void	*m_win;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// typedef struct	s_rgb {
// 	float		d_r;
// 	float		d_g;
// 	float		d_b;
// }				t_rgb;

// void	my_mlx_pixel(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }
// void  black_baground(t_data *vars)
// {
// 	int index;
// 	int j;

// 	index = 0;
// 	j = 0;
// 	while (index < 1920)
// 	{ 
// 		j = 0;
// 		while(j < 1080)
// 		{
// 			mlx_pixel_put(vars->mlx,vars->m_win, index,j,0x810202);
// 			j++;
// 		}
// 		index++;
// 	}
// }

// int	key_hook(int keycode, t_data *vars)
// {
// 	static int i;
// 	t_data	img;

		
// 	if (keycode == 53)
// 		exit(0);
// 	if (keycode == 69)
// 	{
// 		black_baground(vars);
// 		//	mlx_pixel_put(vars->mlx,vars->m_win, 50 + i,i,0x810202);
	
// 	}
// 		// my_mlx_pixel(vars, 5 + i, 5 + i, 0x810202);
// 		// my_mlx_pixel(vars, 5 + i + 300, 5 + i + 120, 0x810202);
// 		//u must change this rabish code
// 		// vars -> xyz_m = vars ->xyz_old;
// 		// isometric_projection(vars -> xyz_old ,vars -> line_length , vars -> n_points,vars);
// 		// drawing_points(vars -> xyz_old , vars -> line_length , vars -> n_points,vars);
// 		//mlx_put_image_to_window(vars->mlx, vars->m_win, vars -> img, 0, 0);
	
// 	//printf(" %d \n",keycode); // + == 69 - = 78
// 	return (0);
// }

//  t_rgb get_deffrent(int color,int color2)
//  {
// 	t_rgb a;
// 	int div = 700;
// 	a.d_r = ((float)((color2 / (256 * 256))) -  (color/(256 * 256))) /div;
// 	a.d_g = ((float)(((color2 / 256) % 256)) - ((color/256) % 256)) /div;
// 	a.d_b = ((float)((color2 % 256)) - (color % 256)) /div; //diffent
// 	printf("%f %f %f \n",a.d_b,a.d_g,a.d_r);
// 	return a;
//  }

// void get_color(int *color, t_rgb d)
// {
// 	float r,g,b;
// 	r = (*color / (256 * 256)) + d.d_r;
// 	g = ((*color / 256) % 256) + d.d_g;
// 	b = (*color % 256) + d.d_b;
// //	printf(" %f %f %f  d  %f %f %f \n",r,g,b,d.d_r,d.d_g,d.d_b);
// 	*color = 256 * 256 * r + 256 * g + b;
// }

// int	main(void)
// {
// 	t_data	img;
// 	t_rgb d_color;

// 	img.mlx = mlx_init();
// 	img.m_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(img.mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	int i = 0;
// 	int div = 700;
// 	//c1 add 3 colum to array for rgb color and function to convert rgb to hexa
// 	//c2 convert color to hexa and get rgb and make the coler and put it to 

// 	int color = 0xffffff;
// 	int color1 = 0xff0000;
// 	d_color = get_deffrent(color,color1);
// 	printf("%f %f %f \n",d_color.d_r,d_color.d_g,d_color.d_b);
// 	// 256 * 256 * r + 256 * g + b
// 	//printf(" %f ", (256 * 256) * -0.507157 * 489 -0.521472 * 489 * 256 - 0.521472 * 489);
// 	while (i < div)
// 	{
// 		my_mlx_pixel(&img, 5 + i, 5 + i, color);
// 		my_mlx_pixel(&img, 5 + i + 30, 5 + i + 20, color);
// 		get_color(&color,d_color);
// 		//color1 = color1 - 339967;
// 		//printf(" %d \n",color1);
// 		i++;
// 	}
// 	mlx_key_hook(img.m_win, key_hook, &img);
// 	mlx_put_image_to_window(img.mlx, img.m_win, img.img, 0, 0);
// 	mlx_loop(img.mlx);
// }
