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
NBONUS = pipex_bonus
SRC = pipex.c \
utils.c \
childs.c \
parsing.c \
pipeges.c
SRC_B = Pipex_42Bonus/pipex_bonus.c \
Pipex_42Bonus/utils_bonus.c \
Pipex_42Bonus/childs_bonus.c \
Pipex_42Bonus/parsing_bonus.c \
Pipex_42Bonus/pipeges_bonus.c
LIBFT = ./Libft/libft.a
HEADERFILES = -I pipex.h Libft/libft.h Pipex_42Bonus/pipex_bonus.h
OBJFILES = $(SRC:.c=.o)
OBJBONUS = $(SRC_B:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g3
CC = gcc
# 
$(NAME): $(OBJFILES)
	make -C Libft
	$(CC) $(CFLAGS) $(OBJFILES) ${LIBFT} -o $(NAME)

all: $(NAME)

$(NBONUS): $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) ${LIBFT} -o $(NBONUS)

bonus: $(NBONUS)

%.o: %.c $(HEADERFILES)
	$(CC) -c $(CFLAGS) -o $@ $< 

clean:
	make clean -C Libft
	rm -f $(OBJFILES) $(OBJBONUS)

fclean:
	make fclean -C Libft
	rm -f $(NAME) $(NBONUS) $(OBJFILES) $(OBJBONUS)

re: fclean all
	
.PHONY: clean fclean all re
