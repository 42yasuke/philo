# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose <jose@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 20:06:58 by jose              #+#    #+#              #
#    Updated: 2023/04/28 20:44:49 by jose             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFLAGS_OBJ = -Wall -Wextra -Werror -c

RM = rm -f

C_FILES =	error.c \
			utils.c \
			main.c

SRC = $(addprefix src/, $(C_FILES))

OBJ = $(SRC:.c=.o)

INC = -I includes/

LIB = -L. -lft

NAME = philo

all : $(NAME)

libft.a :
			make bonus -C libft

%.o : %.c
			$(CC) $(CFLAGS_OBJ) $< -o $@ $(INC)

$(NAME) : $(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
		$(RM) src/*.o

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all fclean clean re