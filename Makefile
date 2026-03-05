NAME        	= so_long
LIBFT_DIR   	= libft
MINILIBX_DIR	= minilibx
LIBFT       	= $(LIBFT_DIR)/libft.a
MINILIBX		= $(MINILIBX_DIR)/libmlx.a

CC          	= cc
CFLAGS      	= -Wall -Wextra -Werror -g
RM          	= rm -f

MAIN        	= src/so_long.c
SRCS        	= src/maps_parsing.c	src/utils.c		src/utils2.c
OBJS        	= $(SRCS:.c=.o)

GREEN       	= \033[0;32m
RESET       	= \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS) $(MAIN)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Cleaning executable and library..."
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MINILIBX_DIR) clean

norm:
	norminette src/ includes/

re: fclean all

.PHONY: all clean fclean re norm