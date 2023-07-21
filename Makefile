NAME = so_long

LIBFT = libft.a

SRCS = main.c

SRC_B =

RM = rm -f

INCS	= -I ./include/

CC = gcc

FLAGS = -g -Wall -Wextra -Werror  MLX42/build/libmlx42.a -Iinclude -lglfw -L"/Users/ohamadou/homebrew/opt/glfw/lib/" #-fsanitize=address -static-libsan

OBJS = $(SRCS:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

$(NAME):	$(OBJS)
		@make all -C libraries/libft
		@${CC} $(FLAGS) $(SRCS) libraries/LIBFT/$(LIBFT) -o so_long
# $(BONUS_NAME) : $(OBJ_B)
# 		@${CC} $(FLAGS) $(SRC_B) -o checker

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
		@$(RM) $(OBJS) $(OBJ_B)

fclean: clean
		$(RM) $(NAME) $(BONUS_NAME)

re: fclean all


.PHONY : all clean fclean re bonus
