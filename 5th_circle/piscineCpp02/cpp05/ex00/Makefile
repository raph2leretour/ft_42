#------------------------------------------------------------------------------#
#   NAME                                                                       #
#------------------------------------------------------------------------------#
NAME		:= ex00

#------------------------------------------------------------------------------#
#   INGREDIENTS                                                                #
#------------------------------------------------------------------------------#
SRCS_DIR	:= srcs
SRCS		:= \
				main.cpp \
				class/Bureaucrat.cpp
SRCS		:= $(SRCS:%=$(SRCS_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRCS_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CXX			:= c++
CFLAGS		:= $(CFLAGS) -Wall -Wextra -Werror -std=c++98
CPPFLAGS	:= $(CPPFLAGS) -Iincs

#------------------------------------------------------------------------------#
#   UTENSILS                                                                   #
#------------------------------------------------------------------------------#
RM			:= rm -fr
MAKE		:= $(MAKE) --jobs --silent --no-print-directory
DIR_DUP		= mkdir -p $(@D)
VALGRIND	:= valgrind -q -s --leak-check=yes --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes --verbose
ERR_MUTE	:= 2>/dev/null

CRUSH		:= \r\033[K
ECHO		:= echo -n "$(CRUSH)"
R			:= $(shell tput setaf 1)
G			:= $(shell tput setaf 2)
END			:= $(shell tput sgr0)

#------------------------------------------------------------------------------#
#   RECIPES                                                                    #
#------------------------------------------------------------------------------#
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)
	$(ECHO)"$(G)CREATED$(END) $(@)\n"

$(BUILD_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(DIR_DUP)
	$(CXX) $(CFLAGS) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<
	$(ECHO)"$(G)CREATED$(END) $(@)\n"

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
	$(ECHO)"$(R)DELETED $(BUILD_DIR)$(END)\n"

fclean: clean
	$(RM) $(NAME)
	$(ECHO)"$(R)DELETED $(NAME)$(END)\n"

re:
	$(MAKE) fclean
	$(MAKE) all

run-%: $(NAME)
	-./$(NAME) $*


vrun-%: CFLAGS += -g3
vrun-%: $(NAME)
	-$(VALGRIND) ./$(NAME) $*

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

print-%:
	$(info $*='$($*)')

#------------------------------------------------------------------------------#
#   SPEC                                                                       #
#------------------------------------------------------------------------------#
.PHONY: clean fclean re
.SILENT:
