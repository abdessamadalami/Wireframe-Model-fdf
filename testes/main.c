#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <math.h>
typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		x0;
	int		y0;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	static int i;
	
	
	printf(" x %d___ y %d %d \n",vars -> x0, vars -> y0, keycode );
	mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0,"3");
	mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0,"3");
	// mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0x00000,"3");
	// mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0x00000,"3");
	if (keycode == 69)
	{
		vars -> x0 = vars -> x0 + 30 ;
		vars -> y0 = vars -> y0 + 30 ;
	}
	if (keycode == 78)
	{
		vars -> x0 = vars -> x0 - 30;
		vars -> y0 = vars -> y0 - 30;
	}
	mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0x1cc738,"3");
	return (0);
}


int mouse_hook(int keycode, t_vars *vars)
{
    static int i;
	// int c = vars->x0;
	// printf("key_hook! %d  \n",c);
	//#000000
	mlx_string_put(vars -> mlx,vars -> win, 60 , 63, 0x1cc738,"aidjf");
	
	if (keycode == 5)
	{
		printf("key_hook 5 ! : %d %d \n",keycode,i);
		
		// segfoult problem 
		i = i + 1;
	}
	if (keycode == 4)
	{
		i--;
		printf("key_hook 4 ! : %d %d \n",keycode,i);
	}
	return (0);
}


int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y)
{
	printf("sdf");
	return 0;
}
int	ft_strchr_int(const char *str, int c)
{
	const char	*s;
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	
			return (0);
}

int to_decimal(char *str)
{
	int i;
	char c;
	int nbr;
	int len;
	char *hix="0123456789abcdef";
	
	i = 0; 
	c = 0;
	nbr = 0;
	if (str[0] == '0' && str[1] == 'x')
		str = str + 2;
 	len = ft_strlen(str) - 1;
	while(str[i] != '\0')
	{
		c =  ft_tolower(str[i]);
		nbr = nbr + ft_strchr_int(hix, c) * pow(16, len);
		i++;
		len--;
	}
	return 0;
}
int	main(void)
{
	t_vars	*vars;
	int x0, y0, x1,y1;
	vars = malloc(sizeof(t_vars));
	vars -> x0 = 220;
	vars -> y0= 30;
	vars -> mlx = mlx_init();
	
	//char a = 0xFF0000;
	//to_decimal(a);
	 int b = 0x810202;
    // ft_printf("+++ %d ++", b);
	// printf(" %x %d %d", a , a, b);// imkn ft_printf t9di lrarad 

	

	vars -> win = mlx_new_window(vars -> mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars -> win, key_hook, vars);
	//mlx_key_hook(vars.win, mouse_hook, &vars);
	mlx_string_put(vars -> mlx,vars->win,50, 50, 188608, "0");
	int i = 0;
	printf(" %d ", b);
	while(i <=  250)
	{
		mlx_string_put(vars -> mlx, vars->win, 50, 50 + 2 + i, b, "df");
		b--;
		i++;
	}
	printf("(<%d>)",b);

// mlx_mouse_hook(vars -> win,  mouse_hook, vars);
//	func_text(&vars);
//	mlx_mouse_hook(vars.win, mlx_mouse_move, &vars);
	//mlx_mouse_move(vars.win, 50, 50);
	mlx_loop(vars -> mlx);
}