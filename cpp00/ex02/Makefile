NAME = account

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Account.hpp

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(COMPILER) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)