CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g -fsanitize=thread -O1
NAME = philo
RM = rm -f

SRC = main.c \
	  ft_utlis.c \
	  syntax_error.c \
	  parsing.c \
	  init_data.c \
	  get_time.c \
	  philo_routine.c \
	  monitor_death.c

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
