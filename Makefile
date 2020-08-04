##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## my_defender
##

CC = 		cc

SRC_DIR = 	src/

SRC	=		main.c										\
			tools/tools_clock.c							\
			tools/tools_sprite.c						\
			tools/tools_text.c							\
			tools/tools_vector.c						\
			tools/tools_fps.c							\
			tools/tools_screenshot.c					\
			tools/hitboxes.c							\
			tools/tools_style.c							\
			tools/tools_move.c							\
			tools/tools_transform.c						\
			tools/tools_hitbox.c						\
			tools/display_cursor.c						\
			tools/particle_engine/create_particle.c		\
			tools/particle_engine/manage_particle.c		\
			tools/particle_engine/modify_particle.c		\
			tools/particle_engine/particle_add.c		\
			tools/particle_engine/particle_set.c		\
			tools/particle_engine/select_list.c			\
			tools/particle_engine/delete_particle.c		\
			tools/particle_engine/delete_particle2.c	\
			tools/particle_engine/particle_other_set.c	\
			tools/tools_time.c							\
			create/window/create_window.c				\
			create/window/create_fps.c					\
			create/menu/create_intro.c					\
			create/menu/create_menu.c					\
			create/menu/create_background.c				\
			create/menu/create_button.c					\
			create/menu/create_opt_button.c				\
			create/menu/create_custom_buttons.c			\
			create/menu/create_opt_text.c				\
			create/game/create_game.c					\
			create/game/create_map.c					\
			create/game/create_player.c					\
			create/game/create_camera.c					\
			create/game/create_hud.c					\
			create/game/create_escape.c					\
			create/game/create_esc_button.c				\
			create/game/create_save_button.c			\
			create/game/create_inventory.c				\
			create/game/create_dialogue_box.c			\
			create/game/create_secondary.c				\
			create/game/create_particle.c				\
			create/game/create_other_particle.c			\
			create/game/create_fight.c					\
			create/game/create_text_fight.c				\
			create/game/create_shop.c					\
			create/game/create_pnj2.c					\
			create/game/create_pnj.c					\
			create/game/create_text_dialogue.c			\
			create/game/create_skill.c					\
			create/game/create_builder.c				\
			create/game/create_build_list.c				\
			create/game/create_build_button.c			\
			create/game/create_quest_menu.c				\
			create/custom/create_custom_bg.c			\
			create/custom/create_custom_buttons.c		\
			save/check_save.c							\
			save/get_save.c								\
			save/modify_save.c							\
			save/save.c									\
			save/add_var.c								\
			save/load_var_player.c						\
			save/load_var_game.c						\
			save/load_slot.c							\
			save/delete_save.c							\
			menu/intro/intro_loop.c						\
			menu/intro/intro_fade.c						\
			menu/menu.c									\
			menu/main/main_menu_event.c					\
			menu/main/main_menu_states.c				\
			menu/main/main_menu.c						\
			menu/options/options_menu.c					\
			menu/options/options_menu_event.c			\
			menu/save/save_menu_event.c					\
			menu/save/save_menu_loop.c					\
			game/game_init.c							\
			game/game_state.c							\
			game/game_loop.c							\
			game/game_event.c							\
			game/game_update.c							\
			game/game_display.c							\
			game/active_skill.c							\
			game/display_hud.c							\
			game/player_move.c							\
			game/camera_move.c							\
			game/escape/escape_loop.c					\
			game/escape/escape_event.c					\
			game/escape/escape_loop_save.c				\
			game/escape/escape_event_save.c				\
			game/escape/escape_buttons_states.c			\
			game/fight/fight_loop.c						\
			game/fight/display_fight.c					\
			game/fight/stats_in_fight.c					\
			game/fight/ennemies.c						\
			game/fight/fight_event.c					\
			game/fight/fight_begin.c					\
			game/sound/play_sound.c						\
			game/map/map_delete.c						\
			game/map/map_draw.c							\
			game/map/map_load.c							\
			game/map/map_read_pattern.c					\
			game/map/map_read_objects.c					\
			game/map/map_sort.c							\
			game/map/map_collision.c					\
			game/inventory/manage_skills.c				\
			game/inventory/inventory_loop.c				\
			game/inventory/inventory_event.c			\
			game/inventory/stats_changer.c				\
			game/inventory/event_skill.c				\
			game/shop/shop_loop.c						\
			game/shop/shop_event.c						\
			game/cheat/manage_cheat.c					\
			game/builder/builder_loop.c					\
			game/builder/builder_event.c				\
			game/builder/builder_catalog_evt.c			\
			game/builder/manage_build.c					\
			game/builder/builder_catalog.c				\
			game/builder/builder_posing.c				\
			inventory/inventory.c						\
			inventory/inventory_funcs.c					\
			custom/custom.c								\
			custom/create_custom_items.c				\
			custom/custom_events.c						\
			custom/mouse_events.c						\
			custom/custom_commands.c					\
			custom/custom_commands_mouse.c				\
			custom/display_custom_buttons.c				\
			quests/main/main_quest.c					\
			quests/main/dialogue.c						\
			quests/secondary/secondary_quest.c			\
			quests/secondary/cat_quest.c				\
			quests/secondary/bandit_quest.c				\
			quests/secondary/baby_quest.c				\
			quests/tp.c									\
			quests/other_tp.c							\
			quests/pnjs_dialogues.c						\

SRC := 		$(addprefix $(SRC_DIR), $(SRC))

OBJ	=		$(SRC:.c=.o)

CFLAGS	=  	-Wall -Wextra -I./include -g

LDFLAGS	=	-L./lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system -lm

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