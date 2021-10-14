SERVER		:=	server
CLIENT		:=	client

CC :=  clang
CFLAGS	:= -Wall -Wextra -Werror
RM	= rm -f

SRC_DIR		:= srcs

SRC_SERVER	:= ${SRC_DIR}/server.c ${SRC_DIR}/utils.c
OBJ_SERVER 	:= ${SRC_SERVER:.c=.o}

SRC_CLIENT	:= ${SRC_DIR}/client.c ${SRC_DIR}/utils.c
OBJ_CLIENT 	:= ${SRC_CLIENT:.c=.o}

SRC_SERVER_B	:= ${SRC_DIR}/server_bonus.c ${SRC_DIR}/utils.c
OBJ_SERVER_B 	:= ${SRC_SERVER_B:.c=.o}

SRC_CLIENT_B	:= ${SRC_DIR}/client_bonus.c ${SRC_DIR}/utils.c
OBJ_CLIENT_B 	:= ${SRC_CLIENT_B:.c=.o}

all:	${SERVER} ${CLIENT} 

${SERVER}: ${OBJ_SERVER} minitalk.h
	@ ${CC} ${CFLAGS} -o ${SERVER} ${OBJ_SERVER}
	@echo "server is ready"	

${CLIENT}: ${OBJ_CLIENT} minitalk.h
	@ ${CC} ${CFLAGS} -o ${CLIENT} ${OBJ_CLIENT}
	@echo "client is ready"	

${SERVER_B}: ${OBJ_SERVER_B} minitalk_bonus.h
	@ ${CC} ${CFLAGS} -o ${SERVER_B} ${OBJ_SERVER_B}
	@echo "server Bonus is ready"	

${CLIENT_B}: ${OBJ_CLIENT_B} minitalk_bonus.h
	@ ${CC} ${CFLAGS} -o ${CLIENT_B} ${OBJ_CLIENT_B}
	@echo "client Bonus is ready"


bonus: ${SERVER} ${CLIENT} 

clean:
		rm -rf ${OBJ_CLIENT} ${OBJ_SERVER} ${OBJ_CLIENT_B} ${OBJ_SERVER_B}

fclean: clean
		${RM} ${SERVER} ${CLIENT} ${SERVER_B} ${CLIENT_B}

re:		fclean all

.PHONY: all clean fclean re bonus
	







