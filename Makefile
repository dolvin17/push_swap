# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 10:28:23 by dolvin17          #+#    #+#              #
#    Updated: 2023/12/13 16:21:00 by dolvin17         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		main.c \
			long_atoi.c \
			ft_split.c \
			check_args.c\
			operations.c \
			double_operations.c \
			algorithms.c \
			utils.c \
			customizing_stack_a.c \
			customizing_stack_b.c \
			pushing_cheapest_stack_b.c \

BONUS_SRC = checker_bonus/checker.c \
			checker_bonus/checker_utils.c \
			checker_bonus/checker_utils2.c \
			checker_bonus/checking_operations.c \
			checker_bonus/check_double_op.c \
			checker_bonus/gnl/get_next_line.c \
			checker_bonus/gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -g
RM_RF = rm -f
NAME = push_swap
BONUS = checker


all: $(NAME) $(BONUS)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
$(BONUS): $(BONUS_OBJ)
	$(CC) $(CC_FLAGS) $(BONUS_OBJ) -o $(BONUS)
bonus: $(BONUS)
clean:
	@$(RM_RF) $(OBJS) $(BONUS_OBJ)
	@sleep 1
	@echo "\033[3;31m..cleanning\033[0m"
fclean: clean
	@$(RM_RF) $(OBJS) $(BONUS_OBJ) $(NAME) $(BONUS)
	@sleep 1
	@echo "\033[3;31m..removed object files && also executables\033[0m"
re: fclean all
.PHONY: clean fclean all re