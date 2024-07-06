NAME = program

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = HumanA.hpp HumanB.hpp Weapon.hpp

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