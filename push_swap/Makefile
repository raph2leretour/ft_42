# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 09:14:01 by rtissera          #+#    #+#              #
#    Updated: 2023/03/17 12:43:10 by rtissera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# SRC_DIR	source directory
# OBJ_DIR	object directory
# SRCS		sources files
# OBJS		objects files
#
# CC		compiler
# CFLAGS	compiler flags
# CPPFLAGS	preprocessor flags

SRC_DIR		:= src
OBJ_DIR		:= obj
SRCS		:=	\
	main.c				\
	utils/utils1.c			\
	utils/utils2.c			\
	moves/moves1.c			\
	moves/moves2.c			\
	sort/push_swap.c		\
	libft/ft_atoi.c			\
	libft/ft_lstnew.c		\
	libft/ft_strlen.c		\
	libft/ft_lstsize.c		\
	libft/ft_isdigit.c		\
	libft/ft_lstlast.c		\
	libft/ft_putstr_fd.c	\
	libft/ft_lstadd_back.c	\
	libft/ft_lstadd_front.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I include

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM		force remove
# MAKEFLAGS	make flags
# DIR_DUP	duplicate directory tree

RM 			:= rm -f
MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all		default goal
# $(NAME)	linking .o -> binary
# %.o		compilation .c -> .o
# clean		remove .o
# fclean	remove .o + binary
# re		remake default goal

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(NAME) fclean
	$(NAME) all

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#
.PHONY: clean fclean re
.SILENT:
