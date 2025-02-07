NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
SRC =			ft_printf.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_itoa.c\
				ft_calloc.c\
				ft_redirect.c\
				ft_hexa.c\
				ft_putchar_fd.c

OBJECTS = $(SRC:.c=.o)

INCLUDE = ft_printf.h

EXEC_SRC = main.c
EXEC_OBJ = $(EXEC_SRC:.c=.o)
EXEC = programa

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJECTS)

$(EXEC): $(EXEC_OBJ) $(NAME)
	$(CC) $(EXEC_OBJ) -L. -lftprintf -o $(EXEC)

clean:
	rm -rf $(OBJECTS) $(BONUSOBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
