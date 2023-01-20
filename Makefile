PATH_SRC = ./src/
PATH_MAP = ./map/
PATH_GNL = ./gnl/
PATH_MINILBX = ./minilibx-linux/
PATH_OBJS = ./objs/

MLX = $(PATH_MINILBX)libmlx.a
NAME = so_long

FILES = $(PATH_SRC)check_and_add_map.c $(PATH_SRC)file_map_read.c \
		$(PATH_SRC)game_init.c $(PATH_SRC)game_ultils.c $(PATH_SRC)itoa.c \
		$(PATH_SRC)mount_map.c $(PATH_SRC)so_long_ultils.c $(PATH_SRC)_bonus.c\
		$(PATH_GNL)get_next_line.c $(PATH_GNL)get_next_line_utils.c \


OBJS = $(patsubst $(PATH_SRC)%.c, $(PATH_OBJS)%.o, $(FILES))

CC = clang
CFLAGS = -Wextra -Werror -Wall
MLXFLAGS = -I $(PATH_MINILBX) -L $(PATH_MINILBX) -lmlx -Ilmlx -lXext -lX11
RM = rm -rf
SAN = -fsanitize=leak

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o so_long

$(PATH_OBJS)%.o:	$(PATH_SRC)%.c
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

bonus: all

play: all
	./$(NAME) map/map.ber
clean:
	$(RM) $(PATH_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

fsanitize: fclean all
	$(CC) $(SAN) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o so_long

valgrind: fclean all
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) $(MLX) -o so_long && valgrind ./$(NAME) map/map.ber

.PHONY: re all fclean clean
