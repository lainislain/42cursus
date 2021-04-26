

NAME = cub3D

SRCS = srcs/cub3d.c \
	   srcs/renderbmp.c \
	   srcs/endgame.c \
	   srcs/keyhooks.c \
	   srcs/checkmap.c \
	   srcs/moveplayer.c \
	   srcs/raycasting.c \
	   srcs/readfile.c \
	   srcs/savedata.c \
	   srcs/sprites.c \
	   srcs/drawtextures.c \
	   srcs/checkfile.c \
	   srcs/minignl.c

OBJS = srcs/cub3d.o \
	   srcs/renderbmp.o \
	   srcs/endgame.o \
	   srcs/keyhooks.o \
	   srcs/checkmap.o \
	   srcs/moveplayer.o \
	   srcs/raycasting.o \
	   srcs/readfile.o \
	   srcs/savedata.o \
	   srcs/sprites.o \
	   srcs/drawtextures.o \
	   srcs/checkfile.o \
	   srcs/minignl.o

CC = clang

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

LINUXFLAGS = -lXext -lX11 -lm -lz

MACFLAGS = -lmlx -framework OpenGL -framework Appkit

all:		$(NAME)

$(NAME):	$(OBJS)
		cd ./libft/ && make
		$(CC) $(CFLAGS) $(MACFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a

clean:		
		$(RM) $(OBJS)
		cd ./libft/ && make fclean

fclean:		clean
		$(RM) $(NAME) cub3D.bmp

re:		fclean all
