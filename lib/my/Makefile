##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib
##

SRC	=	libbasic.a	\
		libprintf.a	\
		libcsfml.a

MAKE	= 	make -C

NAME	=	../libmy.a

all:		$(NAME)

$(NAME):
		$(MAKE) basic
		$(MAKE)	csfml_basic
		$(MAKE) my_printf
		ar rcT $(NAME) $(SRC)

clean :
		$(MAKE) basic clean
		$(MAKE)	csfml_basic clean
		$(MAKE) my_printf clean
		rm -f $(OBJ)

fclean: 	clean
		$(MAKE) basic fclean
		$(MAKE)	csfml_basic fclean
		$(MAKE) my_printf fclean
		rm -f $(NAME)

re:	fclean all
