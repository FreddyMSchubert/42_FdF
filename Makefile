NAME = fdf

SRC = $(shell find ./src -name "*.c")
OBJ = $(SRC:.c=.o)
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -lm
CFLAGS := -Wall -Werror -Wextra -Wunreachable-code -Ofast -g #-fsanitize=address

$(NAME): $(OBJ)
	cc $(OBJ) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $< $(HEADERS)

all: libmlx $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -rf $(LIBMLX)/build
	rm -f $(NAME)
re: fclean all

$(LIBMLX)/build/libmlx42.a:
	cmake $(LIBMLX) -B $(LIBMLX)/build
	make -C $(LIBMLX)/build -j4
libmlx: $(LIBMLX)/build/libmlx42.a

fcomp:
	make fclean
	make libmlx
	make all
	make clean
	clear
comp:
	make all
	make clean
	clear

.PHONY: all clean fclean re comp libmlx
