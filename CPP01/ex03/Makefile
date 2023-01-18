# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 15:29:20 by juzoanya          #+#    #+#              #
#    Updated: 2023/01/18 08:42:55 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb3

SRC = 	HumanA.cpp \
		HumanB.cpp \
		Weapon.cpp \
		main.cpp \

HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp
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