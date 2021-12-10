# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-d <lpaulo-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/01 15:06:48 by lpaulo-d          #+#    #+#              #
#    Updated: 2021/12/10 11:31:30 by lpaulo-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_bzero.c ft_strlen.c ft_calloc.c ft_putendl_fd.c 
SRC = $(FILES:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RE = rm -f

all: $(NAME)

$(NAME): $(SRC)
	@ar -rcs $(NAME) $(SRC)

$(SRC): $(FILES)
	@$(CC) $(FLAGS) -c $(FILES)

clean:
	@$(RM) $(SRC)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

