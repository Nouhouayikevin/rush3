##
## EPITECH PROJECT, 2025
## Droid
## File description:
## c++
##

CXX = g++
CFLAGS = -g3 -fprofile-arcs -ftest-coverage -std=c++20 -Wall -Wextra -Werror
CXXLFLAGS = -lncurses -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = -lcriterion

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TEST_SRC = tests/my_tests.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
NAME = MyGKrellm


all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $(CXXLFLAGS) -o $(NAME) $(SRC)

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name 'a.out' -delete
	find . -type f -name '*.gcno' -delete
	find . -type f -name '*.gcda' -delete
	find . -type f -name '*.txt' -delete
	find . -type f -name 'unit_tests' -delete
	find . -type f -name 'coding-style-reports.log' -delete

fclean: clean
	rm -f $(NAME)

re: fclean all

tests_run: $(TEST_OBJ) $(filter-out main.o, $(OBJ))
	$(CXX) $(CFLAGS) -o unit_tests $^ $(LDFLAGS)
	./unit_tests; find . -type f -name '*.txt' -delete

coverage:
	gcovr --exclude tests/
