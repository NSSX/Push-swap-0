# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avella <avella@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/28 15:58:31 by avella            #+#    #+#              #
#    Updated: 2017/06/02 17:08:32 by avella           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myExec

CC = gcc

INCLUDES = "libft/includes"

FLAGS = -Wall -Wextra -Werror

SRC =   checker.c libft_func.c usefull_func.c pile_action.c \
	get_next_line.c

SRC2 =  push_swap.c libft_func.c usefull_func.c pile_action.c

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) :
	make -C libft/
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) -I $(INCLUDES)

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIB)
	rm -f $(NAME)

re : fclean all
