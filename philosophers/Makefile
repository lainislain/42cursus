FLAGS = -Werror -Wextra -Wall -pthread
NAME = philo
SRC = philo.c utils.c libft.c routine.c
#OBJ = philo.o utils.o libft.o routine.o

all:	$(NAME)

$(NAME) :
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean:

fclean:	clean
	rm -f $(NAME)

re:		fclean all