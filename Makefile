# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdo-carm <mdo-carm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 14:44:08 by mdo-carm          #+#    #+#              #
#    Updated: 2022/11/13 18:40:22 by mdo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW=\033[0;33m
COLOUR_END=\033[0m

SERVER_C = server.c
CLIENT_C = client.c

MTALK_H = minitalk.h

LIBFT_DIR = Libft/
FT_PRINTF_DIR = ft_printf/

CC = gcc
RM = rm -rf

CFLAGS = -Wall  \
         -Wextra \
         -Werror  \

all: $(NAME)

$(NAME): $(SERVER_C) $(CLIENT_C) $(MTALK_H)
		@$(MAKE) all -C ./Libft
		@$(MAKE) all -C ./ft_printf
		@echo "$(COLOUR_BLUE)Minitalk: Compiling Server...$(COLOUR_END)"
		@sleep 0.2
		@$(CC) $(CFLAGS) $(SERVER_C) $(MTALK_H) $(FT_PRINTF_DIR)libftprintf.a -o server
		@echo "$(COLOUR_GREEN)Minitalk: Server Compiled$(COLOUR_END)"
		@echo "$(COLOUR_BLUE)Minitalk: Compiling Client...$(COLOUR_END)"
		@sleep 0.2
		@$(CC) $(CFLAGS) $(CLIENT_C) $(MTALK_H) $(LIBFT_DIR)/libft.a -o client
		@echo "$(COLOUR_GREEN)Minitalk: Client Compiled$(COLOUR_END)"
		@echo "$(COLOUR_GREEN)Minitalk: Project Fully Compiled$(COLOUR_END)"

client: $(CLIENT_C) $(MTALK_H)
		@$(MAKE) all -C ./Libft
		@echo "$(COLOUR_BLUE)Minitalk: Compiling Client...$(COLOUR_END)"
		@sleep 0.2
		@$(CC) $(CFLAGS) $(CLIENT_C) $(MTALK_H) $(LIBFT_DIR)/libft.a -o client
		@echo "$(COLOUR_GREEN)Minitalk: Client Compiled$(COLOUR_END)"

server: $(SERVER_C) $(MTALK_H)
		@$(MAKE) all -C ./ft_printf
		@echo "$(COLOUR_BLUE)Minitalk: Compiling Server...$(COLOUR_END)"
		@sleep 0.2
		@$(CC) $(CFLAGS) $(SERVER_C) $(MTALK_H) $(FT_PRINTF_DIR)libftprintf.a -o server
		@echo "$(COLOUR_GREEN)Minitalk: Server Compiled$(COLOUR_END)"

clean: 
		@echo "$(COLOUR_BLUE)Minitalk: cleaning...$(COLOUR_END)"
		@sleep 0.2
		@rm -rf $(OBJ)
		@echo "$(COLOUR_GREEN)Minitalk: Object files deleted$(COLOUR_END)"

fclean:	clean
		@$(RM) $(NAME_SERVER) $(NAME_CLIENT) *.o
		@echo "$(COLOUR_GREEN)Minitalk fully cleaned$(COLOUR_END)"
		@sleep 0.2
		@$(MAKE) fclean -C ./Libft
		@$(MAKE) fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re
