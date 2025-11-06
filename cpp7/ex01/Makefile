CFLAGS = -I./includes  -Wall -Werror -Wextra -std=c++98
CC = c++

HEADERS = includes/iter.hpp        \

SRCS = main.cpp                        \

OBJS = $(patsubst %.cpp,.objs/%.o,$(SRCS))

NAME = iter

all: $(NAME)

.objs/%.o:%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf .objs

fclean: clean
	rm -f $(NAME)

re: fclean all