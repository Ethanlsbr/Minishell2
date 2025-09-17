##
## EPITECH PROJECT, 2024
## Delivery
## File description:
## Makefile
##

NAME  =  mysh

CC    =  gcc

LIB	= ./lib/my/

CFLAGS  += -W -Wall -Wextra -g3
CFLAGS  += -I./include/
CFLAGS  += -lmy

SRCS  =  $(wildcard \
    ./src/*.c \
	./src/change_directory/*.c	\
	./src/env/*.c	\
	./src/parsing/*.c	\
)

OBJS = $(SRCS:.c=.o)

RESET = \033[0m
GREEN = \033[1;32m

c = 1
total = $(words $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB) -s
	@$(CC) $^ -o $@ -L $(LIB) $(CFLAGS) $(CSFML)
	@echo "Built target $@"
	@echo -e "$(GREEN)✔ Compilation completed successfully!$(RESET)"

%.o: %.c
	@echo -e "\033[m[$(c)/$(total)]\033[0m \033[32mBuilding C object $@\033[0m"
	@$(CC) -c $< -o $@ $(CFLAGS) $(CSFML)
	$(eval c=$(shell echo $$(($(c)+1))))

clean:
	@make clean -C $(LIB) -s
	@echo "Cleaning up..."
	@rm -f $(OBJS)

fclean: clean
	@make  fclean -C $(LIB) -s
	@echo "Full cleaning..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
