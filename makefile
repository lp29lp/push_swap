# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 20:10:58 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/10/11 20:29:48 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC = ./src
P_UTILS = ./src/utils
P_LIBFT = ./include/libft

LIBFT = $(P_LIBFT)/libft.a

FILES = $(P_SRC)/main.c 
SRC = $(FILES:.c=.o)

CC = clang
RM = rm -f

all: comp test

test:
	@$(CC) $(SRC) $(LIBFT) -o test
	@echo test created.

comp: $(SRC)
	@make --no-print-directory -C $(P_LIBFT)
	@echo libft done.

%.o: %.c
	@$(CC) -c $< -o $@

clean:
	@make clean --no-print-directory -C $(P_LIBFT)
	@$(RM) $(SRC)
	@echo All clean dude.

fclean: clean
	@make fclean --no-print-directory -C $(P_LIBFT)
	@$(RM) test

re: fclean clean all