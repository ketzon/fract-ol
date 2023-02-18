NAME = fractol

NAME_BONUS = fractol_bonus

MLX = ./mlx_linux/libmlx.a

MLX_SUBDIR = ./mlx_linux

OBJ = $(SRC:.c=.o)

SRC =	tools/julia.c		\
		tools/utils.c	\
		tools/mouse.c			\
		tools/keyboard.c		\
		tools/parse.c			\
		tools/mandelbrot.c			\
		tools/ship.c			\
		tools/fractol.c			\
		tools/put.c \

BONUS =	







OBJ_BONUS = $(BONUS:.c=.o)

CC = clang

CFLAGS = -g -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c 

LDFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o 

all: $(MLX) $(NAME)

$(MLX):
	@$(MAKE) -C $(MLX_SUBDIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LDFLAGS) $(NAME)
	@echo "";
	@echo "███████╗██████╗░░█████╗░░█████╗░████████╗░█████╗░██╗░░░░░";
	@echo "██╔════╝██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗██║░░░░░";
	@echo "█████╗░░██████╔╝███████║██║░░╚═╝░░░██║░░░██║░░██║██║░░░░░";
	@echo "██╔══╝░░██╔══██╗██╔══██║██║░░██╗░░░██║░░░██║░░██║██║░░░░░";
	@echo "██║░░░░░██║░░██║██║░░██║╚█████╔╝░░░██║░░░╚█████╔╝███████╗";
	@echo "╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░╚════╝░╚══════╝";
	@echo "		      ____________";
	@echo "		     /\  ________ \ ";
	@echo "		    /  \ \______/\ \ ";
	@echo "		   / /\ \ \  / /\ \ \ ";
	@echo "		  / / /\ \ \/ / /\ \ \ ";
	@echo "		 / / /__\_\/ / /__\_\ \ ";
	@echo "		/ /_/_______/ /________\ ";
	@echo "		\ \ \______ \ \______  /";
	@echo "		 \ \ \  / /\ \ \  / / /";
	@echo "		  \ \ \/ / /\ \ \/ / /";
	@echo "		   \ \/ / /__\_\/ / /";
	@echo "		    \  / /______\/ /";
	@echo "		     \/___________/  ";
	@echo "";
	@echo "Usage : ./fractol		              by: fbesson";
	@echo "";

%.o: %.c
	@$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f ${OBJ} ${OBJ_BONUS}
	@$(MAKE) -C $(MLX_SUBDIR) clean

fclean: clean
	@rm -f ${NAME} ${NAME_BONUS}

re: fclean all

bonus: $(MLX) $(OBJ_BONUS)	
	@$(CC) $(OBJ_BONUS) $(LDFLAGS) $(NAME_BONUS)

.PHONY: all clean fclean re bonus 
