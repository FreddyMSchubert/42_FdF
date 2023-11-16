NAME = fdf

SRC = $(shell find ./src -name "*.c")
OBJ = $(SRC:.c=.o)
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include -fsanitize=address -g
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -lm
CFLAGS	:= -Wall -Werror -Wextra -Wunreachable-code -Ofast

$(NAME): $(OBJ)
	@cc $(OBJ) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
	@cc $(CFLAGS) -Ofast -o $@ -c $< $(HEADERS)

all: libmlx $(NAME)
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -rf $(LIBMLX)/build
	@rm -f $(NAME)
re: fclean all
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
fcomp:
	@make fclean
	@make libmlx
	@make all
	@make clean
	@clear
comp:
	@make all
	@make clean
	@clear

.PHONY: all clean fclean re comp libmlx
