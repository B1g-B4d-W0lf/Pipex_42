# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wfreulon <wfreulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 02:36:56 by wfreulon          #+#    #+#              #
#    Updated: 2023/05/17 03:33:49 by wfreulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex_bonus
SRC = pipex_bonus.c \
utils_bonus.c \
childs_bonus.c \
parsing_bonus.c \
pipeges_bonus.c
LIBFT = ./Libft/libft.a
HEADERFILES = -I pipex_bonus.h Libft/libft.h
OBJFILES = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc
# 
$(NAME): $(OBJFILES)
#	make -C Libft
	$(CC) $(CFLAGS) $(OBJFILES) ${LIBFT} -o $(NAME)

all: $(NAME)

%.o: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $< 

clean:
#	make clean -C Libft
	rm -f $(OBJFILES)

fclean:
#	make fclean -C Libft
	rm -f $(NAME) $(NAME_B) $(OBJFILES)

re: fclean all
	
.PHONY: clean fclean all re
