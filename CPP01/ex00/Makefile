
NAME = zombie
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb3


SRC = 	main.cpp \
		Zombie.cpp \
		newZombie.cpp \
		randomChump.cpp \

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