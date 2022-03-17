# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 08:52:13 by ael-oual          #+#    #+#              #
#    Updated: 2022/03/09 13:48:01 by ael-oual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c
#BS =  mondatory_bonus/ft_strlen.c mondatory_bonus/help_fun.c mondatory_bonus/ft_strncmp.c   mondatory_bonus/ft_putchar_fd.c mondatory_bonus/ft_putstr_fd.c  mondatory_bonus/ft_split.c mondatory_bonus/main_bonns.c mondatory_bonus/pipex_42_1337.c mondatory_bonus/get_next_line_utils.c mondatory_bonus/get_next_line.c
CC = gcc
#CFLAGS = -Wall -Wextra -Werror
NAME = fdfd
#NAME2 = pipex_bonus
#OBJ = $(SRC:.c=.o)
#OBJB = $(BS:.c=.o)
all: $(OBJB)
	$(CC)  $(SRC) -lmlx -framework OpenGL -framework AppKit libft.a
#bonus: $(OBJB)
#	$(CC) $(BS) -o $(NAME2)
#clean: 
#	rm -f $(OBJ) $(OBJB)
#fclean:clean
#	rm -f $(NAME) 
#re:fclean all bonus
