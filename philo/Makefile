# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/15 21:11:27 by buehara           #+#    #+#              #
#    Updated: 2026/01/15 21:11:29 by buehara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---- Colors ----

C_BOLD	= \033[1m
C_BLUE	= \033[0;34
C_GREEN	= \033[0;32
C_RED	= \033[0;31
C_END	= \033[0m


#---- File Vars ----

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3

SRCS_FILES	= main.c \
			  parsing.c \
			  philo_utils.c

SRCS		= $(SRCS_FILES)

OBJS_DIR	= obj

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS_FILES:.c=.o))


#---- Recipes ----

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "\n$(C_GREEN);1m\t -> [ COMPILING ]$(C_END)\n"
	$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "\n$(C_GREEN);1m\t -> [ COMPILATION COMPLETED ]$(C_END)\n"


$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(C_GREEN)m\t -> $(C_BOLD)[ COMPILED ] $(C_END) $(C_END) $(C_BLUE)m $(notdir $<)$(C_END)"


#---- Clean ----

clean :
	@rm -fr $(OBJS_DIR)
	@echo "\t -> $(C_RED)mOBJS Deleted$(C_END)"

fclean : clean
	@rm -f $(NAME)
	@echo "\t -> $(C_RED)mFiles Deleted$(C_END)"

re : fclean all

.PHONY: all clean fclean re
