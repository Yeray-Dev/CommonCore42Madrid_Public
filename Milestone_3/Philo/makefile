NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(PWD)/include -pthread -v

SRC_DIR	= src
SRC = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(NAME)


$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)



clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
