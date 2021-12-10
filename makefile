# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 20:10:58 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/12/10 06:48:52 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC = ./src/
P_UTILS = $(P_SRC)utils/
P_MOVEMENTS = $(P_SRC)utils/movements/
P_SMALL = $(P_SRC)small/
P_BIG = $(P_SRC)big/
P_LIBFT = ./include/libft/
P_OBJ = ./obj/
P_INCLUDE = ./include/

FILES = $(P_SRC)main.c $(P_UTILS)utils_0.c $(P_MOVEMENTS)move_0.c \
		$(P_MOVEMENTS)move_1.c $(P_MOVEMENTS)move_2_and_aux.c \
		$(P_UTILS)utils_1.c $(P_SMALL)small.c $(P_SMALL)small_utils.c \
		$(P_BIG)big.c $(P_BIG)big_utils_0.c $(P_BIG)big_utils_1.c

SRC = $(patsubst $(P_SRC)%.c, $(P_OBJ)%.o, $(FILES))

LIBFT = $(P_LIBFT)libft.a

NAME = push_swap

CC = clang
RM = rm -rf
RMR = rm -rf
CFLAGS = -Wall -Werror -Wextra -I ./include/ #-g -fsanitize=address

all: $(NAME)

$(NAME): $(SRC)
	@make --no-print-directory -C $(P_LIBFT)
	@echo Folder for obj Created.
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "file(push_swap) created."

$(P_OBJ)%.o: $(P_SRC)%.c
	@mkdir -p $(P_OBJ)
	@mkdir -p $(P_OBJ)big
	@mkdir -p $(P_OBJ)small
	@mkdir -p $(P_OBJ)utils
	@mkdir -p $(P_OBJ)utils/movements
	@$(CC) $(CFLAGS) -I. -c $< -o $@

val:
	valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes --verbose --log-file=valgrind-out.txt ./$(NAME) $(test)

clean:
	@$(RM) $(P_OBJ)
	@make clean --no-print-directory -C $(P_LIBFT)
	@rm -f valgrind-out.txt
	@echo All clean.

fclean: clean
	@$(RM) $(NAME)
	@make fclean --no-print-directory -C $(P_LIBFT)

re: fclean all
