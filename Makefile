##
## EPITECH PROJECT, 2025
## Droid
## File description:
## c++
##

CXX = g++
CFLAGS = -g3 -fprofile-arcs -ftest-coverage -std=c++20 -Wall -Wextra
LIBFLAGS = -lncursesw -lsfml-graphics -lsfml-window -lsfml-system
TESTS_FLAGS = -lcriterion
INCLUDES = -I/usr/include
ALL_TESTS_FLAGS = $(CFLAGS) $(TEST_OBJ) $(TESTS_FLAGS) $(LIBFLAGS) $(INCLUDES)

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TEST_SRC = tests/my_tests.cpp
TEST_OBJ = $(TEST_SRC:.cpp=.o)

NAME = MyGKrellm

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFLAGS) $(INCLUDES)

%.o: src/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ $(INCLUDES)

tests_run: $(TEST_OBJ) $(filter-out main.o, $(OBJ))
	$(CXX) $(ALL_TESTS_FLAGS) -o unit_tests
	./unit_tests; find . -type f -name '*.txt' -delete

coverage:
	gcovr --exclude tests/

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
	rm -f unit_tests

re: fclean all
