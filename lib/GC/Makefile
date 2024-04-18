NAME    = libgarb_collect.a
SRC             = garbage_collector.c
OBJS    = $(SRC:.c=.o)
CC              = cc
RM              = rm -f
CFLAGS  = -Wall -Werror -Wextra
all: ${NAME}
$(NAME):
	${CC} ${CFLAGS} -g -c ${SRC} -o ${OBJS}
	ar rcs ${NAME} ${OBJS}
debug:
	${CC} ${CFLAGS} -D DEBUG=1 -g -c ${SRC} -o ${OBJS}
	ar rcs ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
