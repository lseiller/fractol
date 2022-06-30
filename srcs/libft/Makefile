# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 15:50:51 by lseiller          #+#    #+#              #
#    Updated: 2022/06/27 12:45:22 by lseiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
MAKEFLAGS	+=	--silent
CC			=	clang
CC_FLAGS	=	-Wall -Wextra -Werror

# CMDS #
RM			=	rm -rf

# DIRECTORIES #
DIR_HEADERS =	includes/
DIR_SRCS	=	srcs/
DIR_OBJS	=	objs/

# FILES #
SRCS			=	ft_atoi.c \
				ft_atof.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_putptr_fd.c \
				ft_putnbr_base_fd.c \
				ft_puthex_fd.c \
				ft_check_base.c \
				ft_putnbr_base_un_fd.c \
				ft_printf.c \
				get_next_line.c \
				ft_strjoin_free.c \
				get_next_line_utils.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstadd_back.c \
				ft_strcmp.c \
				ft_dprintf.c \
				ft_split_path.c \
				ft_free_split.c \
				ft_strncut.c \
				ft_strjoin_sep.c \
				ft_substr_set.c

# COMPILED_SOURCES #
OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)
NAME 		=	libft.a


# **************************************************************************** #

all:			$(NAME)

$(NAME):		$(OBJS)
				echo -n "\033[2K\r✔️$(_GREEN) All files compiled into '$(DIR_OBJS)'. $(_END)\n"
				ar rc $@ $?
				ranlib $@
				echo -n "\033[2K\r✔️$(_GREEN) Library '$(NAME)' created. $(_END)\n"

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				echo -n "\033[2K\r $(_YELLOW)Compiling $< $(_END)"
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				mkdir $(DIR_OBJS)

clean:
				$(RM) $(DIR_OBJS)
				echo -n "\033[2K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)\n"

fclean:			clean
				$(RM) $(NAME)
				echo -n "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

re:				fclean all

.PHONY:			all clean fclean re
