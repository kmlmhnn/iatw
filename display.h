#ifndef DISPLAY_H
#define DISPLAY_H

#include <ncurses.h>
#include <stdio.h>
#include "creature.h"
#include "map.h"

typedef struct {
	int x;
	int y;
	int width;
	int height;
} viewport;


void init_viewport_from_map(viewport*, map*);
void print_msg(char* debug_msg, creature* c);
void print_status();
void init_display();
void show_title();
void cleanup_display();
void show_creature(creature* c, viewport* v);
void show_map(map* m, viewport* v);
void show_player(viewport* vp);
void init_player_from_map(map* m);
#endif
