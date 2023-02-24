# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 09:14:01 by rtissera          #+#    #+#              #
#    Updated: 2023/02/24 14:44:38 by rtissera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

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
SRCS		:= \
	main.c			\
	src/push_swap.c	\
SRCS		:= $(SRCS:%=$(SRC_DIR)/$)
OBJS		:= $(SRCS:$(SRC_DIR)/%.C=$(OBJ_DIR)/%.o)

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
# run		make and run the default goal
# print		print the value of an arbitrary variable

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
	$(MAKE) fclean
	$(MAKE) all

run: re
	-./$(NAME)

print-%:
	$(info '$*'='$($*)')

#------------------------------------------------#
#   SPEC                                         #
#------------------------------------------------#
.PHONY: clean fclean re run
.SILENT:
