# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andi.shkoza <andi.shkoza@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/09 16:08:48 by andi.shkoza       #+#    #+#              #
#    Updated: 2025/08/09 16:08:49 by andi.shkoza      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCS = -I.

SRCS = \
	main.c \
	io.c \
	str_basic.c \
	str_cmp.c \
	str_dup.c \
	str_trim.c \
	dict_utils.c \
	dict.c \
	dict_parse.c \
	convert.c \
	convert_trip.c \
	input.c \
	args.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c rush02.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
