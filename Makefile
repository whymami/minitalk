SERVER= server
CLIENT= client

NAME= all

CC= gcc

CFLAGS= -Wall -Wextra -Werror

RM= rm -rf

all: $(SERVER) $(CLIENT)

$(SERVER):
	$(CC) $(CFLAGS) server.c -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c -o $(CLIENT)

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re 