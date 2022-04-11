# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:      :+:    :+:    #
#                                                      +:+                     #
#    By: W2Wizard <w2.wizzard@gmail.com>              +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/26 21:36:38 by W2Wizard      #+#    #+#                  #
#    Updated: 2022/04/11 14:08:25 by lde-la-h      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#//= Colors =//#
BOLD		:= \033[1m
BLACK		:= \033[30;1m
RED			:= \033[31;1m
GREEN		:= \033[32;1m
YELLOW		:= \033[33;1m
BLUE		:= \033[34;1m
MAGENTA		:= \033[35;1m
CYAN		:= \033[36;1m
WHITE		:= \033[37;1m
RESET		:= \033[0m

#//= Params =//#
NAME		:=	MegaRT
LIBMLX		:=	lib/MLX42
LIBFT		:=	lib/libft
ARCHIVE		:=	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ \
				$(LIBMLX)/libmlx42.a $(LIBFT)/libft.a
HEADERS		:=	-I include -I $(LIBMLX)/include -I $(LIBFT)

CFLAGS		:=	-Wextra -Wall -Werror -Wunreachable-code -Wno-char-subscripts
ifdef DEBUG
	CFLAGS	+=	-g3
else
	CFLAGS	+=	-Ofast -D NDEBUG
endif

SRC_DIR		:=	src
VPATH		:=	$(subst $(space),:,$(shell find $(SRC_DIR) -type d))
MAIN		:=	main.c
export SRCS	:=	ft_parser.c \
				ft_parse_lights_cameras.c \
				ft_parse_objects.c \
				ft_parse_utils.c \
				ft_atof_atoi.c \
				rendering.c \
				camera.c \
				Ray_Operations.c \
				Vector_NewF.c \
				Vector_Arithmetic_Float.c \
				Vector_Arithmetic_Vec3.c \
				Vector_Operations.c
ALL_SRCS	:=	$(MAIN) $(SRCS)
OBJ_DIR		:=	obj
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(ALL_SRCS:.c=.o))
TESTER		:=	tester

#//= Recipes =//#
all: dep $(NAME)

dep:
	@printf "$(GREEN)$(BOLD)\nCompiling MLX42\n$(RESET)"
	@$(MAKE) -C $(LIBMLX)
	@printf "$(GREEN)$(BOLD)\nCompiling libft\n$(RESET)"
	@$(MAKE) -C $(LIBFT)

$(NAME): $(OBJ_DIR) $(OBJS)
	@gcc $(OBJS) $(ARCHIVE) -o $(NAME)
	@printf "$(GREEN)$(BOLD)Done\n$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "$(GREEN)$(BOLD)\rCompiling: $(notdir $<)\r\e[35C[OK]\n$(RESET)"

$(OBJ_DIR):
	mkdir -p $@

test: dep $(OBJ_DIR) $(OBJS)
	@$(MAKE) -C $(TESTER)
	@$(MAKE) -C $(TESTER) run

clean:
	@echo "$(RED)Cleaning $(NAME)$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(TESTER) fclean

re:	fclean all
