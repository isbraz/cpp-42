GREEN := \033[32m
RED := \033[31m
END := \033[0m

CXX = c++

SRCS = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

CXXFLAGS = -std=c++98 -g -Wall -Wextra -Werror

NAME = fight

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