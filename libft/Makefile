# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maboukra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 22:00:52 by maboukra          #+#    #+#              #
#    Updated: 2015/12/21 15:26:28 by maboukra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = `ls | grep "\.c" | grep "ft_"`

OBJ = `ls | grep "\.o" | grep "ft_"`

all: $(NAME)

$(NAME):
			$(CC) $(FLAGS) -I . -c $(SRC)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)

clean:
			rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re: fclean all
