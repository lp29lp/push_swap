# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 20:10:58 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/12/08 18:07:41 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC = ./src
P_UTILS = ./src/utils
P_MOVEMENTS = ./src/utils/movements
P_SMALL = ./src/small
P_BIG = ./src/big
FILES = $(P_SRC)/main.c $(P_UTILS)/utils_0.c $(P_MOVEMENTS)/move_0.c \
		$(P_MOVEMENTS)/move_1.c $(P_MOVEMENTS)/move_2_and_aux.c \
		$(P_UTILS)/utils_1.c $(P_SMALL)/small.c $(P_SMALL)/small_utils.c \
		$(P_BIG)/big.c $(P_BIG)/big_utils_0.c $(P_BIG)/big_utils_1.c
SRC = $(FILES:.c=.o)

CC = clang
RM = rm -f
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -I ./include/ -g #-fsanitize=address

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo push_swap created.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRC)
	@echo All clean.

fclean: clean
	@$(RM) push_swap

re: fclean clean all
