# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 20:10:58 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/12/09 20:13:30 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC = ./src/
P_UTILS = $(P_SRC)utils/
P_MOVEMENTS = $(P_SRC)utils/movements/
P_SMALL = $(P_SRC)small/
P_BIG = $(P_SRC)big/
P_OBJ = ./obj/
P_INCLUDE = ./include/

FILES = $(P_SRC)main.c $(P_UTILS)utils_0.c $(P_MOVEMENTS)move_0.c \
		$(P_MOVEMENTS)move_1.c $(P_MOVEMENTS)move_2_and_aux.c \
		$(P_UTILS)utils_1.c $(P_SMALL)small.c $(P_SMALL)small_utils.c \
		$(P_BIG)big.c $(P_BIG)big_utils_0.c $(P_BIG)big_utils_1.c

SRC = $(patsubst $(P_SRC)%.c, $(P_OBJ)%.o, $(FILES))

CC = clang
RM = rm -rf
RMR = rm -rf
NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -I ./include/ #-g -fsanitize=address

all: $(NAME)

$(NAME): $(SRC)
	@echo Folder for obj Created.
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "file(push_swap) created."

$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(P_OBJ)
	@mkdir -p $(P_OBJ)big
	@mkdir -p $(P_OBJ)small
	@mkdir -p $(P_OBJ)utils
	@mkdir -p $(P_OBJ)utils/movements
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@$(RM) $(P_OBJ)
	@echo All clean.

fclean: clean
	@$(RM) $(NAME)

re: fclean all
