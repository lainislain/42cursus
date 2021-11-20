CC = gcc

NAME = fdf

LIBFT = libft/

FLAGS = -Wall -Wextra -Werror

LINUXFLAGS = -lXext -lX11 -lm -lz

MACFLAGS = -lmlx -framework OpenGL -framework Appkit

SRCS = color.c fdf.c \
	free.c ft_atoi_base.c \
	get_next_line.c inputs.c \
	map_aux.c map.c math_extensions.c \
	project.c render.c vector_aux.c params.c

OBJ = color.o fdf.o free.o ft_atoi_base.o get_next_line.o inputs.o map_aux.o \
	map.o math_extensions.o project.o render.o vector_aux.o params.o

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT) -s
		make -C $(MLX) -s
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -L $(MLX) -lft $(LINUXFLAGS)


clean:
		

fclean: clean
		$(RM) $(NAME)

re: fclean all

bonus: all