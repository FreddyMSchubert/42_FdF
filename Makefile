# Compiler to use
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files (including subfolders)
SRC = $(shell find . -name "*.c")

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
EXEC = etc/fdf

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

comp:
	make re
	make clean
	clear

.PHONY: all clean fclean re comp
