NAME = libft-test
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = libft-test.c \

INCLUDES = -lbsd

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC) ../libft.a $(INCLUDES) 

bonus:
	$(CC) $(FLAGS) libft-test-bonus.c ../libft.a $(INCLUDES)

fclean:
	rm -f $(NAME)

re: fclean all
