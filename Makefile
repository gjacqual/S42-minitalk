SERVER		:=	server
CLIENT		:=	client
SERVER_B	:=	server_bonus
CLIENT_B 	:=	client_bonus 

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

SRC_SERVER_B	:= ${SRC_DIR}/server_bonus.c
OBJ_SERVER_B 	:= ${SRC_SERVER_B:.c=.o}

SRC_CLIENT_B	:= ${SRC_DIR}/client_bonus.c
OBJ_CLIENT_B 	:= ${SRC_CLIENT_B:.c=.o}

INC			:= -I -I${LIBFT_DIR}

all:	${SERVER} ${CLIENT} 

${LIBFT_LIB}: 
	@make -C ./${LIBFT_DIR}

${SERVER}: ${OBJ_SERVER} ${LIBFT_LIB} minitalk.h
	@ ${CC} ${CFLAGS} ${LIBFT_LIB} ${INC} -o ${SERVER} ${OBJ_SERVER}
	@echo "server is ready"	

${CLIENT}: ${OBJ_CLIENT} ${LIBFT_LIB} minitalk.h
	@ ${CC} ${CFLAGS} ${LIBFT_LIB} ${INC} -o ${CLIENT} ${OBJ_CLIENT}
	@echo "client is ready"	

${SERVER_B}: ${OBJ_SERVER_B} ${LIBFT_LIB} minitalk_bonus.h
	@ ${CC} ${CFLAGS} ${LIBFT_LIB} ${INC} -o ${SERVER_B} ${OBJ_SERVER_B}
	@echo "server Bonus is ready"	

${CLIENT_B}: ${OBJ_CLIENT_B} ${LIBFT_LIB} minitalk_bonus.h
	@ ${CC} ${CFLAGS} ${LIBFT_LIB} ${INC} -o ${CLIENT_B} ${OBJ_CLIENT_B}
	@echo "client Bonus is ready"



bonus: $(SERVER_B) $(CLIENT_B)

clean:
		${MAKE} -C ${LIBFT_DIR} clean
		rm -rf ${OBJ_CLIENT} ${OBJ_SERVER} ${OBJ_CLIENT_B} ${OBJ_SERVER_B}

fclean: clean
		${RM} ${SERVER} ${CLIENT} ${LIBFT_LIB} ${SERVER_B} ${CLIENT_B}

re:		fclean all

.PHONY: all libft clean fclean re bonus
	







