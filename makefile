NAME_CLIENT = client

NAME_SERVER = server

SRCS_CLIENT	= client.c utils/ft_printf.c utils/ft_atoi.c

SRCS_SERVER = server.c utils/ft_printf.c utils/ft_atoi.c

OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}

OBJS_SERVER = ${SRCS_SERVER:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf


${NAME_CLIENT} : ${OBJS_CLIENT}
	${CC} ${CFLAGS} ${OBJS_CLIENT} -o ${NAME_CLIENT}

${NAME_SERVER} : ${OBJS_SERVER}
	${CC} ${CFLAGS} ${OBJS_SERVER} -o ${NAME_SERVER}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ 

clean : 
	${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

fclean : clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

all : ${NAME_CLIENT} ${NAME_SERVER}

re : fclean all

.PHONY : all clean fclean re

