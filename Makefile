# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/04/25 10:51:56 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = mandatory/b_algorithem.c mandatory/color.c mandatory/drawing.c mandatory/get_next_line_utils.c mandatory/get_next_line.c mandatory/help_fun.c mandatory/hooks.c mandatory/iso_centre.c mandatory/make_matrix.c mandatory/main.c
BS = bonus/func.c bonus/transfrmation.c bonus/rotate.c bonus/mouse.c bonus/zoom.c bonus/b_algorithem.c bonus/color.c bonus/drawing.c bonus/get_next_line_utils.c bonus/get_next_line.c bonus/help_fun.c bonus//hooks.c bonus/iso_centre.c bonus/make_matrix.c bonus/print.c bonus/main.c
CC = cc
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fdf
LIB = libft/libft.a
LIBO = libft/*.O
MLX = -lmlx -framework OpenGL -framework AppKit
NAME2 = fdf_bonus
OBJ = $(SRC:.c=.o)
OBJB = $(BS:.c=.o)
all: $(NAME)
$(NAME):  $(OBJ) $(LIB)
	$(CC)  $(CFLAGS) $(OBJ) $(MLX) $(LIB) -o $@
$(LIB):
	cd libft && make
bonus: $(NAME2)
$(NAME2):  $(OBJB) $(LIB)
	$(CC) $(BS) $(MLX) $(LIB) -o $@
LIBC:
	cd libft && make clean
clean: LIBC
	rm -f $(OBJ) $(OBJB)
fclean:clean
	cd libft && make fclean
	rm -f $(NAME)
	rm -f $(NAME2)
re:fclean all bonus
