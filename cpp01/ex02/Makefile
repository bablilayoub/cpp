NAME = program

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(COMPILER) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)