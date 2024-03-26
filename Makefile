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
SOURCES = $(addprefix $(SRC_DIR), ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
	  ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
	  ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
	  ft_lstmap_bonus.c) ft_printf.c ft_printf_c.c ft_printf_s.c \
	  ft_printf_p.c ft_printf_d.c ft_printf_u.c ft_printf_pct.c
OBJECTS = $(SOURCES:%.c=%.o)
BOBJECTS = $(BSOURCES:%.c=%.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c 
	$(CC) $(FLAGS) -I. -o $@ -c $<

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BOBJECTS)
	ar rcs $(NAME) $(BOBJECTS)

full: all clean
	clear
