NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRCS = 	src/midpoint.c\
		src/instructs.c\
		src/moreinstructs.c\
		src/utiles.c\
		src/pushrot.c\
		src/revpushrot.c
		

OBG = 	src/push_swap.o\
		src/instructs.o\
		src/moreinstructs.o\
		src/utiles.o

all: $(NAME)

$(NAME):
	cd ./libft/ && make
	cd ..
	gcc $(FLAGS) -c $(SRCS)
	ar -rc push_swap.a *.o
	ranlib push_swap.a
	gcc $(FLAGS) src/checker.c push_swap.a ./libft/libft.a -o checker
	gcc $(FLAGS) src/push_swap.c push_swap.a ./libft/libft.a -o push_swap
clean:
	rm -f $(OBG)
	cd ./libft/ && make fclean
	rm -rf push_swap.a

fclean: clean
	rm -f $(NAME)
	rm -rf checker

re: fclean all