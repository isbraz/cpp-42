GREEN := \033[32m
RED := \033[31m
END := \033[0m

CXX = c++

SRCS = main.cpp Bureaucrat.cpp Form.cpp

CXXFLAGS = -std=c++98 -g -Wall -Wextra -Werror

NAME = Bureaucrat

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(SRCS) -o $(NAME) $(CXXFLAGS)

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re