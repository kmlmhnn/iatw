#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <ncurses.h>
#include "display.h"
#include "map.h"
#include "player.h"
#include "save.h"

int main()
{
	viewport vp;
	map *m1 = NULL;

	init_display();

	// Try to open save file
	struct stat st;
	if(stat("carcass", &st) != 0){
		m1 = load_map(0);
		init_viewport_from_map(&vp, m1);
		init_player_from_map(m1);
	} else {
		load_everything_from_file(&m1, &vp);
	}

	// save_everything_to_file(m1, &vp); 

	show_title();

	int ch = getch();
	
	while(ch != 'Q')
	{
		curs_set(0);
		clear();

		switch(ch){
			case KEY_LEFT:	move_player(LEFT, m1, &vp); break;
			case KEY_RIGHT: move_player(RIGHT, m1, &vp); break;
			case KEY_UP:	move_player(UP, m1, &vp); break;
			case KEY_DOWN:	move_player(DOWN, m1, &vp); break;

			case 'S'	:	save_everything_to_file(m1, &vp); break;
		}


		show_map(m1, &vp);
		show_player(&vp);

		print_status(&player);
		print_msg(NULL, &player);

		refresh();
		ch = getch();
	} 

	unload_map(m1);
	cleanup_display();
		


	return 0;
}
