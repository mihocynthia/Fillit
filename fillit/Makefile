# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arkim <arkim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 16:46:43 by arkim             #+#    #+#              #
#    Updated: 2019/09/05 21:13:09 by arkim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIB_FT		=	libft/libft.a
LIB_FT_DIR	=	./libft
LIB_FT_LNK	=	-L libft -lft


SRCS_DIR	=	./srcs/
OBJS_DIR	=	./objs/
INCS_DIR	=	./includes/

SRCS		=	$(wildcard $(SRCS_DIR)*.c)
OBJS		=	$(notdir $(SRCS:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CHECK = \033[0;33m\xE2\x9C\x94\033[0m
PINK = \033[0;1;35m
YELLOW = \033[0;33m

all: $(NAME)

$(NAME): $(LIB_FT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(LIB_FT)
	@echo "\n $(CHECK)$(PINK)	Finished !!"

$(LIB_FT):
	@make -C $(LIB_FT_DIR)
	@make clean -C $(LIB_FT_DIR)

$(OBJS):
	@gcc $(CFLAGS) -c $(SRCS) -I $(INCS_DIR)

clean:
	@rm -f $(LIB_FT)
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIB_FT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
