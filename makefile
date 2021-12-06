# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 20:10:58 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/12/05 22:45:15 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC = ./src
P_UTILS = ./src/utils
P_MOVES = ./src/utils/moves
P_LIBFT = ./include/libft

LIBFT = $(P_LIBFT)/libft.a

FILES = $(P_SRC)/main.c $(P_UTILS)/utils_circular.c $(P_MOVES)/move.c \
		$(P_MOVES)/move_utils.c $(P_MOVES)/move_1.c
SRC = $(FILES:.c=.o)

CC = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
all: comp test

test:
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o file
	@echo file created.

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
	@$(RM) file

re: fclean clean all