NAME		:= philo

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRC_DIR			:= src
OBJ_DIR			:= obj
SRCS			:=		\
	main.c				\
	init.c				\
	routine.c			\
	destroy.c			\
	atouille.c			\
	get_time_in_ms.c
SRCS			:= $(SRCS:%=$(SRC_DIR)/%)
OBJS			:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

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
