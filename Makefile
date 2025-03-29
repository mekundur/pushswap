# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mekundur <mekundur@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 19:34:04 by mekundur          #+#    #+#              #
#    Updated: 2024/02/19 09:29:51 by mekundur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = pushswap.h
SOURCES = pushswap.c input.c list1.c list2.c ops1.c ops2.c utils1.c utils2.c \
	  sorting1.c sorting2.c sorting3.c sorting4.c

OBJECTS = $(SOURCES:.c=.o)

all : $(NAME) 

%.o: %.c
	@echo "Compiling object files from source files:"
	cc -c -Werror -Wall -Wextra $< -o $@

$(NAME) : $(OBJECTS) $(HEADER)
	@echo "<Creating <push_swap> executable"
	cc -Werror -Wall -Wextra $(OBJECTS) -o $(NAME)

clean :
	@echo "<Removig object files>"
	rm -f $(OBJECTS) 

fclean : clean 
	@echo "<Removing the executable>"
	rm -f push_swap

re : fclean all

.PHONY: all, clean, fclean, re
