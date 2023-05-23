# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 13:41:30 by rtissera          #+#    #+#              #
#    Updated: 2023/05/23 18:30:01 by rtissera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRC_DIR			:= src
OBJ_DIR			:= obj
SRCS			:=			\
	main.c					\
	utils.c					\
	check_map.c				\
	print_map.c				\
	init_sprite.c			\
	print_sprite.c			\
	printf/ft_putu.c		\
	printf/ft_strlen.c		\
	printf/ft_printf.c		\
	printf/ft_putnbr.c		\
	printf/ft_putstr.c		\
	printf/ft_putchar.c		\
	printf/ft_putnbr_base.c
SRCS			:= $(SRCS:%=$(SRC_DIR)/%)
OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
MLX				:= minilibx-linux/libmlx.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I include
L_FLAGS		:= -lX11 -lXext -lm

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#

RM 			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(MLX) $(L_FLAGS)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

norminette:
	norminette include
	norminette src

re: fclean all

run: re
	-./$(NAME)

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#
.PHONY: clean fclean norminette re run
.SILENT:
