NAME = program

COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

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