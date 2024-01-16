# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alaaouam <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 20:45:55 by alaaouam          #+#    #+#              #
#    Updated: 2023/03/17 15:10:01 by alaaouam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	COLOURS	#

GREEN = \033[0:32m
COLOR_OFF = \033[0m

#	VARIABLES	#

NAME = pipex

SRC = pipex.c ft_getpath.c ft_processes.c free_utils.c file_utils.c exit_utils.c array_utils.c parser.c ft_getpath_utils.c

SRC_PATH = src/*/
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
INCLUDE = include/


CC = gcc
CFLAGS =  -Wall -Wextra -Werror -I $(INCLUDE) -I ./libft/include
RM = rm -rf

#	RULES	#

all: $(NAME)

$(LIBFT): $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)
	
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)<+> Pipex has been created! <+>$(COLOR_OFF)"

clean:
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJ_PATH)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME) 
	@echo "$(GREEN)<-> Pipex cleaned successfuly! <->$(COLOR_OFF)"

re: fclean all

.PHONY: all clean fclean re