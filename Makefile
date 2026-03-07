NAME        	= so_long
LIBFT_DIR   	= libft
MINILIBX_DIR	= minilibx
LIBFT       	= $(LIBFT_DIR)/libft.a
MINILIBX		= $(MINILIBX_DIR)/libmlx.a

CC          	= cc
CFLAGS      	= -Wall -Wextra -Werror -g
MLXFLAG			= -lXext -lX11 -lm -lz
RM          	= rm -f

MAIN        	= src/so_long.c

SRCS        	= src/maps_parsing.c	src/utils.c			src/utils2.c	src/checker.c \
				  src/map_copy.c		src/flood_fill.c	src/point.c		src/events.c

OBJS        	= $(SRCS:.c=.o)

GREEN       	= \033[0;32m
RESET       	= \033[0m

NORM_ERR = norminette src/ includes/ textures/ | grep "Error" | wc -l
NORM = norminette src/ includes/ textures/ | grep "Error" 

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS) $(MAIN)
	@echo -e "$(GREEN)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAG) -o $(NAME)

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
	@ERR_COUNT=$$(norminette src/ includes/ | grep "Error" | wc -l); \
	if [ $$ERR_COUNT -eq 0 ]; then \
		echo -e "\033[32mNorminette: TOUT EST PARFAIT !\033[0m"; \
	else \
		echo -e "\033[31mNorminette: ERREURS TROUVÉES :\033[0m"; \
		norminette src/ includes/ | grep "Error"; \
	fi

re: fclean all

.PHONY: all clean fclean re norm