# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/20 10:01:50 by inowak--          #+#    #+#              #
#    Updated: 2025/02/28 09:55:56 by inowak--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color #

CYAN     = \033[1;36m
WHITE    = \033[1;37m
BLACK    = \033[1;30m
ORANGE   = \033[38;5;202m
GRAY     = \033[1;90m
LIGHT_RED = \033[1;91m
LIGHT_GREEN = \033[1;92m
LIGHT_YELLOW = \033[1;93m
LIGHT_BLUE = \033[1;94m
LIGHT_PURPLE = \033[1;95m
LIGHT_CYAN = \033[1;96m
LIGHT_WHITE = \033[1;97m
RED    = \033[1;31m
GREEN  = \033[1;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
PURPLE = \033[1;35m
RESET  = \033[0m

NAME = philo
BONUS = 

CC = cc
CFLAGS := -Wall -Wextra -Werror -g


SRC = mandatory/main.c \
		mandatory/parsing/ft_error.c \
		mandatory/parsing/ft_parsing.c \
		mandatory/tools/ft_atoi.c \
		mandatory/tools/ft_strlen.c \
		mandatory/tools/ft_lst_utils.c\
		mandatory/init/ft_init.c \
		mandatory/exec/unique_philo.c\
		mandatory/exec/process.c\
		mandatory/exec/routine.c\
		mandatory/exec/brother.c\
		mandatory/exec/monitoring.c\
		mandatory/exec/sleep_check.c\
		mandatory/clean/clean.c\

OBJ_DIR = .object

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(ORANGE)";
	@echo " ######   ##   ##   ####    ####      ##### ";
	@echo "  ##  ##  ##   ##    ##      ##      ##   ##";
	@echo "  ##  ##  ##   ##    ##      ##      ##   ##";
	@echo "  #####   #######    ##      ##      ##   ##";
	@echo "  ##      ##   ##    ##      ##   #  ##   ##";
	@echo "  ##      ##   ##    ##      ##  ##  ##   ##";
	@echo " ####     ##   ##   ####    #######   ##### ";
	@echo "$(RESET)";

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -O0 -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)clean$(RESET)"
	@rm -f $(OBJ) $(OBJ_LIB) $(OBJ_BONUS)

fclean: clean
	@echo "$(YELLOW)remove$(YELLOW) $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus