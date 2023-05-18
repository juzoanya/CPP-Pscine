# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 09:58:49 by juzoanya          #+#    #+#              #
#    Updated: 2023/05/05 13:29:30 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scavTrap
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb3

SRC = 	ClapTrap.cpp \
		ScavTrap.cpp \
		main.cpp \

HEADERS = 	ScavTrap.hpp	ClapTrap.hpp
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