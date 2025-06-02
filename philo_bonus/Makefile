CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
RM = rm -f

SRC =  src/philo_bonus.c \
	  src/allocate_data.c\
	  src/ft_utlis.c \
	  src/syntax_error.c \
	  src/parsing.c \
	  src/init_data.c \
	  src/start_simulation.c \
	  src/get_time.c \
	  src/philo_routine.c \
	  src/eating_process.c \
	  src/monitor_death.c\
	  src/destroy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
