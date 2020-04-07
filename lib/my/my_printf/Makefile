##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib
##

SRC	=	my_printf.c				\
		my_printf_flag1.c		\
		my_printf_flag2.c		\
		my_printf_flag3.c

INC		=	-I ../../../include

CFLAGS	+=	-g $(INC)

OBJ		=	$(SRC:.c=.o)

NAME	=	../libprintf.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean :
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:	fclean all
