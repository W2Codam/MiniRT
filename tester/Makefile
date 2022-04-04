# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 10:53:45 by dvan-der          #+#    #+#              #
#    Updated: 2022/04/04 11:11:01 by dvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

#//= Params =//#
NAME		:= tester
LIB3D		:=	../lib/lib3d
LIBFT		:=	../lib/libft
HEADERS		:=	-I include -I $(LIB3D)/include -I$(LIBFT)/include
CFLAGS		:=	-Werror -Wextra -Wall -Wunreachable-code -Ofast
OBJS		:=	$(OBJ_DIR)/%.o
OBJ_DIR		:=	../obj
T_SRCS		:=	$(shell find ./t_src -iname "*.c")
T_OBJS_DIR	:=	t_obj
T_OBJS		:=	$(addprefix $(T_OBJ_DIR)/, $(notdir $(T_SRCS:.c=.o)))

#//- Recipes =//#
all: $(NAME) runtest

$(NAME): $(T_OBJ_DIR) $(T_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(T_OBJS) -o $@

$(T_OBJS_DIR)/%.o: %.c 
	$(CC) -c $(CFLAGS) $< $(HEADERS) -o $@

$(T_OBJS_DIR):
	mkdir -p $@

runtest:
	./$(NAME)

fclean:
	rm -f $(NAME)
	rm -rf $(T_OBJS_DIR)

.PHONY: all runtest fclean
