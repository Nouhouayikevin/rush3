##
## EPITECH PROJECT, 2025
## Droid
## File description:
## c++
##

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage
CXXLFLAGS = -lncurses -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = -lcriterion

SRC = $(wildcard ex06/*.cpp)
OBJ = $(SRC:.cpp=.o)
TEST_SRC = tests/my_tests.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)
NAME = MyGKrellm


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(CXXLFLAGS)

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.gcno' -delete
	find . -type f -name '*.gcda' -delete
	find . -type f -name '*.txt' -delete
	find . -type f -name 'unit_tests' -delete

fclean: clean

re: fclean all

tests_run: $(TEST_OBJ) $(filter-out main.o, $(OBJ))
	$(CXX) $(CXXFLAGS) -o unit_tests $^ $(LDFLAGS)
	./unit_tests; find . -type f -name '*.txt' -delete

coverage:
	gcovr --exclude tests/
