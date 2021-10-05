SERVER	:=	server
CLIENT	:=	client 

CC :=  clang
CFLAGS	:= -Wall -Wextra -Werror
RM	= rm -f

LIBFT_DIR	:= libft
LIBFT_LIB	:= ${LIBFT_DIR}/libft.a


SRC_DIR		:= srcs

SRC_SERVER	:= ${SRC_DIR}/server.c
OBJ_SERVER 	:= ${SRC_SERVER:.c=.o}

SRC_CLIENT	:= ${SRC_DIR}/client.c
OBJ_CLIENT 	:= ${SRC_CLIENT:.c=.o}

HEADERS_PATH := includes/
INC			:= -I${HEADERS_PATH}  -I${LIBFT_DIR}

all:	${SERVER} ${CLIENT}

${SERVER}: ${OBJ_SERVER} ${LIBFT}
	@ ${CC} ${CFLAGS} ${LIBFT} ${INC} -o ${SERVER} ${OBJ_SERVER}
	@echo "server is ready"	

${CLIENT}: ${OBJ_CLIENT} ${LIBFT}
	@ ${CC} ${CFLAGS} ${LIBFT} ${INC} -o ${CLIENT} ${OBJ_CLIENT}
	@echo "client is ready"	

${LIBFT}: 
	${MAKE} -C ${LIBFT_DIR}

clean:
		${MAKE} -C libft clean
		rm -rf ${OBJ_CLIENT} ${OBJ_SERVER}

fclean: clean
		${RM} ${SERVER} ${CLIENT} ${LIBFT_LIB}

re:		fclean all

.PHONY: all libft clean fclean re
	







