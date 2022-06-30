# COLORS #
_END		=	\e[0m
_BOLD		=	\e[1m
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m

## VARIABLES ##

# FLAGS #
MAKEFLAGS		+=	--silent
CC				=	clang
CC_FLAGS		=	-Wall -Wextra -Werror
# CC_FLAGS		=	-O3 -g
LDFLAGS			=	-L$(DIR_LIBFT) -lft
MLXFLAGS		=	-L$(DIR_MINILIBX) -lmlx -lXext -lX11 -lm

# CMDS #
RM				=	rm -rf

# DIRECTORIES #
DIR_HEADERS 	=	includes/
DIR_SRCS		=	srcs/
DIR_OBJS		=	objs/
DIR_LIBFT		=	../libft/
DIR_MINILIBX	=	../minilibx-linux

# FILES #
SRCS			=	main.c \
					hook_handler.c \
					mlx_tools.c \
					hook_tools.c \
					mandelbrot.c \
					math_tools.c \
					julia.c \
					burning_ship.c

# COMPILED_SOURCES #
OBJS 			=	$(SRCS:%.c=$(DIR_OBJS)%.o)
NAME 			=	fractol

# **************************************************************************** #

all:			$(NAME)

$(NAME):		$(OBJS)
				echo -n "\033[2K\r✔️$(_GREEN) All files compiled into '$(DIR_OBJS)'. $(_END)\n"
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) ${LDFLAGS} ${MLXFLAGS} -o $(NAME)
				echo -n "\033[2K\r✔️$(_GREEN) Program '$(NAME)' created. $(_END)\n"

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				echo -n "\033[2K\r $(_YELLOW)Compiling $< $(_END)"
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				mkdir $(DIR_OBJS)

bonus:			all

clean:
				$(RM) $(DIR_OBJS)
				echo -n "\033[2K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)\n"

fclean:			clean
				$(RM) $(NAME)
				echo -n "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re:				fclean all

.PHONY:			all clean fclean re bonus
