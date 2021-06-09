NAME = push_swap

SRC = push_swap.c\
	instructs.c\
	moreinstructs.c\
	utiles.c

OBG = push_swap.o\
	instructs.o\
	moreinstructs.o\
	utiles.o

all: $(NAME)

$(NAME):
	cd ../libft/ && make
	gcc $(SRC) ../libft/libft.a -o $(NAME)
clean:
	rm -f $(OBG)
	cd ../libft/ && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all