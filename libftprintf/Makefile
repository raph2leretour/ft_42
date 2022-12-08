# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtissera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 17:21:42 by rtissera          #+#    #+#              #
#    Updated: 2022/12/08 15:38:46 by rtissera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = libftprintf.a
SRC = ft_printf.c ft_putchar.c ft_putu.c ft_putstr.c .c ft_putv.c ft_strlen.c ft_putnbr_base.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all clean fclean tildeclean re
