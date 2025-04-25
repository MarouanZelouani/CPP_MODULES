NAME = phonebook
CC = c++ -Wextra -Werror -Wall
SRC = 
OBJ = $(SRC:=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean : 
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(NAME)

re : fclean all