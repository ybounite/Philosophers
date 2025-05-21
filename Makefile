CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g #-fsanitize=address
NAME = philo
RM = rm -f

SRC = main.c\
	  ft_atoi.c\
	  syntax_error.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

run: $(NAME)
	./$(NAME) 

re: fclean all
