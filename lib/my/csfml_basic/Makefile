##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for lib
##

SRC		=	cs_checkalloc.c		\
			cs_spritearea.c		\
			cs_freemem.c		\
			cs_text.c			\
			cs_spritearea.c		\
			cs_createwindow.c 	\
			cs_createsprite.c  	\
			cs_clock.c			\
			cs_vertex.c			\
			cs_mouse.c			\
			cs_position.c

INC		=	-I ../../../include

OBJ		=	$(SRC:.c=.o)

NAME	=	../libcsfml.a

CFLAGS	+=	-g $(INC)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean :
		rm -f $(OBJ)

fclean: 	clean
		rm -f $(NAME)

re:	fclean all
