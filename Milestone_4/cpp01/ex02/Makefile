NAME        = ex01

OBJ_DIR     = obj
BIN_DIR     = build

SRCS        = $(wildcard *.cpp)
OBJS        = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98

all: $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

re: fclean all

.PHONY: all clean fclean re
