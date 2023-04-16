CFLAGS = -Wall -Werror -Wextra

RM = rm -f

CC = gcc

CLIENT = client

CLIENTSRC = client.c \
			ft_atoi.c

CLIENTOBJ = $(CLIENTSRC:.c=.o)

SERVER = server

SERVERSRC = server.c

SERVEROBJ = $(SERVERSRC:.c=.o)

HEADER = minitalk.h
		
PINK=\033[0,35m

CYAN=\033[0,36m

NC=\033[0m

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(CLIENT) $(SERVER)

	$(CLIENT): $(CIENTOBJ)
		$(CC) $(CFLAGS) $(CLIENTOBJ) -o $(CLIENT)

	$(SERVER): $(SERVEROBJ)
		$(CC) $(CFLAGS) $(SERVEROBJ) -o $(SERVER)
		@echo "$(CYAN)Compilation done !$(NC)"

clean:
	${RM} ${CLIENTOBJ} ${SERVEROBJ}

fclean:	clean
	${RM} ${CLIENT} ${SERVER}

re:	fclean all

test:
	git clone 

.PHONY:	all clean fclean re
