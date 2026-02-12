# ======= Colors =======

GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RED = \033[31m
RESET = \033[0m

# ======= Config =======

NAME = minishell
CFLAGS = -O3 -Wall -Wextra -Werror
LDLIBS = -lreadline
CC = cc
INC = -I include/.

# ======= Vars =======

obj_dir = build/
src = $(shell find src -name "*.c")
obj = $(patsubst src/%.c, $(obj_dir)%.o, $(src))

# ======= Rules =======

all: $(NAME)

$(NAME): $(obj)
	@echo "$(YELLOW)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)
	@echo "$(GREEN)"
	@echo "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗        "
	@echo "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║        "
	@echo "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║        "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║        "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗   "
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝   "
	@echo "By Itxine & Andrea"
	@echo "$(RESET)"

$(obj_dir)%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo "$(RED)Cleaning objects...$(RESET)"
	@rm -rf $(obj_dir)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

fsa: CFLAGS += -fsanitize=address
fsa: re

test: $(NAME)
	@echo "$(BLUE)Running tests...$(RESET)"
	@bash tests/run_tests.sh

leak_test: $(NAME)
	@echo "$(BLUE)Running leak tests...$(RESET)"
	@bash tests/leak_test.sh

.PHONY: all clean fclean re fsa test leak_test
