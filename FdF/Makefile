CC = clang

NAME = fdf

LIBFT = libft/

MLX = mlx_linux/

FLAGS = -Wall -Wextra -Werror

LIBS = -lm -lbsd -lmlx -lXext -lX11

INCLUDE_PATH = includes/

SRCS = srcs/color.c srcs/fdf.c \
	srcs/free.c srcs/ft_atoi_base.c \
	srcs/get_next_line.c srcs/inputs.c \
	srcs/map_aux.c srcs/map.c srcs/math_extensions.c \
	srcs/project.c srcs/render.c srcs/vector_aux.c srcs/params.c

OBJ = color.o fdf.o free.o ft_atoi_base.o get_next_line.o inputs.o map_aux.o \
	map.o math_extensions.o project.o render.o vector_aux.o params.o

RM = rm -rf

all: $(NAME)
	make feiradafruta

$(NAME): $(OBJ)
		@printf "\n$(CY)Compiling Feira da Fruta\n"
		make -C $(LIBFT) -s
		@printf "\n$(YE)Libft Ready\n"
		make -C $(MLX) -s
		@printf "\n$(YE)MLX Ready\n"
		$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT) -L $(MLX) -lft $(LIBS)
		@printf "\n$(GR)Everything compiled\n"
		@printf "\nSorting out the mess\n"
		mkdir tmp
		mv $(OBJ) tmp
		@printf "\nDone!\n$(YE)"

$(OBJ): $(SRCS)
		$(CC) $(FLAGS) -c -I $(INCLUDE_PATH) $(SRCS)

clean:
		@printf "$(RE)\nINCINERATING ALL THE .o\n"
		$(RM) tmp
		make -C $(LIBFT) clean

fclean: clean
		@printf "$(RE)\nSENDING FDF STRAIGHT TO HELL\n"
		$(RM) $(NAME)
		@printf "$(RE)\nDELETING ALL .a FROM EXISTENCE\n"
		make -C $(MLX) clean -s
		make -C $(LIBFT) fclean -s
		@printf "it is done..."

re: fclean all

bonus: all

norm:
	norminette $(INCLUDE_PATH) $(LIBFT) srcs/

instructions:
	@printf "$(RE)(You need to have X11, XShm and bsd installed to run this software)"
	@printf "\n$(CY)Usage: ./fdf [valid fdf file] (check project pdf for more info about fdf files)\n"
	@printf "$(CY)Use WASD to move the camera on the x and y axis\n"
	@printf "$(CY)Use Left Shift and Left Control to move the camera on the z axis\n"
	@printf "$(CY)Use Q and E to perform a yaw on the projection\n"
	@printf "$(CY)Use Left and Right arrows to perform a roll on the projection\n"
	@printf "$(CY)Use Up and Down arrows to perform a pitch on the projection\n\n"

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m