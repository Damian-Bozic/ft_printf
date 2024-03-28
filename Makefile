# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbozic <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 18:54:12 by dbozic            #+#    #+#              #
#    Updated: 2024/03/20 12:55:12 by dbozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
SRC_DIR = libft/
SOURCES = ft_printf.c ft_printf_c.c ft_printf_s.c \
	  ft_printf_p.c ft_printf_d.c ft_printf_u.c \
	  ft_printf_xx.c ft_putchar_fd.c ft_putnbr_fd.c \
	  ft_putstr_fd.c ft_strlen.c ft_bzero.c
OBJECTS = $(SOURCES:%.c=%.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c 
	$(CC) $(FLAGS) -I. -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

full: all clean
	clear

.PHONY: clean fclean