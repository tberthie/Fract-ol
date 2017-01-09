SRCS = main.c \
	   setup.c

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra
INCS = includes -I libft

all: $(NAME)

$(NAME): $(OBJS)
	@echo "[compiling libft]"
	@make -C libft
	@make -C minilibx
	@gcc $(FLAGS) -o $(NAME) libft/libft.a minilibx/libmlx.a $(OBJS) \
	-framework OpenGL -framework AppKit
	@echo "[$(NAME)]"

srcs/%.o: srcs/%.c
	@$(CC) $(FLAGS) -I $(INCS) -I libft/includes -I minilibx -o $@ -c $<
	@echo "[$@]"

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@echo "[objs removed]"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "[workspace clean]"

re: fclean all
