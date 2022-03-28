# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: W2Wizard <w2.wizzard@gmail.com>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/26 21:36:38 by W2Wizard      #+#    #+#                  #
#    Updated: 2022/03/28 14:49:18 by lde-la-h      ########   odam.nl          #
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
LIBVEC	:=	lib/Vectors
LIBFT	:=	lib/libft
ARCHIVE	:=	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBVEC)/libvec42.a $(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
HEADERS	:=	-I include -I $(LIBVEC)/include -I $(LIBMLX)/include -I $(LIBFT)
CFLAGS	:=	-Werror -Wextra -Wall -Wunreachable-code -Ofast
SRCS	:=	$(shell find ./src -iname "*.c")
OBJS 	:=	${SRCS:.c=.o}

#//= Recipes =//#
all: dep $(NAME)

dep:
	@printf "$(GREEN)$(BOLD)\nCompiling MLX42\n$(RESET)"
	@$(MAKE) -C $(LIBMLX)
	@printf "$(GREEN)$(BOLD)\nCompiling Vectors\n$(RESET)"
	@$(MAKE) -C $(LIBVEC)
	@printf "$(GREEN)$(BOLD)\nCompiling libft\n$(RESET)"
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJS)
	@gcc $(OBJS) $(ARCHIVE) -o $(NAME)
	@printf "$(GREEN)$(BOLD)Done\n$(RESET)"

%.o : %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\n\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

clean:
	@echo "$(RED)Cleaning $(NAME)$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBVEC) fclean
	@$(MAKE) -C $(LIBFT) fclean

re:	fclean all