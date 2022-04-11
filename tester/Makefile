# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 10:53:45 by dvan-der          #+#    #+#              #
#    Updated: 2022/04/11 15:42:19 by dvan-der         ###   ########.fr        #
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
NAME		:= 	tester
MAP			:=	../maps/default.rt
LIBFT		:=	../lib/libft
MLX42		:=	../lib/MLX42/include
ARCHIVE		:=	../lib/libft/libft.a -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ \
				../lib/MLX42/libmlx42.a 
HEADERS		:=	-I ../include -I $(LIBFT) -I $(MLX42) -I ./
CFLAGS		:=	-Wextra -Wall -Werror -Wunreachable-code -Wno-char-subscripts
ifdef DEBUG
	CFLAGS	+=	-g3
else
	CFLAGS	+=	-Ofast -D NDEBUG
endif

T_SRCS		:=	parser_test.c
OBJ_DIR		:=	../obj
T_OBJ_DIR	:=	obj
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
T_OBJS		:=	$(addprefix $(T_OBJ_DIR)/, $(T_SRCS:.c=.o))

#//- Recipes =//#
all: $(NAME)

$(NAME): $(T_OBJ_DIR) $(T_OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(T_OBJS) $(ARCHIVE) -o $@

$(T_OBJ_DIR)/%.o: %.c 
	$(CC) -c $(CFLAGS) $< $(HEADERS) -o $@

run:
	./$(NAME) $(MAP)

$(T_OBJ_DIR):
	mkdir -p $@

fclean:
	rm -f $(NAME)
	rm -rf $(T_OBJ_DIR)

.PHONY: all runtest fclean
