OC = $(addprefix c/ft_,$(addsuffix .o,\
	atoi atoip itoa itoabase utoabase\
	freeret freeswap ptrswap free\
	gnl rfc gdc\
	isdir\
	putchar putnchar putnbr\
	strrchr strstr strncmp stricmp strndup strjoin strcjoin strsjoin strsplit\
	strrem strfrmchr strcount\
	strnew strpush strspush strins strsins strrem\
	strarrdup strarrstr strarrstrn strarrrem strarrstrlen strarrstrstrr\
	parrnew parrfree parrelmfree parrpush parrprem parrrem parrlen parrdup parrndup parrjoin\
	intlen\
	print\
	printf con format cast utl wchar wutl color \
	))

OA = $(addprefix asm/ft_,$(addsuffix .o,\
	bzero m memalloc memset memcpy memcmp \
	strcat strlen strdup strcpy strcmp strchr puts\
	abs\
	cat\
	))

NAME=libft.a

all: $(NAME)

$(NAME): $(OC) $(OA)
	ar rcs $(NAME) $(OC) $(OA)

c/%.o: c/%.c
	gcc -c $< -o $@ -Wall -Wextra -Werror -O3 -I.

asm/%.o: asm/%.s
	nasm $< -o $@ -f macho64 -I.

clean:
	rm -f $(OC)
	rm -f $(OA)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
