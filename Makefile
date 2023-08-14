NAME = so_long

LIBFT = libraries/Libft/libft.a

LIBFT_PATH = "libraries/Libft/"

SRCS = main.c src/exit_game.c src/keypress.c \
			src/output_elmts.c src/play_game.c src/read_map.c \
			src/check_ber.c src/hook.c src/utils.c\
			src/check_map.c \

SRC_B =

RM = rm -f

INCS	= -I ./include/

CC = gcc

FLAGS = -g -Wall -Wextra -Werror  MLX/build/libmlx42.a -Iinclude -lglfw -L"/Users/ohamadou/homebrew/opt/glfw/lib/" -fsanitize=address -static-libsan

OBJS = $(SRCS:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

$(NAME):	$(OBJS)
		@make -C $(LIBFT_PATH)
		@${CC} $(FLAGS) $(SRCS) $(LIBFT) -o ${NAME}
# $(BONUS_NAME) : $(OBJ_B)
# 		@${CC} $(FLAGS) $(SRC_B) -o checker

all: $(NAME)

bonus: $(NAME)

clean:
		@$(RM) $(OBJS) $(OBJ_B)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)

re: fclean all


.PHONY : all clean fclean re bonus


# NAME	:= so_long
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
# LIBMLX	:= ./MLX42

# HEADERS	:= -I ./include -I $(LIBMLX)/include
# LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
# SRCS	:= main.c src/exit_game.c src/initiation.c src/keypress.c \
# 			src/output_elmts.c src/playgame.c src/read_map.c \
# OBJS	:= ${SRCS:.c=.o}

# all: libmlx $(NAME)

# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

# $(NAME): $(OBJS)
# 	@make all -C libraries/libft
# 	@$(CC) $(OBJS) $(LIBS) $(HEADERS) libraries/LIBFT/$(LIBFT) -o $(NAME)

# clean:
# 	@rm -rf $(OBJS)
# 	@rm -rf $(LIBMLX)/build

# fclean: clean
# 	@rm -rf $(NAME)

# re: clean all

# .PHONY: all, clean, fclean, re, libmlx