# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 19:46:37 by juzoanya          #+#    #+#              #
#    Updated: 2022/12/12 19:46:45 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRC = megaphone.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
