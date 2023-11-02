# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 10:28:23 by dolvin17          #+#    #+#              #
#    Updated: 2023/11/02 00:00:59 by ghuertas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		push_swap.c \
			operations.c \
			order_three.c \
			order_five.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror -g
RM_RF = rm -rf
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $(NAME)
clean:
	$(RM_RF) $(OBJS)
fclean: clean
	$(RM_RF) $(OBJS) $(NAME)
re: fclean all
.PHONY: clean fclean all re