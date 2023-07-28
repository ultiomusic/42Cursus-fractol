NAME	= fractol

# directories
SRCDIR	= ./src/
INCDIR	= ./inc/
OBJDIR	= ./obj/
BUILDDIR = ./build/

RM = rm -rf
# src / obj files
SRC		= main.c\
		ft_utils.c\
		ft_utils_2.c\
		mlx_utils.c\
		hooks.c\
		$(addprefix fractals/,$(shell ls $(SRCDIR)/fractals | grep -E ".+\.c"))

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror


# mlx library
MLX		= ./mlx/
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),libmlx.a)


all: obj $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/fractals
	mkdir -p $(BUILDDIR)

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(INCDIR) -o $@ -c $<

$(MLX_LIB):
	@make -C $(MLX) 2>/dev/null

#compiling the main
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) -lm -o $(BUILDDIR)$(NAME)

clean:
	$(RM) $(OBJDIR)
	$(RM) $(BUILDDIR)
	$(RM) $(NAME)

fclean: clean
	make -C $(MLX) 2>/dev/null clean

re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re