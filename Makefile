##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_defender
##

CC = 		cc

SRC_DIR = 	src/

SRC	=		main.c								\
			tools/tools_clock.c					\
			tools/tools_sprite.c				\
			tools/tools_text.c					\
			tools/tools_vector.c				\
			tools/tools_fps.c					\
			create/window/create_window.c		\
			create/window/create_fps.c			\
			create/menu/create_intro.c			\
			create/menu/create_menu.c			\
			create/menu/create_background.c		\
			create/menu/create_button.c			\
			create/menu/create_opt_button.c		\
			create/game/create_game.c			\
			create/game/create_map.c			\
			create/game/create_player.c			\
			create/game/create_camera.c			\
			create/game/create_hud.c			\
			menu/intro/intro_loop.c				\
			menu/intro/intro_fade.c				\
			menu/menu.c							\
			menu/main/main_menu_event.c			\
			menu/main/main_menu.c				\
			menu/options/options_menu.c			\
			menu/options/options_menu_event.c	\
			game/game_init.c					\
			game/game_state.c					\
			game/game_loop.c					\
			game/game_event.c					\
			game/game_update.c					\
			game/game_display.c					\
			game/display_hud.c					\
			game/player_move.c					\
			game/camera_move.c					\
			game/pause/pause_loop.c				\
			game/pause/pause_event.c			\
			game/help/help.c					\
			game/options/option.c				\
			game/fight/fight.c					\

SRC := 		$(addprefix $(SRC_DIR), $(SRC))

OBJ	=		$(SRC:.c=.o)

CFLAGS	=  	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system

NAME	=	my_rpg

LIB	=		./lib/libmy.a

all:		$(NAME)

$(LIB):
			$(MAKE) -C ./lib/my

$(NAME):	$(LIB) $(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

debug:		fclean $(LIB)
			$(CC) $(SRC) -o $(NAME) $(CFLAGS) -g $(LDFLAGS)

clean:
			rm -f $(OBJ)
			$(MAKE) clean -C ./lib/my/

fclean:		clean
			rm -f $(NAME)
			$(MAKE) fclean -C ./lib/my/

re:			fclean all

.PHONY:		all debug clean fclean re $(NAME)