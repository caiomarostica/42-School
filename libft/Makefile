# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 01:05:10 by coder             #+#    #+#              #
#    Updated: 2022/10/06 01:30:19 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

LIB_PATH = ./

SOURCES = \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_bzero.c ft_isascii.c ft_isprint.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putnbr_fd.c ft_strjoin.c ft_strtrim.c ft_putendl_fd.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c\


OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)

clean:
	$(REMOVE) $(OBJECTS)

%.o: %.c
	gcc -c $(FLAGS) $< -o $@
	ar -rcs $(NAME) $@

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

git: fclean
	git status
	echo "Commiting in 5 seconds"
	sleep 5
	git add *.c *h Makefile
	git commit -m "Automatic commit from Makefile"
	git push
