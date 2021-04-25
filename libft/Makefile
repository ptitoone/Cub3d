NAME	= 	libft.a

SRCS	:=	$(shell echo srcs/*.c && echo srcs/get_next_line/*.c)

OBJS	=	$(SRCS:.c=.o)

INCLS   =   incls

CFLAGS	=	-Wall -Wextra -Werror

CC      =   gcc

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@ -I$(INCLS)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
