RED    = $(shell printf "\33[31m")
GREEN  = $(shell printf "\33[32m")
WHITE  = $(shell printf "\33[37m")
YELLOW = $(shell printf "\33[33m")
RESET  = $(shell printf "\33[0m")
BLUE = $(shell printf "\33[34m")
PURPLE = $(shell printf "\33[35m")
TITLE = $(shell printf "\33[32;40m")

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=thread -O1
NAME = philo
RM = rm -rf

SRC_DIR = src/
OBJ_DIR = obj/

SRC = src/main.c \
	  src/ft_utlis.c \
	  src/syntax_error.c \
	  src/parsing.c \
	  src/init_data.c \
	  src/manager_thread.c \
	  src/get_time.c \
	  src/philo_routine.c \
	  src/eating_process.c \
	 src/monitor_death.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
		@clear
		@echo "$(PURPLE)"
		@sleep 0.2
		@echo " ██▓███   ██░ ██  ██▓ ██▓     ▒█████    ██████  ▒█████   ██▓███   ██░ ██ ▓█████  ██▀███    ██████    "
		@sleep 0.2
		@echo "▓██░  ██▒▓██░ ██▒▓██▒▓██▒    ▒██▒  ██▒▒██    ▒ ▒██▒  ██▒▓██░  ██▒▓██░ ██▒▓█   ▀ ▓██ ▒ ██▒▒██    ▒    "
		@sleep 0.2
		@echo "▓██░ ██▓▒▒██▀▀██░▒██▒▒██░    ▒██░  ██▒░ ▓██▄   ▒██░  ██▒▓██░ ██▓▒▒██▀▀██░▒███   ▓██ ░▄█ ▒░ ▓██▄      "
		@sleep 0.2
		@echo "▒██▄█▓▒ ▒░▓█ ░██ ░██░▒██░    ▒██   ██░  ▒   ██▒▒██   ██░▒██▄█▓▒ ▒░▓█ ░██ ▒▓█  ▄ ▒██▀▀█▄    ▒   ██▒   "
		@sleep 0.2
		@echo "▒██▒ ░  ░░▓█▒░██▓░██░░██████▒░ ████▓▒░▒██████▒▒░ ████▓▒░▒██▒ ░  ░░▓█▒░██▓░▒████▒░██▓ ▒██▒▒██████▒▒   "
		@sleep 0.2
		@echo "▒▓▒░ ░  ░ ▒ ░░▒░▒░▓  ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ▒▓▒░ ░  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒▓ ░▒▓░▒ ▒▓▒ ▒ ░   "
		@sleep 0.2
		@echo "░▒ ░      ▒ ░▒░ ░ ▒ ░░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░  ░ ▒ ▒░ ░▒ ░      ▒ ░▒░ ░ ░ ░  ░  ░▒ ░ ▒░░ ░▒  ░ ░   "
		@sleep 0.2
		@echo "░░        ░  ░░ ░ ▒ ░  ░ ░   ░ ░ ░ ▒  ░  ░  ░  ░ ░ ░ ▒  ░░        ░  ░░ ░   ░     ░░   ░ ░  ░  ░     "
		@sleep 0.2
		@echo "          ░  ░  ░ ░      ░  ░    ░ ░        ░      ░ ░            ░  ░  ░   ░  ░   ░           ░     $(GREEN)"
		@sleep 0.2
		@echo
		@sleep 0.2
		@echo "                                      ℹ️ $(YELLOW) Dinner is ready! 🍽️.$(RESET)"
		@sleep 0.2
		@echo
		@sleep 0.2
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@$(RM) $(OBJ)
	@echo "$(RED)┏┓┓ ┏┓┏┓┳┓┏┓┳┓" 
	@echo "┃ ┃ ┣ ┣┫┃┃┣ ┃┃" 
	@echo "┗┛┗┛┗┛┛┗┛┗┗┛┻┛" 
	@echo

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJ_DIR)

re: fclean all
