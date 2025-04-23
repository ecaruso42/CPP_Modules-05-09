NAME =PmergeMe
CC = g++
FLAGS = -Wall -Werror -Wextra
SRC =	main.cpp \
		PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all