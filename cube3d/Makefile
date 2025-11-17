NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_PATH = src/
SRC = main.c \
	utils/clean.c \
	utils/mlx_utils.c \
	player/inputs.c \
	player/movements.c \
	ray/ray_casting.c \
	ray/env_render.c \
	ray/dda.c \
	map/init.c \
	parsing/gest_err.c\
	parsing/gest_id.c\
	parsing/parsing.c\
	parsing/str2arr.c\
	parsing/utils.c \
	parsing/fill_struct.c\
	parsing/gest_map.c\
	lib/ft_calloc.c\
	lib/ft_realloc.c\
	lib/ft_strcmp.c\
	lib/ft_strlen.c\
	lib/ft_strchr.c\
	lib/ft_strdup.c\
	lib/fd_putstr.c\
	lib/ft_strncmp.c\

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

# MLX
MLX_PATH = includes/mlx/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Flags
LFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
INC = -I./includes/

all: $(OBJ_PATH) $(MLX) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/utils
	@mkdir -p $(OBJ_PATH)/player
	@mkdir -p $(OBJ_PATH)/ray
	@mkdir -p $(OBJ_PATH)/map
	@mkdir -p $(OBJ_PATH)/parsing
	@mkdir -p $(OBJ_PATH)/lib

$(MLX):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		printf "[MINILIBX]\n"; \
		printf "⌛ Installing minilibx...\n"; \
		git clone -q https://github.com/42Paris/minilibx-linux.git $(MLX_PATH) && \
		printf "  └⚙️ Compiling minilibx...\n"; \
		make -C $(MLX_PATH) > /dev/null 2>&1 && \
		printf "    └✅ minilibx installed!\n"; \
	elif [ ! -f "$(MLX)" ]; then \
		printf "⚙️  Compiling minilibx...\n"; \
		make -C $(MLX_PATH) > /dev/null 2>&1 && \
		printf "✅ minilibx compiled!\n"; \
	fi

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\033[2K\r⌛ Compilation: $<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

clean:
	@printf "\n🗑️  Removing object files...\n"
	@rm -rf $(OBJ_PATH)
	@if [ -d "$(MLX_PATH)" ]; then \
		printf "🧹 Cleaning mlx\n"; \
		make clean -C $(MLX_PATH) > /dev/null 2>&1; \
		printf "  └✅ mlx cleaned!\n"; \
	fi
	@printf "✅ Cleaning completed!\n\n"

norm:
	@printf "📋 Checking norm...\n"
	@norminette includes/cub3d.h
	@norminette $(SRC_PATH)
	@printf "✅ Check completed!\n"

fclean: clean
	@printf "🗑️  Removing the executable $(NAME)...\n"
	@rm -rf $(NAME)
	@printf "  └✅ Executable removed!\n"
	@printf "\n✅ Full cleaning completed!\n\n"

re: fclean all

.PHONY: all clean fclean re norm
