# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: W2Wizard <w2.wizzard@gmail.com>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/26 21:36:38 by W2Wizard      #+#    #+#                  #
#    Updated: 2022/04/04 12:43:32 by lde-la-h      ########   odam.nl          #
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
NAME	:=	MegaRT
LIBMLX	:=	lib/MLX42
LIB3D	:=	lib/lib3d
LIBFT	:=	lib/libft
ARCHIVE	:=	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIB3D)/lib3D.a $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
HEADERS	:=	-I include -I $(LIB3D)/include -I $(LIBMLX)/include -I $(LIBFT)
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Wno-char-subscripts
ifdef DEBUG
	CFLAGS += -g
else
	CFLAGS	+= -Ofast -D NDEBUG
endif
SRCS	:=	$(shell find ./src -iname "*.c")
OBJS 	:=	${SRCS:.c=.o}

#//= Recipes =//#
all: dep $(NAME)

dep:
	@printf "$(GREEN)$(BOLD)\nCompiling MLX42\n$(RESET)"
	@$(MAKE) -C $(LIBMLX)
	@printf "$(GREEN)$(BOLD)\nCompiling lib3D\n$(RESET)"
	@$(MAKE) -C $(LIB3D)
	@printf "$(GREEN)$(BOLD)\nCompiling libft\n$(RESET)"
	@$(MAKE) -C $(LIBFT)

$(NAME): include/MiniRT.h $(OBJS)
	@gcc $(OBJS) $(ARCHIVE) -o $(NAME)
	@printf "$(GREEN)$(BOLD)Done\n$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

clean:
	@echo "$(RED)Cleaning $(NAME)$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIB3D) fclean
	@$(MAKE) -C $(LIBFT) fclean

re:	fclean all