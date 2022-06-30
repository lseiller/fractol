# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 15:10:57 by lseiller          #+#    #+#              #
#    Updated: 2022/06/06 16:30:28 by lseiller         ###   ########.fr        #
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
MAKEFLAGS 	+=	--silent

## DIRECTORIES ##
SRCS		=	./srcs
DIR			=	./

# CMDS #
RM			=	rm -rf
CP			=	cp -f

# COMPILED_SOURCES #
BONUS		=	bonus
FRACTOL		=	fractol
LIBFT		=	libft
MINILIBX	=	minilibx-linux

# **************************************************************************** #

all:			$(FRACTOL)

$(LIBFT):
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(LIBFT) $(_END)\n"
				$(MAKE) -C $(SRCS)/$(LIBFT)

$(MINILIBX):
				echo -n "\033[2K\r$(_BLUE)$(_BOLD)$(MINILIBX) $(_END)\n"
				$(MAKE) -C $(SRCS)/$(MINILIBX)

$(FRACTOL):		$(LIBFT) $(MINILIBX)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(FRACTOL) $(_END)\n"
				$(MAKE) -C $(SRCS)/$(FRACTOL)
				$(CP) $(SRCS)/$(FRACTOL)/$(FRACTOL) $(DIR)

# bonus:			$(LIBFT) $(MINILIBX)
# 				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(BONUS) $(_END)\n"
# 				$(MAKE) -C $(SRCS)/$(FRACTOL) $(BONUS)
# 				$(CP) $(SRCS)/$(FRACTOL)/$(FRACTOL)

clean:
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(LIBFT) $(_END)\n"
				make clean -C $(SRCS)/$(LIBFT)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(MINILIBX) $(_END)\n"
				make clean -C $(SRCS)/$(MINILIBX)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(FRACTOL) $(_END)\n"
				make clean -C $(SRCS)/$(FRACTOL)

fclean:
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(LIBFT) $(_END)\n"
				make fclean -C $(SRCS)/$(LIBFT)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(MINILIBX) $(_END)\n"
				make clean -C $(SRCS)/$(MINILIBX)
				echo -n	"\033[2K\r$(_BLUE)$(_BOLD)$(FRACTOL) $(_END)\n"
				make fclean -C $(SRCS)/$(FRACTOL)
				$(RM) $(FRACTOL)

re:				fclean all

.PHONY:			all clean fclean re fractol bonus libft minilibx
