NAME = libftprintf.a

SRCS = ft_itoa.c ft_manage.c  ft_printf.c ft_utiles.c ft_printconv.c ft_atoi.c

OBJS = ft_itoa.o ft_manage.o  ft_printf.o ft_utiles.o ft_printconv.o ft_atoi.o

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRCS)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
