FLAGS = -Werror -Wextra -Wall -pthread
NAME = philo
SRC = philo.c outils.c outils_libft.c working.c

all:	$(NAME)

$(NAME) : $(SRC)
	gcc $(FLAGS) $(SRC) -o $(NAME)

clean:
	

fclean:	clean
	rm -f $(NAME)

re:		fclean all