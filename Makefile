# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiskow <tiskow@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 09:42:07 by tiskow            #+#    #+#              #
#    Updated: 2016/10/17 05:18:46 by tiskow           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DNAME = libft.o
SRCS= $(wildcard ft_*.c)
OBJS = $(SRCS:.c=.o)
HEADER = -I ./includes/
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra -fPIC
DFLAGS = -fPIC -shared
AR = ar rc
ARQ = ar -q

all: $(NAME)

$(NAME): compilation

compilation:
	$(CC) $(HEADER) $(CFLAGS) $(SRCS)
	$(AR) $(NAME) $(OBJS)

compilationdyn: fclean
	$(CC) $(HEADER) $(CFLAGS) $(SRCS)
	
	
clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
