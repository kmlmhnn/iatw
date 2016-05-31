#include "display.h"
#include <ncurses.h>
#include <stdlib.h>
#include "creature.h"
#include "map.h"
#include "player.h"

void print_msg(char* debug_string, creature* c)
{
	if(debug_string != NULL){
		mvprintw(LINES - 2, 0, debug_string);
		refresh();
	} else{
		mvprintw(LINES - 2, 0, "%d %d", c->x, c->y);
	}
}

void print_status(creature* c)
{
	mvprintw(LINES - 1, 0, "hp: %d str %d ", c->hp, c->str);
}

void init_display()
{
	initscr();	// Start ncurses.
	refresh();

	cbreak();	// Get keypresses without enter.
	keypad(stdscr, TRUE);	// Get special keys too.
	noecho();

}

void show_title()
{
	printw( "Press any key to start ...");
	curs_set(0);
	refresh();
}

void show_creature(creature* c, viewport* vp)
{
		mvaddch(-1*vp->y + c->y, -1*vp->x + c->x, c->sigil);
}
void show_player(viewport* vp)
{
		mvaddch(-1*vp->y + player.y, -1*vp->x + player.x, player.sigil);
}
void cleanup_display()
{
	nocbreak();
	echo();
	endwin();
}

void init_viewport_from_map(viewport* v, map* m)
{
	v->width = COLS;
	v->height = LINES;
	v->x = m->vp_x;
	v->y = m->vp_y;

}

void init_player_from_map(map* m)
{
	player.x = m->player_x;
	player.y = m->player_y;
	player.hp = player.str = 10;
	player.sigil = '@';

}

void show_map(map* m, viewport* v)
{
	int* ch = m->data;
	move(0, 0);
	int x, y;
	for(y = v->y; y < v->y + v->height; y++){
		for(x = v->x; x < v->x + v->width; x++){
			if(x >= 0 && x < m->width && y >= 0 && y < m->height){
				addch(ch[y * m->width + x]);
			} else {
				addch(' ');
			}
		}
		
	}
}

