# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 08:52:51 by juzoanya          #+#    #+#              #
#    Updated: 2023/01/27 08:53:42 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb3

SRC = 	Fixed.cpp \
		main.cpp \

HEADERS = Fixed.hpp
INCS = .

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(CFLAGS) -I$(INCS) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re