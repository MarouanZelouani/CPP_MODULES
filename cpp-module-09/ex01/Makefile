NAME = span
CPP = c++ 
CPPFLAGS = -Wextra -Werror -Wall -std=c++98 
SRC = main.cpp Span.cpp
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