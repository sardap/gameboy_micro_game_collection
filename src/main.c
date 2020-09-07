#include <gb/gb.h>
#include <stdio.h>
#include <rand.h>
#include "types.h"


#define CLEAN=1

#ifdef CLEAN
	#include "../Resouces/minigames_0_clean.c"
#else
	#include "../Resouces/minigames_0.c"
#endif

#include "../Resouces/mingame_title_map.c"

#ifdef CLEAN
	#include "../Resouces/game_title_map_clean.c"
#else
	#include "../Resouces/game_title_map.c"
#endif

#include "../Resouces/building_00.c"
#include "../Resouces/green_sqaure.c"
#ifdef CLEAN
	#include "../Resouces/victory_screen_clean.c"
#else
	#include "../Resouces/victory_screen.c"
#endif
#ifdef CLEAN
	#include "../Resouces/soviet_symbol_big_clean.c"
#else
	#include "../Resouces/soviet_symbol_big.c"
#endif

#ifdef CLEAN
	#include "../Resouces/game_over_clean.c"
#else
	#include "../Resouces/game_over.c"
#endif

#include "../Resouces/building_background_00.c"
#include "../Resouces/block_game_background.c"
#include "../Resouces/subway_background_map.c"
#include "../Resouces/subway_doors_map.c"
#include "../Resouces/tank_background.c"
#include "../Resouces/lie_game_background_text_map.c"
#include "../Resouces/lie_game_buttons_map.c"
#include "../Resouces/vote_game_voting_options_map.c"
#include "../Resouces/censor_game_background_text_map.c"
#include "../Resouces/buy_car_game_background_map.c"
#include "../Resouces/buy_car_game_text_map.c"
#include "../Resouces/buy_car_game_text_response_map.c"
#include "../Resouces/buy_car_game_text_final_map.c"
#include "../Resouces/health_game_background_building_map.c"
#include "../Resouces/health_care_inside_background_map.c"
#include "../Resouces/speech_box_map.c"

#define MAX_X 160
#define MAX_Y 144

#define MIDDLE_X MAX_X / 2
#define MIDDLE_Y MAX_Y / 2

#define MIDDLE_X_8x8 (MAX_X / 2) + 4
#define MIDDLE_Y_8x8 (MAX_Y / 2) + 4

#define NUMBER_OF_SCREEN_TILES 32

#define NUMBER_OF_MINIGAMES 16

// ENEMY_NUMBERS
#define NUMBER_OF_DEVILS 2
#define NUMBER_OF_SMALL_ENEMIES 5

// TILES
#define BLANK_TILE 127

#define PLAYER_PLAIN_FACE_TILE 0
#define PLAYER_SAD_FACE_TILE 37
#define PLAYER_SCREAMING_FACE_TILE 55
#define PLAYER_SCREAMING_SELECTED_TILE 60

#define GOAL_FLAG_START_TILE 1
#define GOAL_FLAG_BOTTOM_TILE 2

#define ALPHABET_START_TILE 3
#define QUESTION_MARK_TILE 104
#define COLON_TILE 108
#define DOT_DOT_DOT_TILE 109
#define FULL_STOP_TILE 110
#define DASH_TILE 111
#define DIGIT_START_TILE 39

#define BULLET_TILE 38

#define PROGRESS_BAR_EMPTY_END 39
#define PROGRESS_BAR_EMPTY_MIDDLE 40
#define PROGRESS_BAR_FILLED_END 41
#define PROGRESS_BAR_FILLED_MIDDLE 42

#define SPACE_SHIP_TOP_TILE 62
#define SPACE_SHIP_MIDDLE_TILE 61
#define SPACE_SHIP_BOTTOM_OFF_TILE 63
#define SPACE_SHIP_BOTTOM_ON_A_TILE 80
#define SPACE_SHIP_BOTTOM_ON_B_TILE 81

#define PLAYER_IDLE_TILE 0
#define PLAYER_SHOOT_TILE 1
#define PLAYER_DAMAGE_TILE 2

#define VODKA_BOTTLE_TILE 49 
#define SOVIET_SYMBOL_TILE 50

#define TANK_TOP_LEFT_TILE 84
#define TANK_TOP_RIGHT_TILE 86
#define TANK_BOTTOM_LEFT_TILE 85
#define TANK_BOTTOM_RIGHT_TILE 87

#define FLAG_POLE_TILE 90
#define FLAG_MIDDLE_TILE 89

#define BUTTON_UP_TOP_LEFT_TILE 88
#define BUTTON_DOWN_TOP_LEFT_TILE 91
#define HAND_TILE 83

#define BRICK_TILE 51
#define BRICK_WINDOW_TILE 54
#define BRICK_ROOF_TILE 53

#define SUBWAY_DOOR_CLOSED_TILE 96
#define SUBWAY_DOOR_OPEN_TILE 98
#define SUBWAY_DOOR_TOP_TILE 92
#define SUBWAY_END_TILE 97

#define HEALTH_TILE 8

#define GRATE_BACKGROUND_TILE 82

#define TABLE_TILE 107

#define FILLED_TILE 106

//MISC
#define MAX_HEALTH 3

// TIMES
#define MINIGAME_TIME 360
#define TITLE_TEXT_DISPLAY_TIME 120

// Locations
#define TIMER_LOCATION_X 80
#define TIMER_LOCATION_Y 24

// WHAT I WAS DOING UPDATING SPRITE NUMBERS FOR BARS WILL HAVE TO REMOVE GOAL WHICH MEANS UPDATING TEXT START ETC
// SPRITES
#define PLAYER_SPRITE 0
#define TIMER_FIRST_DIGIT 1
#define TIMER_SECOND_DIGIT 2
#define MINIGAME_SPRITE_START 3

// Define Functions
#define initialise_8x8_sprite(ID, TILE, X, Y) {\
		set_sprite_tile(ID, TILE); \
		move_sprite(ID, X, Y); \
	}

#define initialise_goal_flag_sprite(STARTING_ID) {\
		set_sprite_tile(STARTING_ID, GOAL_FLAG_START_TILE); \
		\
		set_sprite_tile(STARTING_ID + 1, GOAL_FLAG_BOTTOM_TILE); \
	}

#define initialise_space_ship_sprite(STARTING_ID) { \
		set_sprite_tile(STARTING_ID, SPACE_SHIP_TOP_TILE); \
		set_sprite_tile(STARTING_ID + 1, SPACE_SHIP_MIDDLE_TILE); \
		set_sprite_tile(STARTING_ID + 2, SPACE_SHIP_MIDDLE_TILE); \
		set_sprite_tile(STARTING_ID + 3, SPACE_SHIP_MIDDLE_TILE); \
		set_sprite_tile(STARTING_ID + 4, SPACE_SHIP_MIDDLE_TILE); \
		set_sprite_tile(STARTING_ID + 5, SPACE_SHIP_BOTTOM_OFF_TILE); \
		\
		set_sprite_tile(STARTING_ID + 6, SPACE_SHIP_TOP_TILE); \
		set_sprite_prop(STARTING_ID + 6, S_FLIPX); \
		\
		set_sprite_tile(STARTING_ID + 7, SPACE_SHIP_MIDDLE_TILE); \
		set_sprite_prop(STARTING_ID + 7, S_FLIPX); \
		\
		set_sprite_tile(STARTING_ID + 8, SPACE_SHIP_MIDDLE_TILE); \
		set_sprite_prop(STARTING_ID + 8, S_FLIPX); \
		\
		set_sprite_tile(STARTING_ID + 9, SPACE_SHIP_MIDDLE_TILE); \
		set_sprite_prop(STARTING_ID + 9, S_FLIPX); \
		\
		set_sprite_tile(STARTING_ID + 10, SPACE_SHIP_MIDDLE_TILE); \
		set_sprite_prop(STARTING_ID + 10, S_FLIPX); \
		\
		set_sprite_tile(STARTING_ID + 11, SPACE_SHIP_BOTTOM_OFF_TILE); \
		set_sprite_prop(STARTING_ID + 11, S_FLIPX); \
	}

#define move_16x16_sprite(STARTING_ID, X, Y) { \
		move_sprite(STARTING_ID, X, Y); \
		move_sprite(STARTING_ID + 1, X + 8, Y); \
		move_sprite(STARTING_ID + 2, X, Y + 8); \
		move_sprite(STARTING_ID + 3, X + 8, Y + 8); \
	}

#define move_16x8_sprite(STARTING_ID, X, Y) { \
		move_sprite(STARTING_ID, X, Y); \
		move_sprite(STARTING_ID + 1, X + 8, Y); \
	}

#define move_8x16_sprite(STARTING_ID, X, Y) { \
		move_sprite(STARTING_ID, X, Y); \
		move_sprite(STARTING_ID + 1, X, Y + 8); \
	}

#define move_8x32_sprite(STARTING_ID, X, Y) { \
		move_sprite(STARTING_ID, X, Y); \
		move_sprite(STARTING_ID + 1, X, Y + 8); \
		move_sprite(STARTING_ID + 2, X, Y + 16); \
	}

// [0, 0] [0, 0]
// [0, 1] [0, 8]
// [0, 2] [0, 16]
// [0, 3] [0, 24]
// [0, 4] [0, 32]
// [0, 5] [0, 40]
// [0, 6] [0, 48]
#define move_16x40_sprite(STARTING_ID, X, Y) { \
		move_sprite(STARTING_ID, X, Y); \
		move_sprite(STARTING_ID + 1, X, Y + 8); \
		move_sprite(STARTING_ID + 2, X, Y + 16); \
		move_sprite(STARTING_ID + 3, X, Y + 24); \
		move_sprite(STARTING_ID + 4, X, Y + 32); \
		move_sprite(STARTING_ID + 5, X, Y + 40); \
		\
		move_sprite(STARTING_ID + 6, X + 8, Y); \
		move_sprite(STARTING_ID + 7, X + 8, Y + 8); \
		move_sprite(STARTING_ID + 8, X + 8, Y + 16); \
		move_sprite(STARTING_ID + 9, X + 8, Y + 24); \
		move_sprite(STARTING_ID + 10, X + 8, Y + 32); \
		move_sprite(STARTING_ID + 11, X + 8, Y + 40); \
	}

#define scroll_16x40_sprite(STARTING_ID, X, Y) { \
		scroll_sprite(STARTING_ID, X, Y); \
		scroll_sprite(STARTING_ID + 1, X, Y + 8); \
		scroll_sprite(STARTING_ID + 2, X, Y + 16); \
		scroll_sprite(STARTING_ID + 3, X, Y + 24); \
		scroll_sprite(STARTING_ID + 4, X, Y + 32); \
		scroll_sprite(STARTING_ID + 5, X, Y + 40); \
		\
		scroll_sprite(STARTING_ID + 6, X + 8, Y); \
		scroll_sprite(STARTING_ID + 7, X + 8, Y + 8); \
		scroll_sprite(STARTING_ID + 8, X + 8, Y + 16); \
		scroll_sprite(STARTING_ID + 9, X + 8, Y + 24); \
		scroll_sprite(STARTING_ID + 10, X + 8, Y + 32); \
		scroll_sprite(STARTING_ID + 11, X + 8, Y + 40); \
	}

#define get_tile_for_char(X) (X - 'A') + ALPHABET_START_TILE

#define rect_overlaping(A_LEFT, A_RIGHT, A_TOP, A_BOTTOM, B_LEFT, B_RIGHT, B_TOP, B_BOTTOM) A_LEFT <= B_RIGHT && B_LEFT <= A_RIGHT && A_TOP <= B_BOTTOM && B_TOP <= A_BOTTOM

#define rect_inside(A_LEFT, A_RIGHT, A_TOP, A_BOTTOM, B_LEFT, B_RIGHT, B_TOP, B_BOTTOM) A_LEFT >= B_LEFT && A_TOP >= B_TOP && A_RIGHT <= B_RIGHT && A_BOTTOM <= B_BOTTOM

#define sprites_8x8_overlaping(A_X, A_Y, B_X, B_Y) rect_overlaping(A_X, A_X + 8, A_Y, A_Y + 8, B_X, B_X + 8, B_Y, B_Y + 8)

#define sprite_in_green_square(A_X, A_Y) rect_inside(A_X, A_X + 8, A_Y, A_Y + 8, 64, 104, 80, 111)

#define UBYTE_rand_in_range(MIN, MAX) \
	(((UBYTE)rand()) % MAX - MIN) + MIN

uint_16 _seed;
uint_16 _devil_move_delay;
uint_16 _devil_change_direction;

UBYTE _player_x;
UBYTE _player_y;

UWORD _count;
UBYTE _next_minigame;

BYTE _health;

void beep() {
	NR10_REG = 0x38U;
	NR11_REG = 0x70U;
	NR12_REG = 0xE0U;
	NR13_REG = 0x0AU;
	NR14_REG = 0xC6U;

	NR51_REG |= 0x11;
}

void player_moved() {
	move_sprite(PLAYER_SPRITE, _player_x, _player_y);
}
 
void initialise_player_sprite() {
	initialise_8x8_sprite(0, PLAYER_IDLE_TILE, MIDDLE_X, MIDDLE_Y);
}

void clear_sprites(UBYTE starting_id, UBYTE n) {
	UBYTE i;

	for(i = 0; i < n; i++) {
		move_sprite(starting_id + i, 0x00, 0x00);
		set_sprite_prop(starting_id + i, 0x00);
	}
}

void print_text(uint_8 starting_id, const char* text, UBYTE n, UBYTE x, UBYTE y) {
	UBYTE i;
	BYTE tile;

	for(i = 0; i < n; i++) {
		if(text[i] == ' ') {
			tile = BLANK_TILE;
		} else {
			tile = get_tile_for_char(text[i]);
		}
		initialise_8x8_sprite(starting_id + i, tile, x + (i * 8), y);
	}
}

void show_health() {
	BYTE i;

	for(i = 0; i < _health; i++) {
		initialise_8x8_sprite(MINIGAME_SPRITE_START + i, SOVIET_SYMBOL_TILE, (MIDDLE_X - 8) + (i * 8) + (i * 2), 50);
	}

}

void hide_health() {
	BYTE i;

	for(i = 0; i < _health; i++) {
		move_sprite(MINIGAME_SPRITE_START + i, 200, 200);
	}
}

void game_success() {
	set_bkg_tiles(0, 0, mingame_title_mapWidth, mingame_title_mapHeight, mingame_title_map);

	set_bkg_tiles(2, 2, victory_screenWidth, victory_screenHeight, victory_screen);

	set_bkg_tiles(8, 11, soviet_symbol_bigWidth, soviet_symbol_bigHeight, soviet_symbol_big);

	waitpad(J_A);
	waitpadup();
}


void game_over() {
	set_bkg_tiles(0, 0, mingame_title_mapWidth, mingame_title_mapHeight, mingame_title_map);
	
	set_bkg_tiles(3, 2, game_over_mapWidth, game_over_mapHeight, game_over_map);

	waitpad(J_A);
	waitpadup();
}

void minigame_fail() {
	UBYTE n = 15;

	_health--;

	set_bkg_tiles(0, 0, mingame_title_mapWidth, mingame_title_mapHeight, mingame_title_map);

	SHOW_BKG;

	if(_health < 0) {

	} else {
		show_health();

		print_text(MINIGAME_SPRITE_START + MAX_HEALTH, "YOU HAVE", 8, MIDDLE_X - ((8 / 2) * 8), MIDDLE_Y);
		print_text(MINIGAME_SPRITE_START + MAX_HEALTH + 8, "FAILLED", 7, MIDDLE_X - ((7 / 2) * 8), MIDDLE_Y + 9);
#ifdef CLEAN
		print_text(MINIGAME_SPRITE_START + MAX_HEALTH + 8 + 7, "THE MONEY", 9, MIDDLE_X - ((9 / 2) * 8), MIDDLE_Y + 18);
#else
		print_text(MINIGAME_SPRITE_START + MAX_HEALTH + 8 + 7, "THE STATE", 9, MIDDLE_X - ((9 / 2) * 8), MIDDLE_Y + 18);
#endif		
		delay(1200);

		hide_health();
		clear_sprites(MINIGAME_SPRITE_START + MAX_HEALTH, 8 + 7 + 9);
	}
}

void minigame_success() {
	UBYTE n = 15;

	set_bkg_tiles(0, 0, mingame_title_mapWidth, mingame_title_mapHeight, mingame_title_map);

	SHOW_BKG;

	show_health();

	print_text(MINIGAME_SPRITE_START + MAX_HEALTH, "MASSIVE", 7, MIDDLE_X - ((7 / 2) * 8), MIDDLE_Y);
	print_text(MINIGAME_SPRITE_START + MAX_HEALTH + 7, "SUCCESS", 7, MIDDLE_X - ((7 / 2) * 8), MIDDLE_Y + 9);
	
	delay(1200);

	hide_health();
	clear_sprites(MINIGAME_SPRITE_START + MAX_HEALTH, 7 * 2);
}

void reset_timer() {
	_count = MINIGAME_TIME;

	set_sprite_tile(TIMER_FIRST_DIGIT, DIGIT_START_TILE);
	set_sprite_tile(TIMER_SECOND_DIGIT, DIGIT_START_TILE);
}

void step_timer() {
	BYTE seconds;
	BYTE first_digit;
	BYTE second_digit;
	
	_count--;
	seconds = _count / 60;
	first_digit = seconds % 10;
	second_digit = seconds / 10;
	
	set_sprite_tile(TIMER_FIRST_DIGIT, DIGIT_START_TILE + second_digit);

	set_sprite_tile(TIMER_SECOND_DIGIT, DIGIT_START_TILE + first_digit);
}

void hide_timer() {
	move_sprite(TIMER_FIRST_DIGIT, 200, 200);
	move_sprite(TIMER_SECOND_DIGIT, 200, 200);
}

void show_timer() {
	move_sprite(TIMER_FIRST_DIGIT, TIMER_LOCATION_X, TIMER_LOCATION_Y);
	move_sprite(TIMER_SECOND_DIGIT, TIMER_LOCATION_X + 9, TIMER_LOCATION_Y);
}

void hide_player() {
	_player_x = 200;
	_player_y = 200;
	player_moved();
}

void process_movement() {
	if(joypad() & J_RIGHT) {
		_player_x++;
		player_moved();
	}
	
	if(joypad() & J_LEFT) {
		_player_x--;
		player_moved();
	}

	if(joypad() & J_UP) {
		_player_y--;
		player_moved();
	}

	if(joypad() & J_DOWN) {
		_player_y++;
		player_moved();
	}
}

void print_UWORD_number(UBYTE starting_id, UWORD number, UBYTE x, UBYTE y) {
	BYTE digits[4];
	BYTE i = 3;

	while(number > 0) {
		digits[i] = number % 10;
		number /= 10;
		i--;
	}
	
	for(; i < 4; i++) {
		set_sprite_tile(starting_id + i, DIGIT_START_TILE + digits[i]);
		move_sprite(starting_id + i, x + (i * 8), y);
	}
}

void show_text(const BYTE* text, BYTE n) {
	BYTE i, j, k, y;
	BYTE letter[18];

	k = 0;
	y = 14;
	for(i = 0; i < n;) {
		set_bkg_tiles(0, 13, speech_box_mapWidth, speech_box_mapHeight, speech_box_map);
		
		for(j = 0; j < 3 && i < n; j += 2) {
			for(k = 0; k < 17; k++) {
				if(k + i < n) {
					letter[k] = text[k + i];

					switch (letter[k]) {
						case '?':
							letter[k] = QUESTION_MARK_TILE;
							break;
						case ':':
							letter[k] = COLON_TILE;
							break;
						case '.':
							letter[k] = FULL_STOP_TILE;
							break;
						case '@':
							letter[k] = DOT_DOT_DOT_TILE;
							break;
						default:
							letter[k] = ALPHABET_START_TILE + (letter[k] - 'A'); //get_tile_for_char(letter[0]);
							break;
					}
				}
				else {
					letter[k] = BLANK_TILE;
				}
			}

			if(k + i < n && text[k + i - 1] != ' ' && text[k + i + 1] != ' ') {
				letter[17] = DASH_TILE;
			} else {
				letter[17] = j == 2 ? DOT_DOT_DOT_TILE : BLANK_TILE;
			}

			i += k;

			set_bkg_tiles(1, y + j, 18, 1, letter);
		}

		waitpad(J_A);
		waitpadup();
	}
}

#define HEALTH_GAME_INSIDE_FLOOR_HEIGHT 13 * 8
#define HEALTH_GAME_TABLE_X 14 * 8

BYTE start_health_care_game() {
	// MONEY 0
	BYTE money_map[] = {get_tile_for_char('M'), get_tile_for_char('O'), get_tile_for_char('N'), get_tile_for_char('E'), get_tile_for_char('Y'), BLANK_TILE, DIGIT_START_TILE};
	BYTE inside = 0;


	set_bkg_tiles(0, 0, health_game_background_building_mapWidth, health_game_background_building_mapHeight, health_game_background_building_map);

	set_bkg_tiles(1, 2, 7, 1, money_map);

	show_timer();
	reset_timer();

	_player_x = 16;
	_player_y = 13 * 8;
	
	while (_count > 0) {
		wait_vbl_done();
		step_timer();

		if(joypad() & J_LEFT && _player_x > 16) {
			_player_x--;
		}

		if(joypad() & J_RIGHT && ((inside && _player_x < HEALTH_GAME_TABLE_X - 8) || (!inside && _player_x < MAX_X))) {
			_player_x++;
		}

		if(joypad() & J_A && inside && _player_x > HEALTH_GAME_TABLE_X - 16) {
			waitpadup();
#ifdef CLEAN
			show_text("CAPO JOHN: HI GLORY TO THE MONEY HOW CAN I HELP YOU?", 52);
			show_text("CAPO YOU:I AM SICK AND NEED DOCTOR", 34);
			show_text("CAPO JOHN: DO YOU HAVE MONEY?", 29);
			show_text("CAPO YOU: NO WORK AT AMAZON", 27);
			show_text("CAPO JOHN: FUCK YOU I HAVE MINE.", 32);
#else
			show_text("COMO VLAD: HELLO COMRADE GLORY TO THE STATE HOW CAN I HELP YOU?", 63);
			show_text("COMO YOU: I AM SICK COMRADE AND NEED DOCTOR.", 43);
			show_text("COMO VLAD: YOU WILL NEED TO WAIT BUT YOU WILL BE HEALED.", 55);
			show_text("COMO YOU: GLORY TO THE STATE.", 28);
			show_text("COMO VLAD: GLORY TO THE STATE.", 30);
#endif
			
			set_bkg_tiles(0, 13, speech_box_mapWidth, speech_box_mapHeight, speech_box_map);
			set_bkg_tiles(8, 2, soviet_symbol_bigWidth, soviet_symbol_bigHeight, soviet_symbol_big);

			delay(5000);
			
			break;
		}

		if(joypad() & J_UP && !inside && _player_x > 112 && _player_x < 112 + 16) {
			// Change to inside building
			set_bkg_tiles(0, 0, health_care_inside_background_mapWidth, health_care_inside_background_mapHeight, health_care_inside_background_map);

			initialise_8x8_sprite(MINIGAME_SPRITE_START + 0, PLAYER_SAD_FACE_TILE, HEALTH_GAME_TABLE_X + 8, HEALTH_GAME_INSIDE_FLOOR_HEIGHT);
			initialise_8x8_sprite(MINIGAME_SPRITE_START + 2, VODKA_BOTTLE_TILE, HEALTH_GAME_TABLE_X + 8, HEALTH_GAME_INSIDE_FLOOR_HEIGHT + 8);
			initialise_8x8_sprite(MINIGAME_SPRITE_START + 1, TABLE_TILE, HEALTH_GAME_TABLE_X, HEALTH_GAME_INSIDE_FLOOR_HEIGHT);

			_player_x = 16;

			inside = 1;
		}

		player_moved();
	}

	hide_timer();
	hide_player();
	clear_sprites(MINIGAME_SPRITE_START, 3);

	return _count > 0;
}

#define text_background_tiles_array(NAME, ...) BYTE NAME[] = {get_tile_for_char(fmt), __VA_ARGS__}

#define BUY_CAR_GAME_SALESMAN_X 96

// TODO: Fix text tile maps to no include background 
BYTE start_buy_car_game() {
	BYTE year_map[] = {get_tile_for_char('Y'), get_tile_for_char('E'), get_tile_for_char('A'), get_tile_for_char('R')};
	BYTE blank_map[] = {127};
	UWORD year = 1960;
	
	set_bkg_tiles(0, 0, buy_car_game_background_mapWidth, buy_car_game_background_mapHeight, buy_car_game_background_map);
	// Can I Buy A Car Comrade?

	set_bkg_tiles(0, 2, 4, 1, year_map);
	print_UWORD_number(MINIGAME_SPRITE_START + 0, year, 5 * 8, 4 * 8);
	
	reset_timer();
	show_timer();

	_player_y = 13 * 8;
	_player_x = 1 * 8;
	player_moved();

	while (_count > 0) {
		wait_vbl_done();
		step_timer();

		if(joypad() & J_LEFT &&  _player_x > 1 * 8) {
			_player_x--;
			player_moved();
		}

		if(joypad() & J_RIGHT && _player_x < BUY_CAR_GAME_SALESMAN_X) {
			_player_x++;
			player_moved();
		}

		if(joypad() & J_A && _player_x > BUY_CAR_GAME_SALESMAN_X - 16) {
			waitpadup();
			hide_timer();

			set_bkg_tiles(0, 13, buy_car_game_text_mapWidth, buy_car_game_text_mapHeight, buy_car_game_text_map);
			// Text consvation loop
			waitpad(J_A);
			waitpadup();
			
			set_bkg_tiles(0, 13, buy_car_game_text_response_mapWidth, buy_car_game_text_response_mapHeight, buy_car_game_text_response_map);
			waitpad(J_A);
			waitpadup();

			set_bkg_tiles(18, 16, 1, 1, blank_map);

			while (year < 1966){
				year++;
				print_UWORD_number(MINIGAME_SPRITE_START + 0, year, 5 * 8, 4 * 8);
				// Some fucking reason it is doing this I cannot figure out why so that's why this is here
				move_sprite(MINIGAME_SPRITE_START - 1, 0, 0);
				delay(1000);
			}

			// No border
			set_bkg_tiles(1, 14, buy_car_game_text_final_mapWidth, buy_car_game_text_final_mapHeight, buy_car_game_text_final_map);
			waitpad(J_A);
			waitpadup();

			set_bkg_tiles(0, 0, buy_car_game_background_mapWidth, buy_car_game_background_mapHeight, buy_car_game_background_map);
			set_bkg_tiles(0, 2, 4, 1, year_map);
			hide_player();
			
			_player_y = 12 * 8;
			_player_x = 7 * 8;

			initialise_8x8_sprite(MINIGAME_SPRITE_START + 4, TANK_TOP_RIGHT_TILE, _player_x, _player_y);
			set_sprite_prop(MINIGAME_SPRITE_START + 4, S_FLIPX);

			initialise_8x8_sprite(MINIGAME_SPRITE_START + 5, TANK_TOP_LEFT_TILE, _player_x + 8, _player_y);
			set_sprite_prop(MINIGAME_SPRITE_START + 5, S_FLIPX);

			initialise_8x8_sprite(MINIGAME_SPRITE_START + 6, TANK_BOTTOM_RIGHT_TILE, _player_x, _player_y + 8);
			set_sprite_prop(MINIGAME_SPRITE_START + 6, S_FLIPX);

			initialise_8x8_sprite(MINIGAME_SPRITE_START + 7, TANK_BOTTOM_LEFT_TILE, _player_x + 8, _player_y + 8);
			set_sprite_prop(MINIGAME_SPRITE_START + 7, S_FLIPX);

			reset_timer();
			show_timer();

			while (_count != 0 && !(_player_x > MAX_X - 8)) {
				wait_vbl_done();
				step_timer();

				if(joypad() & J_LEFT) {
					_player_x--;
				}

				if((joypad() & J_RIGHT) && _player_x + 8 < 10 * 8) {
					_player_x++;
				}

				move_16x16_sprite(MINIGAME_SPRITE_START + 4, _player_x, _player_y);
			}

			break;
		}
	}

	hide_player();
	hide_timer();
	
	clear_sprites(MINIGAME_SPRITE_START + 0, 9);

	return _count != 0;
}

#define CENSOR_GAME_FIRST_LINE_X 2

BYTE start_censor_game() {
	BYTE current_index = 0;
	BYTE i, j;
	BYTE censor_game_text[] = " USA GOOD USSR BAD";
	BYTE word_tiles[18];

	for(i = 0; i < 18; i++) {
		word_tiles[i] = censor_game_text[i] == ' ' ? BLANK_TILE : ALPHABET_START_TILE + (censor_game_text[i] - 'A');
	}

	set_bkg_tiles(1, 6, 18, 1, word_tiles);

	_player_x = (2 + current_index) * 8;
	_player_y = 8 * 8;

	set_sprite_tile(MINIGAME_SPRITE_START + 0, VODKA_BOTTLE_TILE);

	reset_timer();
	show_timer();

	while(_count > 0) {
		wait_vbl_done();
		step_timer();

		if(joypad() & J_LEFT) {
			waitpadup();
			current_index--;

			if(current_index < 0) {
				current_index = 14;
			} else {
				while (censor_game_text[current_index] != ' ') {
					current_index--;
				}
			}

			_player_x = (2 + current_index) * 8;
		}

		if(joypad() & J_RIGHT) {
			waitpadup();
			current_index++;

			if(current_index > 14) {
				current_index = 0;
			} else {
				while (censor_game_text[current_index] != ' ') {
					current_index++;
				}
			}

			_player_x = (2 + current_index) * 8;
		}

		if(joypad() & J_A) {
			waitpadup();

			for(j = current_index + 1; censor_game_text[j] != ' ' && j < 18; j++) {
				word_tiles[j] = word_tiles[j] == FILLED_TILE ? ALPHABET_START_TILE + (censor_game_text[j] - 'A') : FILLED_TILE;
			}
			
			set_bkg_tiles(1, 6, 18, 1, word_tiles);
		}

		move_sprite(MINIGAME_SPRITE_START + 0, _player_x, _player_y);
	}

	hide_timer();

	clear_sprites(MINIGAME_SPRITE_START, 7);
 
	// USA BAD ^ GOOD USSR
	return (word_tiles[5] == FILLED_TILE && word_tiles[10] == FILLED_TILE) ^ (word_tiles[1] == FILLED_TILE && word_tiles[15] == FILLED_TILE);
}

// Vote
BYTE start_vote_game() {
	BYTE state = 1;

	set_bkg_tiles(3, 6, vote_game_voting_options_mapWidth, vote_game_voting_options_mapHeight, vote_game_voting_options_map);

	_player_x = 4 * 8;
	set_sprite_tile(MINIGAME_SPRITE_START + 0, GRATE_BACKGROUND_TILE);

	reset_timer();
	show_timer();

	while (_count > 0 && !(joypad() & J_A)) {
		wait_vbl_done();
		step_timer();

		if(joypad() & J_UP){
			state--;
			waitpadup();
		}

		if(joypad() & J_DOWN) {
			state++;
			waitpadup();
		}

		if(state > 1) {
			state = 0;
		} else if(state < 0) {
			state = 1;
		}

		switch (state) {
			case 0:
				_player_y = 8 * 8;
				break;
			case 1:
				_player_y = 11 * 8;
				break;
		}

		move_sprite(MINIGAME_SPRITE_START + 0, _player_x, _player_y);
	}

	hide_timer();
	
#ifdef CLEAN
	return state == 1;
#else
	return state == 0;
#endif
}

#define LIE_GAME_PLAYER_X_START 10 * 8
#define LIE_GAME_PLAYER_Y_START 14 * 8 + 4

// LIE
BYTE start_lie_game() {
	BYTE state = 0;

	// Set up text
	set_bkg_tiles(5, 3, lie_game_background_text_mapWidth, lie_game_background_text_mapHeight, lie_game_background_text_map);
	set_bkg_tiles(5, 11, lie_game_buttons_mapWidth, lie_game_buttons_mapHeight, lie_game_buttons_map);

	_player_x = LIE_GAME_PLAYER_X_START;
	_player_y = LIE_GAME_PLAYER_Y_START;
	player_moved();

	set_sprite_tile(MINIGAME_SPRITE_START + 0, VODKA_BOTTLE_TILE);

	reset_timer();
	show_timer();

	while (_count > 0 && !(joypad() & J_A)) {
		wait_vbl_done();
		step_timer();

		if(joypad() & J_RIGHT) {
			waitpadup();
			state++;
		}

		if(joypad() & J_LEFT) {
			waitpadup();
			state--;
		}

		if(state > 1) {
			state = 0;
		}

		if(state < 0) {
			state = 1;
		}

		switch (state)
		{
			case 0:
				move_sprite(MINIGAME_SPRITE_START + 0, 6 * 8, 13 * 8);
				break;
			
			case 1:
				move_sprite(MINIGAME_SPRITE_START + 0, 11 * 8, 13 * 8);
				break;
		}
	}

	if(_count == 0) {
		state = 1;
	}

	if(state == 1) {
		_player_x = 0;
		set_sprite_tile(MINIGAME_SPRITE_START + 1, BULLET_TILE);

		while (_player_x < LIE_GAME_PLAYER_X_START) {
			wait_vbl_done();

			_player_x++;
			move_sprite(MINIGAME_SPRITE_START + 1, _player_x, LIE_GAME_PLAYER_Y_START);
		}

		move_sprite(MINIGAME_SPRITE_START + 0, 0, 0);
	}

	move_sprite(MINIGAME_SPRITE_START + 1, 0, 0);

	hide_timer();
	hide_player();

	return state == 0;
}

#define GAME_10_MOVE_SPEED 2

// Enter
BYTE start_enter_building_game() {
	UBYTE active_bkg[NUMBER_OF_SCREEN_TILES * tank_backgroundHeight];
	BYTE last_active_postion = 0;
	BYTE tank_background_postion = 32;
	BYTE i, j;
	UWORD world_x;

	for(i = 0; i < tank_backgroundHeight; i++) {
		for(j = 0; j < NUMBER_OF_SCREEN_TILES; j++) {
			active_bkg[NUMBER_OF_SCREEN_TILES * i + j] = tank_background[tank_backgroundWidth * i + j];
		}
	}

	_player_x = 24;
	_player_y = MIDDLE_Y + 8;
	
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 0, PLAYER_PLAIN_FACE_TILE, _player_x, _player_y);

	reset_timer();
	show_timer();

	set_bkg_tiles(0, 0, NUMBER_OF_SCREEN_TILES, tank_backgroundHeight, active_bkg);

	j = 0;
	while (1) {
		wait_vbl_done();
		step_timer();

		if(joypad() & J_LEFT && _player_x - GAME_10_MOVE_SPEED > 8) {
			_player_x -= GAME_10_MOVE_SPEED;
			move_sprite(MINIGAME_SPRITE_START + 0, _player_x, _player_y);
		}

		world_x = (UWORD)_player_x + (UWORD)((tank_background_postion - 32) * 8);
		
		if(joypad() & J_UP && world_x >= 304 && world_x <= 304 + 16) {
			i = 1;
			break;
		}

		if(joypad() & J_RIGHT) {
			if(tank_background_postion - 12 < tank_backgroundWidth) {
				if(_player_x < MAX_X / 2) {
					_player_x += GAME_10_MOVE_SPEED;
					move_sprite(MINIGAME_SPRITE_START + 0, _player_x, _player_y);
				} else {
					scroll_bkg(GAME_10_MOVE_SPEED, 0);
					j += GAME_10_MOVE_SPEED;

					if(j % 8 == 0) {
						for(i = 0; i < tank_backgroundHeight; i++) {
							active_bkg[NUMBER_OF_SCREEN_TILES * i + last_active_postion] = tank_background[tank_backgroundWidth * i + tank_background_postion];
						}

						set_bkg_tiles(0, 0, NUMBER_OF_SCREEN_TILES, tank_backgroundHeight, active_bkg);

						tank_background_postion++;

						if(last_active_postion == 31) {
							last_active_postion = 0;
						} else {
							last_active_postion++;
						}
					}
				}
			} else if(_player_x < 116) {
				_player_x += GAME_10_MOVE_SPEED;
				move_sprite(MINIGAME_SPRITE_START + 0, _player_x, _player_y);
			}
		}

		if(_count == 0) {
			i = 0;
			break;
		}
	}

	set_bkg_tiles(0, 0, game_title_mapWidth, game_title_mapHeight, game_title_map);
	move_bkg(0, 0);

	move_sprite(MINIGAME_SPRITE_START + 0, 0, 0);

	hide_timer();
	
	return i;
}

// Subway game
BYTE start_subway_game() {
	BYTE random_person_x = 84;
	BYTE success = 0;

	set_bkg_tiles(0, 0, subway_background_mapWidth, subway_background_mapHeight, subway_background_map);

	initialise_8x8_sprite(MINIGAME_SPRITE_START + 0, PLAYER_SAD_FACE_TILE, 0, 0);
	
	// Background moves to give subway train moving effect
	move_bkg(12 * 8, 0);
	reset_timer();
	show_timer();

	_player_x = 140;
	_player_y = 17 * 8;
	player_moved();

	while (_count > 0) {
		wait_vbl_done();
		step_timer();

		if(_count > 296) {
			scroll_bkg(-2, 0);
		}
		else if(_count == 296) {
			scroll_bkg(-2, 0);
			set_bkg_tiles(5, 14, 2, 2, subway_doors_map);
		} 
		
		if(joypad() & J_LEFT) {
			if(_count % 2 == 0) {
				_player_x--;
				player_moved();
			}
		}

		if(joypad() & J_RIGHT) {
			if(_count % 2 == 0) {
				_player_x++;
				player_moved();
			}
		}

		if(_count < 290) {
			if(_count % 25 == 0) {
				random_person_x--;
				move_sprite(MINIGAME_SPRITE_START + 0, random_person_x, 17 * 8);
			}

			if(random_person_x + 8 > _player_x) {
				break;
			}

			if(joypad() & J_UP && _player_x >= 80 && _player_x <= 88) {
				hide_player();				
				success = 1;
				break;
			}
		}
	}

	hide_timer();

	set_bkg_tiles(0, 0, subway_background_mapWidth, subway_background_mapHeight, subway_background_map);

	_count = 0;
	while (_count < 64) {
		wait_vbl_done();
		scroll_bkg(-2, 0);
		_count++;
	}
	
	hide_player();
	move_bkg(0, 0);
	move_sprite(MINIGAME_SPRITE_START + 0, 0, 0);
	
	return success;
}

#define BUTTON_TOP_LEFT_X MIDDLE_X
#define BUTTON_TOP_LEFT_Y MIDDLE_Y

BYTE start_block_game() {
	BYTE direction = 1;
	BYTE success = 0;

	set_bkg_tiles(1, 14, block_game_backgroundWidth, block_game_backgroundHeight, block_game_background);

	// Player controlled 
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 0, BRICK_ROOF_TILE, _player_x, _player_y + 0);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 1, BRICK_TILE, _player_x, _player_y + 8);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 2, BRICK_TILE,  _player_x, _player_y + 16);
	
	reset_timer();

	_player_x = 5 * 8;
	_player_y = 40;

	while (1) {
		wait_vbl_done();

		step_timer();

		if(_count % 4 == 0) {
			_player_y++;
		} else {
			continue;
		}

		if(joypad() & J_A) {
			direction = !direction;
			waitpadup();
		}

		if(joypad() & J_LEFT) {
			_player_x -= 8;
		}

		if(joypad() & J_RIGHT) {
			_player_x += 8;
		}

		move_sprite(MINIGAME_SPRITE_START + 0, _player_x + direction * 0, _player_y + !direction * 0);
		move_sprite(MINIGAME_SPRITE_START + 1, _player_x + direction * 8, _player_y + !direction * 8);
		move_sprite(MINIGAME_SPRITE_START + 2, _player_x + direction * 16, _player_y + !direction * 16);

		if(
			(_player_x != 8 * 11 && _player_y == ((8 * 16) - (direction ? (8 * 1) - 2 : (8 * 3) - 2))) ||
			(_player_x == 8 * 11 && ((direction && _player_y == (8 * 15) + 2) || _player_y == (8 * 16)))
		) {
			delay(2000);
			break;
		}
	}

	move_sprite(MINIGAME_SPRITE_START + 0, 0, 0);
	move_sprite(MINIGAME_SPRITE_START + 1, 0, 0);
	move_sprite(MINIGAME_SPRITE_START + 2, 0, 0);

	hide_timer();

	return !direction && _player_y == (8 * 16) && _player_x == 8 * 11;
}

BYTE start_fire_missle_game() {
	_player_x = MIDDLE_X - 30;
	_player_y = MIDDLE_Y + 4;

	initialise_8x8_sprite(MINIGAME_SPRITE_START + 0, HAND_TILE, _player_x, _player_y);
	set_sprite_prop(MINIGAME_SPRITE_START + 0, S_PRIORITY);

	// Button top left
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 1, BUTTON_UP_TOP_LEFT_TILE, BUTTON_TOP_LEFT_X, BUTTON_TOP_LEFT_Y);

	// Button top right
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 2, BUTTON_UP_TOP_LEFT_TILE, BUTTON_TOP_LEFT_X + 8, BUTTON_TOP_LEFT_Y);
	set_sprite_prop(MINIGAME_SPRITE_START + 2, S_FLIPX);

	// Button bottom left
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 3, BUTTON_UP_TOP_LEFT_TILE, BUTTON_TOP_LEFT_X, BUTTON_TOP_LEFT_Y + 8);
	set_sprite_prop(MINIGAME_SPRITE_START + 3, S_FLIPY);

	// Button bottom right
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 4, BUTTON_UP_TOP_LEFT_TILE, BUTTON_TOP_LEFT_X + 8, BUTTON_TOP_LEFT_Y + 8);
	set_sprite_prop(MINIGAME_SPRITE_START + 4, S_FLIPX | S_FLIPY);

	reset_timer();
	show_timer();

	while(_count > 0) {
		wait_vbl_done();
		step_timer();

		if(joypad() & J_RIGHT) {
			_player_x++;
			move_sprite(MINIGAME_SPRITE_START + 0, _player_x, _player_y);

			// Button has been pressed
			if(_player_x >= 79) {
				set_sprite_tile(MINIGAME_SPRITE_START + 0, BUTTON_DOWN_TOP_LEFT_TILE);
				set_sprite_tile(MINIGAME_SPRITE_START + 2, BUTTON_DOWN_TOP_LEFT_TILE);
				set_sprite_tile(MINIGAME_SPRITE_START + 3, BUTTON_DOWN_TOP_LEFT_TILE);
				set_sprite_tile(MINIGAME_SPRITE_START + 4, BUTTON_DOWN_TOP_LEFT_TILE);

				set_sprite_prop(MINIGAME_SPRITE_START + 0, 0);
				set_sprite_prop(MINIGAME_SPRITE_START + 2, 0);
				set_sprite_prop(MINIGAME_SPRITE_START + 3, 0);
				set_sprite_prop(MINIGAME_SPRITE_START + 4, 0);

				print_text(MINIGAME_SPRITE_START, "LIFE  DEAD", 10, MIDDLE_X - (8 * 5), MIDDLE_Y);
				delay(2000);
				clear_sprites(MINIGAME_SPRITE_START, 9);
				break;
			}
		}
	}

	hide_timer();

	for(_count = 0; _count < 5; _count++) {
		move_sprite(MINIGAME_SPRITE_START + _count, 0, 0);
		set_sprite_prop(MINIGAME_SPRITE_START + _count, 0);
	}

	return _player_x < 79;
}

#define POLE_START_X MIDDLE_X 
#define POLE_START_Y MIDDLE_Y - 5

// Raise Flag
BYTE start_raise_flag_game() {
	BYTE success = 0;

	_player_y = MIDDLE_Y + 24;

	set_bkg_tiles(6, 11, building_00Width, building_00Height, building_00);

	// This is used so it can overlay 
	// Sprites used are out of order becuase I fucked it 
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 0, FLAG_POLE_TILE, POLE_START_X, POLE_START_Y);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 1, FLAG_POLE_TILE, POLE_START_X, POLE_START_Y + 8);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 2, FLAG_POLE_TILE, POLE_START_X, POLE_START_Y + 16);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 3, FLAG_POLE_TILE, POLE_START_X, POLE_START_Y + 24);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 10, FLAG_POLE_TILE, POLE_START_X, POLE_START_Y + 32);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 11, FLAG_POLE_TILE, POLE_START_X, POLE_START_Y + 40);

	initialise_8x8_sprite(MINIGAME_SPRITE_START + 4, FLAG_MIDDLE_TILE, MIDDLE_X + 8, _player_y);
	set_sprite_prop(MINIGAME_SPRITE_START + 4, S_FLIPY);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 5, FLAG_MIDDLE_TILE, MIDDLE_X + 8, _player_y + 8);

	initialise_8x8_sprite(MINIGAME_SPRITE_START + 6, FLAG_MIDDLE_TILE, MIDDLE_X + 16, _player_y);
	set_sprite_prop(MINIGAME_SPRITE_START + 6, S_FLIPY);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 7, FLAG_MIDDLE_TILE, MIDDLE_X + 16, _player_y + 8);

	initialise_8x8_sprite(MINIGAME_SPRITE_START + 8, FLAG_MIDDLE_TILE, MIDDLE_X + 24, _player_y);
	set_sprite_prop(MINIGAME_SPRITE_START + 8, S_FLIPY);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 9, FLAG_MIDDLE_TILE, MIDDLE_X + 24, _player_y + 8);

	reset_timer();

	while (!(joypad() & (J_A | J_B | J_LEFT ) || _player_y < POLE_START_Y - 8)) {
		wait_vbl_done();

		step_timer();

		if(_count % 5 == 0) {
			_player_y--;
			move_sprite(MINIGAME_SPRITE_START + 4, MIDDLE_X + 8, _player_y);
			move_sprite(MINIGAME_SPRITE_START + 5, MIDDLE_X + 8, _player_y + 8);
			move_sprite(MINIGAME_SPRITE_START + 6, MIDDLE_X + 16, _player_y);
			move_sprite(MINIGAME_SPRITE_START + 7, MIDDLE_X + 16, _player_y + 8);
			move_sprite(MINIGAME_SPRITE_START + 8, MIDDLE_X + 24, _player_y);
			move_sprite(MINIGAME_SPRITE_START + 9, MIDDLE_X + 24, _player_y + 8);
		}
	}

	if(_player_y >= POLE_START_Y && _player_y <= POLE_START_Y + 4) {
		set_bkg_tiles(8, 2, soviet_symbol_bigWidth, soviet_symbol_bigHeight, soviet_symbol_big);
		delay(1000);
		success = 1;
	} else {
		success = 0;
	}

	for(_count = 0; _count < 12; _count++) {
		move_sprite(MINIGAME_SPRITE_START + _count, 0, 0);
		set_sprite_prop(MINIGAME_SPRITE_START + _count, 0);
	}

	return success;
}

#define GAME_BUILD_TANK_GAME_TANK_BOTTOM_Y MAX_Y

BYTE start_build_tank_game() {
	_player_y = 50;
	// postion the turrent head
	_player_x =  
		8 * (rand() % 2 == 0 ? 
			((UBYTE)2 + (UBYTE)rand() % ((UBYTE)5 - (UBYTE)2)) : 
			((UBYTE)14 + (UBYTE)rand() % ((UBYTE)18 - (UBYTE)14)));

	// Head
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 0, TANK_TOP_LEFT_TILE, MIDDLE_X, _player_y);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 1, TANK_TOP_RIGHT_TILE, MIDDLE_X + 8, _player_y);

	// Body
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 2, TANK_BOTTOM_LEFT_TILE, _player_x, GAME_BUILD_TANK_GAME_TANK_BOTTOM_Y);
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 3, TANK_BOTTOM_RIGHT_TILE, _player_x + 8, GAME_BUILD_TANK_GAME_TANK_BOTTOM_Y);

	// This proably saves space?
	for(_count = 1; _count < 18; _count++) {
		set_bkg_tiles(_count, 7, building_background_00Width, building_background_00Height, building_background_00);
	}

	set_bkg_tiles(8, 7, soviet_symbol_bigWidth, soviet_symbol_bigHeight, soviet_symbol_big);

	reset_timer();
	show_timer();

	while (1) {
		wait_vbl_done();
		step_timer();

		if(_count % 2 == 0) {
			_player_y++;
		}

		if(joypad() & J_LEFT) {
			_player_x--;
		}

		if(joypad() & J_RIGHT) {
			_player_x++;
		}

		move_sprite(MINIGAME_SPRITE_START + 0, MIDDLE_X, _player_y);
		move_sprite(MINIGAME_SPRITE_START + 1, MIDDLE_X + 8, _player_y);
		move_sprite(MINIGAME_SPRITE_START + 2, _player_x, GAME_BUILD_TANK_GAME_TANK_BOTTOM_Y);
		move_sprite(MINIGAME_SPRITE_START + 3, _player_x + 8, GAME_BUILD_TANK_GAME_TANK_BOTTOM_Y);

		if(_player_y == GAME_BUILD_TANK_GAME_TANK_BOTTOM_Y - 8) {
			break;
		}
	}

	delay(1000);

	hide_timer();

	move_sprite(MINIGAME_SPRITE_START + 0, 0, 0);
	move_sprite(MINIGAME_SPRITE_START + 1, 0, 0);
	move_sprite(MINIGAME_SPRITE_START + 2, 0, 0);
	move_sprite(MINIGAME_SPRITE_START + 3, 0, 0);

	return _player_x >= MIDDLE_X - 4 && _player_x <= MIDDLE_X + 12;
}

#define NUMBER_OF_PROLETARIAT_GAME_04 4

BYTE start_line_waiting_game() {
	UBYTE proletariat_cords[NUMBER_OF_PROLETARIAT_GAME_04];
	UBYTE i;

	proletariat_cords[0] = MIDDLE_X_8x8 - 18;
	initialise_8x8_sprite(MINIGAME_SPRITE_START, PLAYER_SAD_FACE_TILE, proletariat_cords[0], MIDDLE_Y_8x8);

	proletariat_cords[1] = MIDDLE_X_8x8 - 32;
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 1, PLAYER_SAD_FACE_TILE, proletariat_cords[1], MIDDLE_Y_8x8);

	proletariat_cords[2] = MIDDLE_X_8x8 - 45;
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 2, PLAYER_SAD_FACE_TILE, proletariat_cords[2], MIDDLE_Y_8x8);

	proletariat_cords[3] = MIDDLE_X_8x8 + 12;
	initialise_8x8_sprite(MINIGAME_SPRITE_START + 3, PLAYER_SAD_FACE_TILE, proletariat_cords[3], MIDDLE_Y_8x8);

	reset_timer();
	show_timer();

	_player_x = MIDDLE_X_8x8;
	_player_y = MIDDLE_Y_8x8;
	player_moved();
	
	while (_count > 0) {
		wait_vbl_done();
		step_timer();

		for(i = 0; i < NUMBER_OF_PROLETARIAT_GAME_04; i++) {
			if(i == 3 && rand() % 18 == 0 || i != 3 && rand() % 15 == 0) {
				proletariat_cords[i]++;
				move_sprite(MINIGAME_SPRITE_START + i, proletariat_cords[i], MIDDLE_Y_8x8);
			}

			if(_player_x + (BYTE)8 > proletariat_cords[i] && _player_x < proletariat_cords[i] + (BYTE)8) {
				break;
			}
		}

		if(joypad() & J_RIGHT) {
			_player_x++;
			player_moved();
		}
	}

	hide_player();
	hide_timer();

	clear_sprites(MINIGAME_SPRITE_START, 4);

	return _count == 0;
}

BYTE start_launch_rocket_game() {
	BYTE success = 0;
	// used to wait for pad up without blocking
	BYTE up_last_loop = 0;

	_player_y = 66;

	reset_timer();
	show_timer();

	set_bkg_tiles(7, 11, building_00Width, building_00Height, building_00);

	initialise_space_ship_sprite(MINIGAME_SPRITE_START);
	move_16x40_sprite(MINIGAME_SPRITE_START, 85, _player_y);

	while (_count > 0) {
		wait_vbl_done();

		step_timer();

		if((joypad() & J_A) && up_last_loop) {
			up_last_loop = 0;

			_player_y -= 5;
			move_16x40_sprite(MINIGAME_SPRITE_START, 85, _player_y);

			if(_player_y % 2 == 0) {
				set_sprite_tile(MINIGAME_SPRITE_START + 5, SPACE_SHIP_BOTTOM_ON_A_TILE);
				set_sprite_tile(MINIGAME_SPRITE_START + 11, SPACE_SHIP_BOTTOM_ON_B_TILE);
			} else {
				set_sprite_tile(MINIGAME_SPRITE_START + 5, SPACE_SHIP_BOTTOM_ON_B_TILE);
				set_sprite_tile(MINIGAME_SPRITE_START + 11, SPACE_SHIP_BOTTOM_ON_A_TILE);
			}

			if(_player_y + 30 > 200) {
				success = 1;
				break;
			}
		} else if (!(joypad() & J_A) && !up_last_loop) {
			up_last_loop = 1;
		} else if(_count % 10 == 0 && _player_y < 66) {
			_player_y++;
			move_16x40_sprite(MINIGAME_SPRITE_START, 85, _player_y);
		}
	}

	hide_timer();
	clear_sprites(MINIGAME_SPRITE_START, 12);

	return success;
}

#define NUMBER_OF_PROLETARIAT_GAME_02 3 * 2

BYTE start_unite_game() {
	// 3 dudes 2 cords each
	UBYTE proletariat_cords[NUMBER_OF_PROLETARIAT_GAME_02];
	BYTE success = 0;
	BYTE i;
	BYTE controling_index = 0;

	for(i = 0; i < NUMBER_OF_PROLETARIAT_GAME_02; i += 2) {
		proletariat_cords[i] = (UBYTE)16 + (UBYTE)rand() % ((UBYTE)MAX_X - (UBYTE)16);
		proletariat_cords[i + 1] = (UBYTE)24 + (UBYTE)rand() % ((UBYTE)MAX_Y - (UBYTE)24);

		if(i == 0){
			initialise_8x8_sprite(MINIGAME_SPRITE_START + i, PLAYER_SCREAMING_SELECTED_TILE, proletariat_cords[i], proletariat_cords[i + 1]);
		} else {
			initialise_8x8_sprite(MINIGAME_SPRITE_START + i, PLAYER_SAD_FACE_TILE, proletariat_cords[i], proletariat_cords[i + 1]);
		}
	}

	set_bkg_tiles(7, 6, green_sqaureWidth, green_sqaureHeight, green_sqaure);

	reset_timer();
	show_timer();

	while (_count > 0) {
		wait_vbl_done();
		step_timer();

		if(controling_index >= 0){
			if(joypad() & J_RIGHT) {
				proletariat_cords[controling_index]++;
			}
			
			if(joypad() & J_LEFT) {
				proletariat_cords[controling_index]--;
			}

			if(joypad() & J_UP) {
				proletariat_cords[controling_index + 1]--;
			}

			if(joypad() & J_DOWN) {
				proletariat_cords[controling_index + 1]++;
			}

			move_sprite(
				MINIGAME_SPRITE_START + controling_index, 
				proletariat_cords[controling_index], 
				proletariat_cords[controling_index + 1]
			);

			if(sprite_in_green_square(proletariat_cords[controling_index], proletariat_cords[controling_index + 1])) {
				// Ensure move hitbox
				proletariat_cords[controling_index] = 0;
				proletariat_cords[controling_index + 1] = 0;

				set_sprite_tile(MINIGAME_SPRITE_START + controling_index, PLAYER_SCREAMING_FACE_TILE);

				controling_index += 2;

				if(controling_index >= NUMBER_OF_PROLETARIAT_GAME_02){
					success = 1;
					break;
				}
				else{
					set_sprite_tile(MINIGAME_SPRITE_START + controling_index, PLAYER_SCREAMING_SELECTED_TILE);
				}

			}
		} 
	}

	hide_timer();
	
	for(i = 0; i < NUMBER_OF_PROLETARIAT_GAME_02; i += 2) {
		move_sprite(MINIGAME_SPRITE_START + i, 0, 0);
	}

	return success;
}

BYTE start_shoot_game() {

	set_bkg_tiles(11, 3, building_00Width, building_00Height, building_00);

	_player_x = MIDDLE_X_8x8 - 16;
	_player_y = MIDDLE_Y_8x8;
	player_moved();

	initialise_8x8_sprite(MINIGAME_SPRITE_START, PLAYER_SAD_FACE_TILE, MIDDLE_X_8x8 - 32, MIDDLE_Y_8x8);

	initialise_8x8_sprite(MINIGAME_SPRITE_START + 1, PLAYER_SAD_FACE_TILE, MIDDLE_X_8x8, MIDDLE_Y_8x8);

	initialise_8x8_sprite(MINIGAME_SPRITE_START + 2, BULLET_TILE, 200, 200);

	reset_timer();
	show_timer();

	while (_count > 0) {
		wait_vbl_done();
		
		step_timer();

		if(joypad() & J_A) {
			// Shoot first bullet
			beep();
			while(_player_x < MIDDLE_X_8x8) {
				wait_vbl_done();
				move_sprite(MINIGAME_SPRITE_START + 2, _player_x, _player_y);
				_player_x++;
			}
			set_sprite_tile(MINIGAME_SPRITE_START + 1, 0xFF);
			move_sprite(MINIGAME_SPRITE_START + 2, 0, 0);
			delay(1000);

			// Shoot 2nd bullet
			_player_x = MIDDLE_X_8x8 - 32;
			// No idea why I can't just use _player_x here it just doesn't work
			move_sprite(MINIGAME_SPRITE_START + 2, MIDDLE_X_8x8 - 32, _player_y);
			beep();

			while(_player_x < MIDDLE_X_8x8 - 16) {
				wait_vbl_done();
				move_sprite(MINIGAME_SPRITE_START + 2, _player_x, _player_y);
				_player_x++;
			}

			hide_player();

			delay(1000);

			break;
		}
	}

	hide_timer();
	hide_player();

	move_sprite(MINIGAME_SPRITE_START, 0, 0);
	move_sprite(MINIGAME_SPRITE_START + 1, 0, 0);
	move_sprite(MINIGAME_SPRITE_START + 2, 0, 0);

	return _count;
}

BYTE start_find_food_game() {
	_player_x = MIDDLE_X_8x8;
	_player_y = MIDDLE_Y_8x8;

	player_moved();

	reset_timer();
	show_timer();

	while (_count > 0) {
		wait_vbl_done();
		process_movement();

		step_timer();
	}

	hide_timer();
	hide_player();

	return 1;
}

void start_minigame_title(const char* text, UBYTE n) {
	UWORD i, j;

	set_bkg_tiles(0, 0, mingame_title_mapWidth, mingame_title_mapHeight, mingame_title_map);
	
	print_text(MINIGAME_SPRITE_START, text, n, MIDDLE_X - ((n / 2) * 8), MIDDLE_Y);
	print_UWORD_number(MINIGAME_SPRITE_START + n, MIDDLE_X - ((n / 2) * 8), 10, 10);

	SHOW_BKG;

	for(i = 0; i < TITLE_TEXT_DISPLAY_TIME; i++) {
		for(j = 0; j < n; j++) {
			if(i % 10 == 0) {
				set_sprite_tile(MINIGAME_SPRITE_START + j, 0xFF);
			} else {
				set_sprite_tile(MINIGAME_SPRITE_START + j, get_tile_for_char(text[j]));
			}
		}
		wait_vbl_done();
	}

	clear_sprites(MINIGAME_SPRITE_START, n);
}

void play_game() {
	UBYTE i;
	UBYTE j;
	UBYTE t;
	UBYTE minigame_order[NUMBER_OF_MINIGAMES];

	for(i = 0; i < NUMBER_OF_MINIGAMES; i++) {
		minigame_order[i] = i;
	}

	// Shuffle minigame
	for (i = 0; i < NUMBER_OF_MINIGAMES - 1; i++) {
		j = (UBYTE)rand();
		j = i + (j / ((UBYTE)255 / ((UBYTE)NUMBER_OF_MINIGAMES - (UBYTE)i) + (UBYTE)1));
		t = minigame_order[j];
		minigame_order[j] = minigame_order[i];
		minigame_order[i] = t;
	}

	i = 0;

	_player_x = 200;
	_player_y = 200;
	_health = MAX_HEALTH;

	initialise_8x8_sprite(PLAYER_SPRITE, PLAYER_PLAIN_FACE_TILE, _player_x, _player_y);

	while(1) {
		wait_vbl_done();

		game_success();

		_next_minigame = minigame_order[i];
		i++;

		switch (_next_minigame) {
			case 0:
#ifdef CLEAN
				start_minigame_title("WALK", 4);
#else
				start_minigame_title("EAT", 3);
#endif
				t = start_find_food_game();
				break;
			case 1:
				start_minigame_title("SHOOT", 5);
				t = start_shoot_game();
				break;
			case 2:
				start_minigame_title("UNITE", 5);
				t = start_unite_game();
				break;
			case 3:
				start_minigame_title("LAUNCH", 6);
				t = start_launch_rocket_game();
				break;
			case 4:
				start_minigame_title("LINE", 4);
				t = start_line_waiting_game();
				break;
			case 5:
				start_minigame_title("ARM", 3);
				t = start_build_tank_game();
				break;
			case 6:
				start_minigame_title("RAISE", 5);
				t = start_raise_flag_game();
				break;
			case 7:
				start_minigame_title("NUKE", 4);
				t = start_fire_missle_game();
				break;
			case 8:
				start_minigame_title("BUILD", 5);
				t = start_block_game();
				break;
			case 9:
				start_minigame_title("BOARD", 5);
				t = start_subway_game();
				break;
			case 10:
				start_minigame_title("ENTER", 5);
				t = start_enter_building_game();
				break;
			case 11:
#ifdef CLEAN
				start_minigame_title("LIE", 3);
#else
				start_minigame_title("TRUTH", 5);
#endif
				t = start_lie_game();
				break;
			case 12:
				start_minigame_title("VOTE", 4);
				t = start_vote_game();
				break;
			case 13:
#ifdef CLEAN
				start_minigame_title("FIX", 3);
#else
				start_minigame_title("CENSOR", 6);
#endif
				t = start_censor_game();
				break;
			case 14:
				start_minigame_title("BUY", 3);
				t = start_buy_car_game();
				break;
			default:
				start_minigame_title("HEALTH", 6);
				t = start_health_care_game();
				break;
		}

		if(t) {
			minigame_success();
		} else {
			minigame_fail();
		}

		if(_health <= 0) {
			game_over();
			break;
		}

		// Am i an idiot?
		if(i > NUMBER_OF_MINIGAMES - 1) {
			game_success();
			break;
		}
	}
}

void main_menu() {
	UWORD seed = 0;

	set_bkg_tiles(0, 0, game_title_mapWidth, game_title_mapHeight, game_title_map);

	SHOW_BKG;

	// uses the timing of the player pressing the a button to get the seed
	while (1) {
		seed++;

		if(joypad() & J_A) {
			initrand(seed);
			waitpadup();
			play_game();
			set_bkg_tiles(0, 0, game_title_mapWidth, game_title_mapHeight, game_title_map);
		}
	}
	
}

void initalise_game() {
	set_bkg_data(0, 126, minigames_0);
	set_sprite_data(0, 127, minigames_0);

	SPRITES_8x8;
	DISPLAY_ON;
	SHOW_SPRITES;
}

void initialise_sound() {
	NR50_REG = 0xFF;
	NR51_REG = 0xFF;
	NR52_REG = 0x80;
}

void main() {
	initialise_sound();
	initalise_game();

	main_menu();
}
