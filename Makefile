NAME		=	cub3D
NAMEL		=	linux_cub3D
CC			=	gcc
LIBFT		=	libft.a
LIBMLX		=	libmlx.dylib
LIBMLXL		=	libmlx_linux.a
CFLAGS		=	-Wall -Werror -Wextra -L . -lft -lmlx -framework OpenGl -framework AppKit
CFLAGSL		=	-Wall -Werror -Wextra -L . -lft -lmlx_linux -lXext -lX11 -lm
SRCS		:=	$(shell echo srcs/*.c 		\
				&& echo srcs/parse/*.c 		\
				&& echo srcs/draw/*.c 		\
				&& echo srcs/controls/*.c 	\
				&& echo srcs/init/*.c 		\
				&& echo srcs/engine/*.c 	\
				&& echo srcs/errors/*.c 	\
				&& echo srcs/utils/*.c)
OBJS		=	$(SRCS:.c=.o)
LIBFTOBJS	:=	$(shell echo libft/srcs/*.o \
					&& echo libft/srcs/get_next_line/*.o)
LIBMLXOBJS	:=	$(wildcard minilibx/*.o)
LIBMLXOBJSL	:=	$(wildcard minilibx-linux/*.o)
INCLS		=	-Iincls

.PHONY : all  alll clean fclean re rel debug

all : $(NAME)

alll : $(NAMEL)

debug : $(NAME)
	$(CC) $(SRCS) -g $(CFLAGS) $(INCLS) -o $(NAME)

$(NAME) : $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLS) -o $(NAME)

$(NAMEL) : $(LIBFT) $(LIBMLXL) $(OBJS)
	$(CC) $(OBJS) $(CFLAGSL) $(INCLS) -o $(NAME)

$(LIBFT) :
	@make -C libft \
	&& mv libft/libft.a . \
	&& cp libft/incls/libft.h libft/incls/get_next_line.h ./incls \

$(LIBMLX) :
	@make -C minilibx \
	&& mv minilibx/libmlx.dylib ./ \
	&& cp minilibx/mlx.h ./incls

$(LIBMLXL) :
	@make -C minilibx-linux \
	&& mv minilibx-linux/libmlx.a ./$(LIBMLXL) \
	&& cp minilibx-linux/mlx.h ./incls

%.o : %.c
	$(CC) $(INCLS) -c $< -o $@

clean :
	@rm -rf $(OBJS) $(LIBFT) $(LIBFTOBJS) $(LIBMLX) $(LIBMLXOBJS) $(LIBMLXL) $(LIBMLXOBJSL) incls/libft.h \
	incls/get_next_line.h incls/mlx.h \
	&& echo "- Object and library files removed."

fclean : clean
	@rm -rf $(NAME) $(NAMEL) \
	&& echo "- Binary files removed."

re : fclean all

rel : fclean alll
