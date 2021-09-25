NAME = a.out
CC = gcc
FLUG = ./minilibx-linux/libmlx.a -lXext -lX11
SRC = main.c libft.c libft2.c error.c read_map.c init_data.c

all		:$(NAME)
$(NAME)	:$(SRC)
	$(CC) $(SRC) $(FLUG) -o $@
clean	:
	rm -f $(NAME)
fclean	:
	rm -f $(NAME)
re		:fclean clean all

.PHONY		:all clean fclean re
