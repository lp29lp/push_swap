# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 20:10:58 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/12/06 19:56:24 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P_SRC = ./src
P_UTILS = ./src/utils
P_MOVEMENTS = ./src/utils/movements

FILES = $(P_SRC)/main.c $(P_UTILS)/utils_0.c $(P_MOVEMENTS)/move_0.c \
		$(P_MOVEMENTS)/move_1.c $(P_MOVEMENTS)/move_2_and_aux.c
SRC = $(FILES:.c=.o)

CC = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
all: comp

comp: $(SRC)
	@$(CC) $(CFLAGS) $(SRC) -o file
	@echo file created.

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SRC)
	@echo All clean dude.

fclean: clean
	@$(RM) file

re: fclean clean all