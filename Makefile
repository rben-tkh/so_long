NAME			= so_long

MLX				= -Lmlx -lmlx_Linux -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o
FLAGS			= -Wall -Werror -Wextra -I. -I/usr/include -Imlx -g3 -c

DIR_SRC			= src
DIR_OBJ			= obj

SRC				= so_long.c checkmap.c checkmap_utils.c map.c moove.c
OBJ				= $(SRC:%.c=$(DIR_OBJ)/%.o)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) $(MLX) $(NAME)

$(DIR_OBJ)/%.o:	$(DIR_SRC)/%.c
				mkdir -p $(DIR_OBJ)
				make -C mlx
				$(CC) $(FLAGS) $< -o $@

all:			$(NAME)

clean:
				rm -rf $(DIR_OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
