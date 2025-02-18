NAME		= push_swap
#NAME_BONUS	= checker
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -rf

SRC_DIR		= ./
OBJ_DIR		= obj/
INCLUDE		= -I .
LIBFT_DIR	= libft/
LIBFT_LIB	= ${LIBFT_DIR}libft.a

SRCS		= ${SRC_DIR}main.c \
		  ${SRC_DIR}check_input.c \
		  ${SRC_DIR}check_input_utils.c \
		  ${SRC_DIR}free_utils.c \
		  ${SRC_DIR}init.c \

#SRCS_BONUS	= ${SRC_DIR}main.c

OBJS		= ${SRCS:${SRC_DIR}%.c=${OBJ_DIR}%.o}
#OBJS_BONUS	= ${SRCS_BONUS:${SRC_DIR}%.c=${OBJ_DIR}%.o}

all:		${OBJ_DIR} ${NAME}

${NAME}:	${OBJS} ${LIBFT_LIB}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${INCLUDE} -o ${NAME}

#bonus:		${OBJ_DIR} ${OBJS_BONUS} ${LIBFT_LIB}
#${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBFT_LIB} ${INCLUDE} -o ${NAME_BONUS}

${OBJ_DIR}:	
			@mkdir -p ${OBJ_DIR}

${OBJ_DIR}%.o:	${SRC_DIR}%.c
			@mkdir -p ${OBJ_DIR}
			${CC} ${CFLAGS} -I . -I ${LIBFT_DIR} -c $< -o $@

${LIBFT_LIB}:	
			@echo "Building libft..."
			make -C ${LIBFT_DIR}

clean:
			@echo "Cleaning object files..."
			${RM} ${OBJ_DIR}
			@echo "Cleaning libft objects..."
			make clean -C ${LIBFT_DIR}

fclean:		clean
			@echo "Removing binary and libraries..."
			${RM} ${NAME} ${NAME_BONUS}
			make fclean -C ${LIBFT_DIR}

re:		fclean all

.PHONY:		all bonus clean fclean re
