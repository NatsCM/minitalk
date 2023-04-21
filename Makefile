CLIENT			= client

SRCS_CLIENT		= $(addprefix srcs/, client.c)

SERVER			= server

SRCS_SERVER		= $(addprefix srcs/, server.c)

ifndef WITH_BONUS
	OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)
	OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
else
	OBJS_CLIENT	= $(BONUS_SRCS_CLIENT:.c=.o)
	OBJS_SERVER	= $(BONUS_SRCS_SERVER:.c=.o)
endif

INCS			= includes/minitalk.h

MINILIBFT			= minilibft/minilibft.a

CC			= gcc

RM			= rm -rf

CFLAGS			= -Wall -Wextra -Werror -O3

.c.o:
			@${CC} $(CFLAGS) -c $< -o $@

all:		MINILIBFT	$(CLIENT) $(SERVER)

MINILIBFT:
	make -C ./minilibft/

$(MINILIBFT):
			@/bin/echo -n "$(shell tput setaf 212)Compiling Miniibft: $(shell tput sgr0)"
				@make -sC minilibft > /dev/null
			@echo "$(shell tput setaf 222)[OK]$(shell tput sgr0)"

$(CLIENT):		$(OBJS_CLIENT) $(LIBFT)
			@/bin/echo -n "$(shell tput setaf 212)Compiling \"$(CLIENT)\": $(shell tput sgr0)"
				@${CC} $(CFLAGS) $(OBJS_CLIENT) ./minilibft/minilibft.a -o $(CLIENT)
			@echo "$(shell tput setaf 222)[OK]$(shell tput sgr0)"

$(SERVER):		$(OBJS_SERVER) $(LIBFT)
			@/bin/echo -n "$(shell tput setaf 212)Compiling \"$(SERVER)\": $(shell tput sgr0)"
				@${CC} $(CFLAGS) $(OBJS_SERVER) ./minilibft/minilibft.a -o $(SERVER)
			@echo "$(shell tput setaf 222)[OK]$(shell tput sgr0)"
				@make -s norminette

norminette:
			@if norminette $(SRCS_CLIENT) $(SRCS_SERVER) $(INCS) ./minilibft > /dev/null; then \
				echo "$(shell tput setaf 212)Norminette: $(shell tput setaf 222)[OK]$(shell tput sgr0)"; \
			else \
				echo "$(shell tput setaf 212)Norminette: $(shell tput setaf 210)[KO]$(shell tput sgr0)"; \
			fi
			@sleep 0.2

clean:
			@/bin/echo -n "$(shell tput setaf 212)Deleting project's object files: $(shell tput sgr0)"
				@${RM} $(SRCS_CLIENT:.c=.o) $(SRCS_SERVER:.c=.o)
			@echo "$(shell tput setaf 222)[OK]$(shell tput sgr0)"
			@/bin/echo -n "$(shell tput setaf 212)Deleting Minilibft's object files: $(shell tput sgr0)"
				@make clean -sC minilibft > /dev/null
			@echo "$(shell tput setaf 222)[OK]$(shell tput sgr0)"

fclean:			clean
			@/bin/echo -n "$(shell tput setaf 212)Deleting project's binary files: $(shell tput sgr0)"
				@${RM} $(CLIENT) $(SERVER)
			@echo "$(shell tput bold)$(shell tput setaf 222)[OK]$(shell tput sgr0)"
			@/bin/echo -n "$(shell tput setaf 212)Deleting minilibft.a: $(shell tput sgr0)"
				@${RM} $(LIBFT)
			@echo "$(shell tput setaf 222)[OK]$(shell tput sgr0)"

re:			fclean all

.PHONY: 		all clean fclean re .c.o norminette
