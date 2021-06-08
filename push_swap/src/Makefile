NAME = push_swap

SRC = push_swap.c

OBG = push_swap.o

all: $(NAME)

$(NAME):
	cd ../libft/ && make
	gcc $(SRC) ../libft/libft.a -o $(NAME)
clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME)

re: fclean all