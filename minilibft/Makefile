# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ncardozo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 09:59:29 by ncardozo          #+#    #+#              #
#    Updated: 2023/04/22 22:14:34 by ncardozo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

CC = gcc

NAME = minilibft.a

SRCS = 	ft_printf.c \
		ft_numbers.c \
		ft_str.c \
		ft_formats.c \
		ft_atoi.c \
		ft_memcpy.c \

OBJS = ${SRCS:.c=.o}
		
all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
