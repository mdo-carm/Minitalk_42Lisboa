# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 00:00:15 by mdo-carm          #+#    #+#              #
#    Updated: 2022/11/13 18:23:11 by mdo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW=\033[0;33m
COLOUR_END=\033[0m

C_SOURCE = ft_atoi.c

INCLUDE = libft.h

OBJ = $(C_SOURCE:.c=.o)

CC = gcc

CFLAGS = -Wall  \
         -Wextra \
         -Werror  \

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		@ar -rcs $(NAME) $(OBJ)
		@echo "$(COLOUR_GREEN)Libft archive created$(COLOUR_END)"

%.o: %.c $(INCLUDE)
		@$(CC) $(CFLAGS) -c $< -o $@

clean: 
		@echo "$(COLOUR_BLUE)Libft: cleaning...$(COLOUR_END)"
		@sleep 0.2
		@rm -rf $(OBJ)
		@echo "$(COLOUR_GREEN)Libft: Object files deleted$(COLOUR_END)"

fclean:	clean
		@sleep 0.2
		@rm -rf $(NAME)
		@echo "$(COLOUR_GREEN)Libft fully cleaned$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
