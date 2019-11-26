# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bantario <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/05 13:57:13 by bantario          #+#    #+#              #
#    Updated: 2019/11/26 16:08:41 by bantario         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

LIBFT2 = obj/libft

DIR_S = srcs

DIR_O = obj

HEADER = ft_printf.h

SOURCES = main.c
SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@cp libft/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
		@mkdir -p obj
		@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

test:
		@make all misc/main.c


norme:
		norminette ./libft/
		@echo
		norminette ./$(HEADER)/
		@echo
		norminette ./$(DIR_S)/

clean:
		@rm -f $(OBJS)
		@make clean -C $(LIBFT2)
		@make clean -C $(LIBFT)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)
		@make fclean -C $(LIBFT2)

re: fclean all

.PHONY: fclean re norme all clean
