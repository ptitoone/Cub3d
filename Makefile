NAME		=	a.out

NAMEL		=	linux_a.out

CC			=	gcc

LIBFT		=	libft.a

LIBMLX		=	libmlx.a

LIBMLXL		=	libmlx_linux.a

CFLAGS		=	-Wall -Werror -Wextra -L . -lft -lmlx -framework OpenGl -framework AppKit

CFLAGSL		=	-Wall -Werror -Wextra -L . -lft -lmlx_linux -lXext -lX11 -lm

SRCS		:=	$(shell echo srcs/*.c && echo srcs/parse/*.c && echo srcs/draw/*.c && echo srcs/controls/*.c && \
 						echo srcs/init/*.c && echo srcs/engine/*.c)

OBJS		=	$(SRCS:.c=.o)

LIBFTOBJS	:=	$(wildcard libft/*.o)

LIBMLx_offsetBJSL	:=	$(wildcard minilibx-linux/*.o)

INCLS		=	incls

.PHONY : all  alll clean fclean re rel debug

debug : $(NAMEL)
	$(CC) $(SRCS) -g -L . -lft -lmlx_linux -lXext -lX11 -lm -I$(INCLS)

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
	rm -rf $(OBJS) $(LIBFT) $(LIBFTOBJS) $(LIBMLXL) $(LIBMLx_offsetBJSL)

fclean : clean
	rm -rf $(NAME) $(NAMEL)

re : fclean all

rel : fclean alll

