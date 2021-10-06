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

${LIBFT_LIB}: 
	@make -C ./${LIBFT_DIR}

${SERVER}: ${OBJ_SERVER} ${LIBFT_LIB} 
	@ ${CC} ${CFLAGS} ${LIBFT_LIB} ${INC} -o ${SERVER} ${OBJ_SERVER}
	@echo "server is ready"	

${CLIENT}: ${OBJ_CLIENT} ${LIBFT_LIB}
	@ ${CC} ${CFLAGS} ${LIBFT_LIB} ${INC} -o ${CLIENT} ${OBJ_CLIENT}
	@echo "client is ready"	



clean:
		${MAKE} -C ${LIBFT_DIR} clean
		rm -rf ${OBJ_CLIENT} ${OBJ_SERVER}

fclean: clean
		${RM} ${SERVER} ${CLIENT} ${LIBFT_LIB}

re:		fclean all

.PHONY: all libft clean fclean re
	







