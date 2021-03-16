NAME	=	a.out

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -lft -lmlx -framework OpenGl -framework AppKit

SRCS	=	*.c

OBJS	=	$(SRCS:.c=.o)

INCLS	=	.incls/

.PHONY : all clean fclean

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

