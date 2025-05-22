NAME = Animal
CPP = c++ 
CPPFLAGS = -Wextra -Werror -Wall -std=c++98 
SRC = AMateria.cpp  Character.cpp  Cure.cpp  Ice.cpp  MateriaSource.cpp	main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME) : $(OBJ)
		$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
.SECONDARY: