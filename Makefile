NAME		=	a.out

NAMEL		=	linux_a.out

CC			=	gcc

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

LIBMLXL		=	libmlx_linux.a

CFLAGS		=	-g -Wall -Werror -Wextra -L . -lft -lmlx -framework OpenGl -framework AppKit

CFLAGSL		=	-g -Wall -Werror -Wextra -L . -lft -lmlx_linux -lXext -lX11 -lm

SRCS		:=	$(shell echo srcs/*.c)

OBJS		=	$(SRCS:.c=.o)

LIBFTOBJS	:=	$(wildcard libft/*.o)

LIBMLXOBJSL	:=	$(wildcard minilibx-linux/*.o)

INCLS		=	incls

.PHONY : all clean fclean re rel

all : $(NAME)

alll : $(NAMEL)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) -I$(INCLS) -o $(NAME)

$(NAMEL) : $(OBJS) $(LIBFT) $(LIBMLXL)
	$(CC) $(OBJS) $(CFLAGSL) -I$(INCLS) -o $(NAME)

$(LIBFT) :
	@make -C libft \
	&& mv libft/libft.a . \
	&& cp libft/libft.h ./incls \

$(LIBMLXL) :
	@make -C minilibx-linux \
	&& mv minilibx-linux/libmlx.a ./$(LIBMLXL) \
	&& cp minilibx-linux/mlx.h ../incls 

%.o : %.c
	$(CC) -I$(INCLS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(LIBFT) $(LIBFTOBJS) $(LIBMLXL) $(LIBMLXOBJSL)

fclean : clean
	rm -rf $(NAME) $(NAMEL)

re : fclean all

rel : fclean alll

