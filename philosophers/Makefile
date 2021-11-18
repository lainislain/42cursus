NAME = philo

SRC = main.c \
	  routine.c \
	  utils.c \
	  more_utils.c \
	  libft.c\
	  parsing.c

all: $(NAME)

$(NAME):
	gcc $(SRC) -pthread -Wall -Werror -Wextra  -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: fclean all re clean
