# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                  VARIABLES                                    #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

NAME		= fdf # Define el nombre del programa.

# Compiler
CC			= clang # Define el compilador
CFLAGS		= -Wall -Wextra -Werror -IInclude -Iminilibx-linux -ILibft # Define las Flags. Las 3 W para errores y warnigns. y las flags -I que son para incluir los headers (.h) => Nos dice que debe buscarlos en esas carpetas

# Libft
LIBFT_DIR	=	Libft # Carpeta donde esta la Libft
LIBFT		=	$(LIBFT_DIR)/libft.a # Ruta del archivo .a
MLX_DIR		= 	minilibx-linux # Carpeta donde esta la MiniLibX
MLX_LIB		=	$(MLX_DIR)/libmlx.a # Ruta del archivo .a
MLX_INC		=	-I$(MLX_DIR) # Ruta donde buscar los .h

# Sources
SRC_DIR		= src # Definimos donde estan los .c=
SRCS		= $(shell find $(SRC_DIR) -name '*.c') # Usamos Shell para que busque en ese directorio y subdirectorios todos los archivos .c y los agrege
OBJS		= $(SRCS:.c=.o) # Crea una lista de archivos .o apartir de los .c
TOTAL		:= $(words $(SRCS))

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                  RULES                                        #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: $(LIBFT) $(MLX_LIB) $(NAME)  # Objeto por defecto que necesita que Libft este compilado y con el .a

$(LIBFT): # Compila la libreria Libft
	@make -C $(LIBFT_DIR) -s

$(MLX_LIB): # Compila la Minilibx
	@make -C $(MLX_DIR) -s

$(NAME): $(OBJS)
	@echo -e "\n🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -o $(NAME)
	@echo "✅ Build complete"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@COMPILED=$$(find . -name '*.o' | wc -l); \
	BAR_WIDTH=30; \
	FILLED=$$((COMPILED * BAR_WIDTH / $(TOTAL))); \
	BAR=$$(printf "%0.s#" $$(seq 1 $$FILLED)); \
	SPACE=$$(printf "%0.s " $$(seq 1 $$((BAR_WIDTH - FILLED)))); \
	printf "\r[%s%s]" "$$BAR" "$$SPACE"


clean: # Limpia los arhivos .o locales
	@make -C $(LIBFT_DIR) clean -s
	@$(RM) $(OBJS)
	clear
	@printf "Cleaned!\n"

fclean: clean # Limpia todos los archivos .o de todas las subrutas
	@make -C $(LIBFT_DIR) fclean -s
	@$(RM) $(NAME)

re: fclean all # Recompila desde 0, primero hace Fclean y luego compila

.PHONY: all clean fclean re #Esto evita confundir los targets con archivos llamados igual, forzando siempre a ejecutar las reglas aunque existan archivos con esos nombres.


