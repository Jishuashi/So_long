NAME            = so_long

LIBFT_DIR       = libft
MINILIBX_DIR    = minilibx

LIBFT           = $(LIBFT_DIR)/libft.a
MINILIBX        = $(MINILIBX_DIR)/libmlx.a

MAIN			= src/so_long.c

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g
MLXFLAG         = -lXext -lX11 -lm -lz

RM              = rm -rf
OBJ_DIR         = obj

SRCS            = src/maps_parsing.c \
                  src/utils/utils.c \
                  src/utils/utils_map.c \
                  src/checker.c \
                  src/map_copy.c \
                  src/flood_fill.c \
                  src/point.c \
                  src/events.c

OBJS            = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

GREEN           = \033[0;32m
RED             = \033[0;31m
RESET           = \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJS)
	@echo -e "$(GREEN)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(MAIN) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAG) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(MINILIBX):
	@$(MAKE) -C $(MINILIBX_DIR) all

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning objects..."
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Cleaning executable..."
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MINILIBX_DIR) clean

norm:
	@ERR_COUNT=$$(norminette src/ includes/ textures/ | grep "Error" | wc -l); \
	if [ $$ERR_COUNT -eq 0 ]; then \
		echo -e "$(GREEN)Norminette: TOUT EST PARFAIT !$(RESET)"; \
	else \
		echo -e "$(RED)Norminette: ERREURS TROUVÉES :$(RESET)"; \
		norminette src/ includes/ textures/ | grep "Error"; \
	fi

re: fclean all

.PHONY: all clean fclean re norm