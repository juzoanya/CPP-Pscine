# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 09:51:13 by juzoanya          #+#    #+#              #
#    Updated: 2023/05/12 09:52:11 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb3

SRC = 	Animal.cpp \
		main.cpp \

HEADERS = 	Animal.hpp
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