GREEN := \033[32m
RED := \033[31m
END := \033[0m

CXX = c++

SRCS = main.cpp Base.cpp BaseChecker.cpp

CXXFLAGS = -std=c++98 -g -Wall -Wextra -Werror

NAME = identify

all: $(NAME)

$(NAME): $(SRCS)
	$(CXX) $(SRCS) -o $(NAME) $(CXXFLAGS)

clean:
	$(RM) $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re