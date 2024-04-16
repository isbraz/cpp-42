GREEN := \033[32m
RED := \033[31m
END := \033[0m

CXX = c++

SRCS = Phonebook.cpp Contact.cpp main.cpp

CXXFLAGS = -std=c++98 -g -Wall -Wextra -Werror

NAME = phonebook

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