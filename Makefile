# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 10:28:23 by dolvin17          #+#    #+#              #
#    Updated: 2023/10/15 16:23:25 by dolvin17         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =		push_swap.c \
			sort_short.c \

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