CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = philo_bonus
RM = rm -rf

SRC_DIR = src/
OBJ_DIR = obj/

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

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR)

re: fclean all
