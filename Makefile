NAME = ircserv

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc

SRCS = src/main.cpp \
		src/error.cpp \
		src/Server.cpp

OBJS = $(SRCS:.cpp=.o)

# default args for the `run` target
PORT = 6667
PASS = password

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME) $(PORT) $(PASS)

re: fclean all

.PHONY: all clean fclean run re
