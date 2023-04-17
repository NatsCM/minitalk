SERVER_SRCS	= server.c ft_atoi.c
CLIENT_SRCS	= client.c ft_atoi.c
HEADERS		= minitalk.h

CC			= clang -Wall -Werror -Wextra

%.o: %.c ${HEADERS}
			${CC} $< -c -o $@

all:		server client

server:		${SERVER_SRCS:.c=.o} ${HEADERS}
			${CC} ${SERVER_SRCS} -o server

client:		${CLIENT_SRCS:.c=.o} ${HEADERS}
			${CC} ${CLIENT_SRCS} -o client

clean:
			rm -rdf ${SERVER_SRCS:.c=.o} ${CLIENT_SRCS:.c=.o}

fclean:		clean
			rm -rdf client server

re:			fclean all

.PHONY:		all clean fclean re
