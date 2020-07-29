/*
** EPITECH PROJECT, 2020
** game.h
** File description:
** game header
*/


#ifndef GAME_H_
#define GAME_H_

#include "basic.h"
#include "inventory.h"
#include "quests.h"
#include "particle_engine.h"
#include "custom.h"

// From save.h
struct file_save_s;

// From map.h
struct map_s;
struct props_s;

// From build_map.h
struct build_s;

typedef struct hud_s
{
    sfView *view;
} hud_t;

typedef enum game_state_n
{
    IN_ESCAPE,
    IN_GAME,
    IN_FIGHT,
    IN_INVENTORY,
    IN_SHOP,
    CUSTOM,
    BUILD
} game_state_e;

typedef enum direction_n
{
    NONE = 0,
    DOWN = 1,
    UP = 2,
    LEFT = 4,
    RIGHT = 8
} direction_e;

typedef enum turn_n
{
    ENNEMY_TURN,
    PLAYER_TURN
} turn_e;

typedef enum cursor_n
{
    ATTACK_LOW,
    ATTACK_HIGH,
    HEAL,
    ESCAPE,
    NO_ATTACK
} cursor_e;

typedef enum esc_n
{
    ESC,
    SAVE_CHOICE
} esc_e;

typedef struct player_s
{
    sprite_t *sprite;
    int direction : 5;
    int speed_move;
    int speed_anim;
    sfClock *ninja_clock;
    int ninja_activated;
    int ninja_cooldown;
    int torch_active;
    sfSound *war_cry;
    custom_t *custom;
    int is_sprint;
} player_t;

typedef struct old_map_s
{
    sprite_t *sprite;
} old_map_t;

typedef struct escape_s
{
    sprite_t *bg;
    button_t *b_opt;
    button_t *b_quit;
    button_t *b_continue;
    button_t *b_save;
    button_t *b_slot1;
    button_t *b_slot2;
    button_t *b_slot3;
    button_t *b_ret;
    esc_e state;
} escape_t;

typedef enum stats_state_e
{
    STATS,
    SKILL
} stats_state_e;

typedef enum skill_unlock_e
{
    ATTACK_BONUS = 1,
    SPEED_RUN = 2,
    MONEY_BONUS = 4,
    WAR_CRY = 8,
    NINJA = 16,
    HEALTH = 32
} skill_unlock_s;

typedef struct skill_s
{
    unsigned int skill_unlock : 6;
    sprite_t *ico_attack;
    sprite_t *ico_runner;
    sprite_t *ico_money;
    sprite_t *ico_cry;
    sprite_t *ico_ninja;
    sprite_t *ico_health;
    sprite_t *ico_perk;
    text_t *perk_text;
    sfVertexArray *line;
} skill_t;

typedef struct stats_s
{
    sprite_t *stats_bg;
    int health;
    int health_max;
    float health_bonus;
    int xp;
    int xp_max;
    int xp_bonus;
    int level;
    int perk_points;
    int attack;
    int attack_bonus;
    int speed_bonus;
    sprite_t *b_skill;
    skill_t *skill;
    text_t *health_txt;
    text_t *xp_txt;
    text_t *level_txt;
    text_t *text_change;
    sfMusic *xp_sound;
    sfMusic *level_sound;
    sfClock *clock;
    float elapsed_time;
    stats_state_e state;
} stats_t;

typedef struct ennemies_s
{
    int id;
    char *name;
    char *path;
    int health;
    int attack;
    sprite_t *sprite;
    struct ennemies_s *next;
} ennemies_t;

typedef struct shop_s
{
    sprite_t *shop_hud;
    text_t *shop_name;
    text_t *object_description;
    text_t *money;
    sprite_t *coin_sprite;
    sprite_t *katana_sprite;
    sprite_t *potion_sprite;
    sfMusic *money_sound;
} shop_t;

typedef struct fight_s
{
    sfMusic *battle_music;
    sprite_t *bg;
    sprite_t *fight_hud;
    sprite_t *player;
    sprite_t *attack_anim;
    int id;
    int nb_ennemies;
    int cursor;
    int turn;
    int ennemy_health_int;
    int ennemy_health_max;
    int ennemy_attack;
    int bonus_gold;
    int init_fight;
    int pass_text;
    int ennemy_played;
    int end_message;
    int is_attack_left;
    int is_attack_right;
    int game_launched;
    int try_escape;
    int success_escape;
    text_t *attack_low;
    text_t *attack_high;
    text_t *heal;
    text_t *escape;
    text_t *ennemy_health;
    text_t *player_health;
    text_t *ennemy_name;
    text_t *musachi_name;
    text_t *infos;
    text_t *other_stats;
    sfClock *clock_infos;
    float elapsed_time;
    ennemies_t *ennemies;
} fight_t;

typedef struct quest_menu_s
{
    sprite_t *bg;
    text_t *main_quest;
    text_t *secondary_quest1;
    text_t *secondary_quest2;
    text_t *secondary_quest3;
    int activated;
} quest_menu_t;

typedef struct game_s
{
    sfClock *clock_loop;
    float time_elapsed;
    sfBool end;
    game_state_e state;
    camera_t *camera;
    hud_t *hud;
    escape_t *esc_menu;
    struct map_s *map;
    player_t *player;
    sfMusic *bg_music;
    sfMusic *bg_pause;
    items_list_t *items_list;
    sprite_t *inventory;
    text_t *item_name;
    dialogue_t *dialogue;
    stats_t *stats;
    sprite_t *stats_bg;
    fight_t *fight;
    shop_t *shop;
    particle_engine_t *rain;
    particle_engine_t *snow;
    particle_engine_t *run_particle;
    particle_engine_t *sakura;
    particle_engine_t *fire;
    struct file_save_s *saves;
    letter_t *letter;
    pnj_t *pnj;
    int hitbox_activated;
    int cheat_mode;
    particle_engine_t *god;
    particle_engine_t *test_particle;
    struct build_s *build;
    quest_menu_t *quest_menu;
} game_t;

// INIT GAME //

game_t *create_game(window_t *win);

camera_t *create_game_camera(window_t *win);

hud_t *create_game_hud(window_t *win);

player_t *create_game_player(window_t *win);

dialogue_t *create_dialogue_box(window_t *win);

letter_t *create_letter(void);

int create_text(dialogue_t *dialogue, window_t *win);

pnj_t *create_pnj(void);

sprite_t *create_samurai_sprite(void);

sprite_t *create_cat_sprite(void);

sprite_t *create_bandit_sprite(void);

sprite_t *create_baby_sprite(void);

escape_t *create_game_escape_menu(window_t *win);
button_t *create_esc_opt(window_t *win);
button_t *create_esc_quit(window_t *win);
button_t *create_esc_continue(window_t *win);
button_t *create_esc_save(window_t *win);
button_t *create_b_slot1(window_t *win);
button_t *create_b_slot2(window_t *win);
button_t *create_b_slot3(window_t *win);
button_t *create_b_ret(window_t *win);

sprite_t *create_inventory(window_t *win);

sprite_t *create_stats_bg(window_t *win);

text_t *create_text_struct(window_t *win);
text_t *create_text_struct_fight(window_t *win);
void create_text_fight(window_t *win, fight_t *fight);
void create_text_fight_stats(window_t *win, fight_t *fight);
fight_t *create_fight(window_t *win);

sprite_t *create_battlg_bg(void);
sprite_t *create_battle_player(void);
sprite_t *create_battle_hud(void);
sprite_t *create_attack_anim(void);

shop_t *create_shop(window_t *win);

ennemies_t *make_ennemies_list(void);

particle_engine_t *create_rain(window_t *win);
particle_engine_t *create_snow(void);
particle_engine_t *create_god(void);
particle_engine_t *create_run_particle(void);
particle_engine_t *create_sakura(void);
particle_engine_t *create_fire_particle(void);

custom_t *init_custom_struct(float scale, window_t *win);

text_t *create_text_struct_dialogue(window_t *win);

skill_t *create_struct_skill(void);

quest_menu_t *create_quest_menu(window_t *win);

//STATES//

int game_loop(window_t *win, game_t *game);

int option_loop(window_t *win, game_t *game);

int fight_loop(window_t *win, game_t *game);

int escape_loop(window_t *win, game_t *game);

int inventory_loop(window_t *win, game_t *game);

int shop_loop(window_t *win, game_t *game);

int builder_loop(window_t *win, game_t *game);

//STATES//


// ****** ESCAPE MENU ****** //

int escape_loop_menu(window_t *win, game_t *game);
int escape_event(window_t *win, game_t *game, escape_t *esc);

int escape_loop_save(window_t *win, game_t *game);
int escape_event_save(window_t *win, game_t *game, escape_t *esc);
void check_escape_mouse_position(window_t *win, escape_t *escape);

// GAME //

int launch_game(window_t *win, int slot);

int game_state(window_t *win, game_t *game);

int pause_event(window_t *win, game_t *game);

int game_event(window_t *win, game_t *game);

void display_game(window_t *win, game_t *game);

void display_hud(window_t *win, game_t *game);

void update_game(window_t *win, game_t *game);

int check_player_move(player_t *player, sfVector2f map_size,
                            struct props_s *props, float elapsed_time);

void update_camera(camera_t *camera, player_t *player, sfVector2f map);

int inventory_event(window_t *win, game_t *game);

int fight_event(window_t *win, game_t *game);

int shop_event(window_t *win, game_t *game);

void main_quest(window_t *win, game_t *game);

void secondary_quests(window_t *win, game_t *game);

void cat_quest(window_t *win, game_t *game);

void take_cat(window_t *win, game_t *game);

void bandit_quest(window_t *win, game_t *game);

void attack_bandit(window_t *win, game_t *game);

void baby_quest(window_t *win, game_t *game);

void take_baby(window_t *win, game_t *game);

void tp(game_t *game);

void tp_house(game_t *game);

void temple_1(game_t *game);

void temple_2(game_t *game);

void palace(game_t *game);

void display_dialogue(window_t *win, game_t *game);

void check_dialogues(window_t *win, game_t *game);

int is_collide(sprite_t *player, struct props_s *props, sfVector2f offset);

int is_click(struct props_s *props, sfVector2f mouse, char *name);

sprite_t *create_noble_sprite(void);

// STATS //

//add xp to the player stat and increase his level if needed
void add_xp(stats_t *stats, int earned_xp);

//update his life (remove or add life)
void update_life(stats_t *stats, int life);

void stat_message_handler(window_t *win, stats_t *stats, player_t *player);

// FIGHT //

void init_fight(game_t *game);

void show_cursor(game_t *game);

void display_ennemies(window_t *win, game_t *game);

void display_fight(window_t *win, game_t *game);

void display_stats_in_fight(window_t *win, game_t *game);

void update_fight_time_message(game_t *game);

void check_fight(game_t *game);

void launch_fight(game_t *game, int id);

// CUSTOM //

void init_custom_basics(custom_t *custom);

c_button_t *create_all_custom_buttons(window_t *win);

int custom_loop(window_t *win, game_t *game);

void update_custom_hair_and_face(player_t *player, int hair, int face);

void update_custom_shirt_and_pants(player_t *player, int shirt, int pants);

void update_custom_shoes(player_t *player, int shoes);

void display_player(window_t *win, player_t *player, game_t *game);

int custom_event(window_t *win, game_t *game);

int custom_command_hair(game_t *game, sfEvent event);

int custom_command_face(game_t *game, sfEvent event);

int custom_command_shirt(game_t *game, sfEvent event);

int custom_command_pants(game_t *game, sfEvent event);

int custom_command_shoes(game_t *game, sfEvent event);

int custom_command_mouse_hair(custom_t *custom, int check);

int custom_command_mouse_face(custom_t *custom, int check);

int custom_command_mouse_shirt(custom_t *custom, int check);

int custom_command_mouse_pants(custom_t *custom, int check);

int custom_command_mouse_shoes(custom_t *custom, int check);

void display_custom_buttons(window_t *win, custom_t *custom);

int update_buttons(custom_t *custom, int which_part);

int update_buttons(custom_t *custom, int which_part);

int check_custom_mouse_position_1(window_t *win, custom_t *custom);

void mouse_events(custom_t *custom, window_t *win);

// SKILL //

void display_skill(sfRenderWindow *window, skill_t *skill);

sprite_t *create_button_skill(void);

void apply_skill(skill_t *skill, stats_t *stats, fight_t *fight);

void click_skill(sfVector2i mouse, game_t *game, skill_t *skill);

void display_torch(window_t *win, game_t *game);

void apply_skill(skill_t *skill, stats_t *stats, fight_t *fight);

void ninja_skill(player_t *player, fight_t *fight);

void passed_mouse_skill(window_t *win, game_t *game, skill_t *skill);

// CHEAT //

void manage_cheat(window_t *win, game_t *game);

#endif /* !GAME_H_ */