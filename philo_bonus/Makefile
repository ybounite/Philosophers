CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-lpthread -lrt
NAME = philo_bonus
RM = rm -f

SRC =  philo_bonus.c \
	   allocate_data.c\
	  ft_utlis.c \
	  syntax_error.c \
	  parsing.c \
	  init_data.c \
	  get_time.c \
	#   init_data.c \
	#   manager_thread.c \
	#   philo_routine.c \
	#   eating_process.c \
	#   monitor_death.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
