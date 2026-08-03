NAME = megaphone
CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98


SRC = $(shell find . -name '*.cpp')
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(NAME)
fclean: clean
	rm -f $(NAME)
re: fclean all