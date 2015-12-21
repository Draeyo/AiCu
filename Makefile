# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlistrat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 15:22:11 by vlistrat          #+#    #+#              #
#    Updated: 2015/12/21 20:17:49 by vlistrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1

SRC = `ls | grep "\.c"`

OBJ = `ls | grep "\.o"`

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

.PHONY: clean fclean re all $(NAME) $(OBJ) $(LIB)
