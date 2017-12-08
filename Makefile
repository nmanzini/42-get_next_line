# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 17:51:18 by nmanzini          #+#    #+#              #
#    Updated: 2017/12/08 14:17:15 by nmanzini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printNextLine

SRC = 	main.c\
		get_next_line.c 

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

HEADER = -c -I lib_fillit.h

all: $(NAME)

$(OBJ): %.o: %.c
		-@gcc -c -Wall -Werror -Wextra -I libft/ $< -o $@

$(LIBFT):
	-@ make -C libft 

$(NAME): $(LIBFT) $(OBJ)
	-@ gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	-@ /bin/rm -f $(OBJ)
	-@ make -C libft clean

fclean: clean
	-@ /bin/rm -f $(NAME)
	-@ make -C libft fclean

re: fclean all
