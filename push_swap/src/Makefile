NAME = push_swap

SRC = push_swap.c\
	instructs.c\
	moreinstructs.c

OBG = push_swap.o\
	instructs.o\
	moreinstructs.o

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