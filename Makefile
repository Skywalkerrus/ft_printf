# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantario <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 13:57:13 by bantario          #+#    #+#              #
#    Updated: 2019/11/27 16:28:11 by bantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

DIR_S = ./srcs/
SOURCES = float.c number.c parser.c display.c functions.c string.c
SRCS = $(addprefix $(DIR_S), $(SOURCES))

DIR_L = ./libft/
LIBFT_S_F = *.c
LIBFT_S= $(addprefix $(DIR_L), $(LIBFT_S_F))
LIBFT_O = $(addprefix $(DIR_L), $(LIBFT_S_F:.c:=.o))

DIR_H = ./includes/
HEADER = ft_printf.h
HEAD = $(addprefix $(DIR_H), $(HEADER))

DIR_O = ./obj/
OBJS = $(addprefix $(DIR_O), $(SOURCES:.c=.o))

INCLUDES = -I./libft -I./includes
CC = gcc $(FLAGS)


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_O) $(HEAD)
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "OK"

$(DIR_O)%.o: $(DIR_S)%.c
	@mkdir -p $(DIR_O)
	@$(CC) $(INCLUDES) -c $< -o $@

$(DIR_L)%.o: $(DIR_L)%.c
	@mkdir $(DIR_L)
	@$(CC) $(INCLUDES) -c $< -o $@

norme:
		norminette ./libft/
		@echo
		norminette ./$(HEADER)/
		@echo
		norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@make clean -C $(DIR_L)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(DIR_L)

re: fclean all

.PHONY: fclean re all clean
