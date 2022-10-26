NAME =	testing
CC =	gcc
CFLAGS=	-g -Wall -Werror -Wextra
DEP =	libft.h libft.a

%.o: %.c
	$(CC) -c $(CFLAGS) $^

$(NAME): *.o $(DEP)
	$(CC) $(CFLAGS) -o $(NAME) $^

all: $(NAME)

.PHONY: clean fclean re all

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all