# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edouvier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 10:38:20 by edouvier          #+#    #+#              #
#    Updated: 2019/11/26 11:03:07 by edouvier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \

OBJ   = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
