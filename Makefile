NAME		= push_swap
NAME_BONUS	= checker
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
		  ${SRC_DIR}init_stack.c \
		  ${SRC_DIR}init_stack_utils.c \
		  ${SRC_DIR}sort_stack.c \
		  ${SRC_DIR}sort_stack_utils.c \
		  ${SRC_DIR}movements.c \
		  ${SRC_DIR}ab_movements.c \
		  ${SRC_DIR}a_to_b.c \
		  ${SRC_DIR}rotate.c \
		  ${SRC_DIR}b_to_a.c \

SRCS_BONUS	= ${SRC_DIR}1_main_bonus.c \
		  ${SRC_DIR}1_check_input_bonus.c \
		  ${SRC_DIR}1_check_input_utils_bonus.c \
		  ${SRC_DIR}1_free_utils_bonus.c \
		  ${SRC_DIR}1_init_stack_bonus.c \
		  ${SRC_DIR}1_init_stack_utils_bonus.c \
		  ${SRC_DIR}1_sort_stack_bonus.c \
		  ${SRC_DIR}1_movements_bonus.c \
		  ${SRC_DIR}1_ab_movements_bonus.c \
		  ${SRC_DIR}1_checker_bonus.c \
		  ${SRC_DIR}1_checker_utils_bonus.c \

OBJS		= ${SRCS:${SRC_DIR}%.c=${OBJ_DIR}%.o}
OBJS_BONUS	= ${SRCS_BONUS:${SRC_DIR}%.c=${OBJ_DIR}%.o}

all:		${OBJ_DIR} ${NAME}

${NAME}:	${OBJS} ${LIBFT_LIB}
			${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} ${INCLUDE} -o ${NAME}

bonus:		${OBJ_DIR} ${OBJS_BONUS} ${LIBFT_LIB}
			${CC} ${CFLAGS} ${OBJS_BONUS} ${LIBFT_LIB} ${INCLUDE} -o ${NAME_BONUS}

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
