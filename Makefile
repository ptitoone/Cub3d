NAME		=	a.out

CC			=	gcc

LIBFT		=	libft.a

CFLAGS		=	-Wall -Werror -Wextra -L . -lft -lmlx -framework OpenGl -framework AppKit

SRCS		:=	$(shell echo srcs/*.c)

LIBFTOBJS 	:=	$(wildcard libft/*.o)

OBJS		=	$(SRCS:.c=.o)

INCLS		=	incls

.PHONY : all clean fclean

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) -I$(INCLS) -o $(NAME)

$(LIBFT) :
	@cd libft \
	&& make \
	&& mv libft.a ../ \
	&& cp libft.h ../incls \
	&& cd ..

%.o : %.c
	$(CC) -I$(INCLS) -c $< -o $@

clean :
	rm -rf $(OBJS) $(LIBFT) $(LIBFTOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

