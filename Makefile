NAME = fractol
NAME_B = fractol_bonus

SRC = fractol_main.c fractols.c inisialiser.c parametre.c\
		put_error.c rgba.c key_hook.c key_mousse.c ft_free.c utils.c

SRC_B = fractol_main_bonus.c fractols_bonus.c inisialiser_bonus.c parametre_bonus.c burning_ship_bonus.c \
		put_error_bonus.c rgba_bonus.c key_hook_bonus.c key_mousse_bonus.c ft_free_bonus.c utils_bonus.c

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

OBJ_B = ${SRC_B:.c=.o}
all : ${NAME}

$(NAME): $(OBJ)
	$(CC) $(FLAGES) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(NAME_B)

$(NAME_B): $(OBJ_B)
	$(CC) $(FLAGES) $(OBJ_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
clean :
	${RM} ${OBJ} ${OBJ_B}
fclean : clean
	${RM} ${NAME} ${NAME_B}
re: fclean all