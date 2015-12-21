# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 15:22:11 by vlistrat          #+#    #+#              #
#    Updated: 2015/12/21 23:13:57 by rmicolon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC = ft_display.c \
	  ft_play.c \
	  ft_get.c \
	  ft_solve.c \
	  main.c \
	  ft_bufextend.c \

OBJ = $(SRC:.c=.o)

LIB = -lft

LIBDIR = libft

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L. $(LIB)

$(OBJ): $(LIB)
	gcc -I . -c $(SRC) -Wall -Werror -Wextra

$(LIB):
	@(cd $(LIBDIR) && $(MAKE) && cp $(LIBDIR).a $(LIBDIR).h ../)

clean: cleanlib
	/bin/rm -f $(OBJ)

cleanlib:
	@(cd $(LIBDIR) && $(MAKE) clean)

fclean: clean fcleanlib
	/bin/rm -f $(NAME) $(LIBDIR).a $(LIBDIR).h

fcleanlib:
	@(cd $(LIBDIR) && $(MAKE) fclean)

re: fclean all

.PHONY: clean fclean re all
