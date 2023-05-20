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

NAME = pipex
SRC = pipex.c \
utils.c \
childs.c \
parsing.c
LIBFT = ./Libft/libft.a
HEADERFILES = -I pipex.h Libft/libft.h
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
