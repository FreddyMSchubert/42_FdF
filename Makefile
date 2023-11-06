NAME = fdf

SRC = $(shell find ./src -name "*.c")
OBJ = $(SRC:.c=.o)
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
CFLAGS	:= -Wunreachable-code -Ofast

$(NAME): $(OBJ)
	@cc $(OBJ) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c
	@cc $(CFLAGS) -Ofast -o $@ -c $< $(HEADERS)

all: libmlx $(NAME)
clean:
	@rm -f $(OBJ)
	@rm -rf $(LIBMLX)/build
fclean: clean
	@rm -f $(NAME)
re: fclean all
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
comp:
	@make fclean
	@make all
	@make clean
	./fdf

.PHONY: all clean fclean re comp libmlx
