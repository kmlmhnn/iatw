#include "player.h"
#include "map.h"

void move_player(direction dir, map* m, viewport* v)
{
	switch(dir){
		case LEFT:if(m->data[player.y * m->width + (player.x - 1)] != 'x'){
					  player.x--; (v->x)--; 
				  }
				  break;
		case RIGHT: if(m->data[player.y * m->width + (player.x + 1)] != 'x'){
					  player.x++; (v->x)++; 
				  }
					break;
		case UP: if(m->data[(player.y - 1) * m->width + player.x] != 'x'){
					  player.y--; (v->y)--; 
				  }
					break;
		case DOWN: if(m->data[(player.y + 1) * m->width + player.x]!= 'x'){
					  player.y++; (v->y)++; 
				  }
				   break;
	}
}
