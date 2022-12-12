# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 19:47:32 by juzoanya          #+#    #+#              #
#    Updated: 2022/12/12 19:47:36 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb3


SRC = 	main.cpp \
		Contact.cpp \
		PhoneBook.cpp \

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
