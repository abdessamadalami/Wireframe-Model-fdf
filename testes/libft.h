/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 08:07:22 by ael-oual          #+#    #+#             */
/*   Updated: 2022/03/21 19:01:43 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include<stdlib.h>
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>
# include <fcntl.h>
# include <string.h>
# include<sys/wait.h>
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"
// typedef struct point_xyz
// {
// 	int x;
// 	int y;
// 	int z;
// 	int coler;
// }	point_xyz;

// typedef struct s_list
// {
// 	void			*content;
// 	void 			*x;
// 	void			*y;
// 	void			*z;
// 	void			*coler;
// 	struct s_list	*next;
// }	t_list;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;
int		ft_printf(const char *n, ...);
int		convert_hex_long_ptr(size_t a, int address);
int		ft_print_memory(void *addr, int address);
void	ft_putchar_fd(char c, int fd);


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int ft_strlen_d(char **arr_split);
void	free_function(char **str);
int  **check_list(t_list *list, int *length_line);
void print_matrix(int **x_y_z_matrix);
void x_y_z_c_function(char **split_line, int nbr_lin,int **x_y_z_matrix);
int *bre_algori(void *mlx,void *mlx_win,int x1, int y1, int x2, int y2, int coler);
int		ft_isalpha(int a);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t length);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
//char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t len, size_t size);
int		ft_atoi(const char *nbr);
char	*ft_strdup(char *src);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
