all :
	rm -rf gnl/get_next_line.h.gch
	gcc gnl/* src/*.c -L ./minilibx-linux -I ./minilibx-linux -lmlx -lX11 -lXext && ./a.out
