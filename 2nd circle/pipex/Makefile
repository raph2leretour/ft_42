# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 13:41:30 by rtissera          #+#    #+#              #
#    Updated: 2023/05/31 18:20:05 by rtissera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= pipex

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRC_DIR			:= src
OBJ_DIR			:= obj
LIBFT_DIR		:= libft
FT_PRINTF_DIR	:= libftprintf
SRCS			:=	\
	main.c
SRCS			:= $(SRCS:%=$(SRC_DIR)/%)
OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT			:= $(LIBFT_DIR)/libft.a
FT_PRINTF		:= $(FT_PRINTF_DIR)/libftprintf.a

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I include

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#

RM			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)
	$(info CREATED $(NAME))
	toilet COMPILED	-F border --metal

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(LIBFT):
	make -C $(LIBFT_DIR)
	$(info CREATED $(LIBFT))

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)
	toilet CLEAN -F border --metal

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	toilet FCLEAN -F border --metal

norminette:
	norminette include
	norminette src
	toilet NORMINETTE -F border --metal

re: fclean all

run: re
	clear
	toilet RUN -F border --metal
	-./$(NAME)

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#
.PHONY: clean fclean re run
.SILENT:
