# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 14:44:08 by mdo-carm          #+#    #+#              #
#    Updated: 2022/10/07 14:44:23 by mdo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

C_SOURCE = 
           
INCLUDE = 

OBJ = $(C_SOURCE:.c=.o)

CC = gcc

CFLAGS = -Wall    \
         -Wextra  \
         -Werror  \

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		ar -rcs $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
		$(CC) $(CFLAGS) -c $< -o $@

clean: 
		rm -rf $(OBJ)
		@echo "Libft cleaned"

fclean:	clean
		rm -rf $(NAME)
		@echo "Libft full cleaned"

re: fclean all

.PHONY: all clean fclean re
