#include <stdio.h>
#include <ncurses.h>
#include "display.h"
#include "map.h"
#include "player.h"

int main()
{
	int mapdata[] = {
		'x', 'x', 'x', 'x', 'x', 'x', 'x', 
		'x', '.', '.', 'x', '.', '.', 'x',
		'x', '.', '.', 'x', '.', '.', 'x', 
		'x', '.', '.', 'x', '.', '.', 'x',
		'x', '.', '.', 'x', '.', '.', 'x',
		'x', '.', '.', 'x', '.', '.', 'x',
		'x', '.', '.', 'x', '.', '.', 'x',
		'x', '.', '.', 'x', '.', '.', 'x',
		'x', '.', '.', 'x', '.', '.', 'x',
		'x', '.', '.', 'x', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', 'x', 'x', 'x', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', 'x', 'x', 'x', 'x', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', '.', '.', '.', '.', '.', 'x',
		'x', 'x', '.', '.', '.', '.', 'x',
		'x', 'x', 'x', 'x', 'x', 'x', 'x'
	};

	viewport vp;
	map m1;
	m1.width = 7;
	m1.height = 27;
	m1.vp_x = -20;
	m1.vp_y = -15;
	m1.player_x = 2;
	m1.player_y = 3;
	m1.data = mapdata;


	init_display();

	init_viewport_from_map(&vp, &m1);
	init_player_from_map(&m1);


	show_title();

	int ch;
	
	while((ch = getch()) != 'q')
	{
		curs_set(0);
		clear();

		switch(ch){
			case KEY_LEFT:	move_player(LEFT, &m1, &vp); break;
			case KEY_RIGHT: move_player(RIGHT, &m1, &vp); break;
			case KEY_UP:	move_player(UP, &m1, &vp); break;
			case KEY_DOWN:	move_player(DOWN, &m1, &vp); break;
		}


		show_map(&m1, &vp);
		show_player(&vp);

		print_status(&player);
		print_msg(NULL, &player);

		refresh();
	} 
	cleanup_display();
		


	return 0;
}
