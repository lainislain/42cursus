SERVERNAME = server

CLIENTNAME = client

FLAGS = -Wall -Wextra -Werror

CC = gcc

SRCS = srcs/utils.c\

all:	$(SERVERNAME) $(CLIENTNAME)

$(SERVERNAME):
		$(CC) $(SRCS) srcs/server.c $(FLAGS) -o $(SERVERNAME)

$(CLIENTNAME):
		$(CC) $(SRCS) srcs/client.c $(FLAGS) -o $(CLIENTNAME)

clean:
		$(RM) srcs/*.o

fclean: clean
	$(RM) $(SERVERNAME)
	$(RM) $(CLIENTNAME)

re: fclean all
