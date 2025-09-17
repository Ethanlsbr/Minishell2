##
## EPITECH PROJECT, 2023
## Delivery
## File description:
## Makefile
##

NAME = libmy.a

SRC =	$(wildcard	\
	./*.c	\
)

RM = rm -f

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

all:     $(NAME)


clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re:     fclean all

.PHONY: all clean fclean re
