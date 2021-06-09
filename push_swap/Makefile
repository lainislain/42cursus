NAME = push_swap

SRC = 	src/push_swap.c\
		src/instructs.c\
		src/moreinstructs.c\
		src/utiles.c

OBG = 	src/push_swap.o\
		src/instructs.o\
		src/moreinstructs.o\
		src/utiles.o

all: $(NAME)

$(NAME):
	cd ./libft/ && make
	gcc $(SRC) ./libft/libft.a -o $(NAME)
clean:
	rm -f $(OBG)
	cd ./libft/ && make fclean

fclean: clean
	rm -f $(NAME)

re: fclean all