GREEN := \033[32m
RED := \033[31m
END := \033[0m

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

CXXFLAGS = -std=c++98 -g -Wall -Wextra -Werror

NAME = zombie

all: $(NAME)

$(NAME): $(SRCS)
	@$(CXX) $(SRCS) -o $(NAME) $(CXXFLAGS)
	@echo "\n$(GREEN)> Compilation done!\n$(END)"

clean:
	@echo "\n$(RED)> Cleaned!\n$(END)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re