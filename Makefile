NAME = libft-test
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = libft-test.c \

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) ../libft.a

bonus:
	$(CC) $(FLAGS) libft-test-bonus.c ../libft.a

fclean:
	rm -f $(NAME)

re: fclean all
