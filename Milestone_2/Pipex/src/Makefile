NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = pipex.c \
		pipex_utils.c \

OBJECTS = $(SRCS:.c=.o)
INCLUDE = pipex.h
EXEC_SRC = main.c
EXEC_OBJ = $(EXEC_SRC:.c=.o)
EXEC = programa
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(INCLUDE) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJECTS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)j
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re