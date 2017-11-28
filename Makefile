OBJS = $(addsuffix .o, $(addprefix objs/, main setup run bind mandelbrot \
		julia ship bird tricorn tapis utl render))

NAME = fractol
INCS = -I includes -I libft

all: $(NAME)

$(NAME): objs $(OBJS)
	make -C libft
	make -C minilibx
	gcc -o $(NAME) -lmlx -framework OpenGL -framework AppKit $(OBJS) \
	libft/libft.a

objs:
	mkdir objs

objs/%.o: srcs/%.c
	gcc -o $@ -c $< $(INCS) -Wall -Wextra -Ofast
	

clean:
	make clean -C libft
	rm -rf objs

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all
