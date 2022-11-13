# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 14:02:54 by mdo-carm          #+#    #+#              #
#    Updated: 2022/11/13 18:41:35 by mdo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW=\033[0;33m
COLOUR_END=\033[0m

C_SOURCE = ft_printf.c       \
           ft_printf_flags.c \

H_SOURCE = ft_printf.h

CC = gcc

C_FLAGS = -Wall  \
          -Wextra \
          -Werror  \

OBJ = $(C_SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(H_SOURCE)
		@ar -rcs $(NAME) $(OBJ)
		@echo "$(COLOUR_GREEN)ft_printf archive created$(COLOUR_END)"

%.o: %.c $(H_SOURCE)
		@$(CC) $(C_FLAGS) -c $< -o $@

clean: 
		@echo "$(COLOUR_BLUE)ft_printf: cleaning...$(COLOUR_END)"
		@sleep 0.2
		@rm -rf $(OBJ)
		@echo "$(COLOUR_GREEN)ft_printf: Object files deleted$(COLOUR_END)"

fclean:	clean
		@sleep 0.2
		@rm -rf $(NAME)
		@echo "$(COLOUR_GREEN)ft_printf fully cleaned$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re