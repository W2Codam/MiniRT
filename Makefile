# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: W2Wizard <w2.wizzard@gmail.com>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/26 21:36:38 by W2Wizard      #+#    #+#                  #
#    Updated: 2022/04/11 21:47:26 by lde-la-h      ########   odam.nl          #
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

NAME	:= MiniRT
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}
LIBMLX	:=	lib/MLX42
LIBFT	:=	lib/libft
HEADERS := -I ./include -I $(LIBFT) -I $(LIBMLX)/include/
ARCHIVE := -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBFT)/libft.a $(LIBMLX)/libmlx42.a
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Wno-char-subscripts
ifdef DEBUG
	CFLAGS	+=	-g3
else
	CFLAGS	+=	-Ofast -D NDEBUG
endif

#//= Make Rules =//#

all: dep $(NAME)

dep:
	@printf "$(GREEN)$(BOLD)\nCompiling MLX42\n$(RESET)"
	@$(MAKE) -C $(LIBMLX)
	@printf "$(GREEN)$(BOLD)\nCompiling libft\n$(RESET)"
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS)
	@gcc $(OBJS) $(ARCHIVE) -o $(NAME)
	@echo "$(GREEN)$(BOLD)Done$(RESET)"

%.o: %.c
	@echo "$(GREEN)$(BOLD)Compiling: $(notdir $<)$(RESET)"
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@echo "$(RED)Cleaning $(NAME)$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean

re:	fclean all
