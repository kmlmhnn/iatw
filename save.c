#include "player.h"
#include "display.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

map* load_map(int file_no)
{
	char filename[16];
	sprintf(filename, "map.%d", file_no);
	FILE* f = fopen(filename, "r");
	map* m = malloc(sizeof(map));
	int *d;
	
	fscanf(f, "%d %d", &(m->width), &(m->height));
	fscanf(f, "%d %d", &(m->vp_x), &(m->vp_y));
	fscanf(f, "%d %d", &(m->player_x), &(m->player_y));

	d = malloc(sizeof(int) * m->width * m->height);

	int ch, *p;
	p = d;
	while((ch = fgetc(f)) != EOF){
		if(ch != '\n'){
			*p = ch;
			p++;
		}
	}

	m->data = d;
	m->no = file_no;

	fclose(f);

	return m;
}

void unload_map(map* m)
{
	free(m->data);
	free(m);
}

void load_everything_from_file(map** m, viewport* vp)
{
	int map_no;
	FILE* f = fopen("carcass", "r");
	fscanf(f, "%d", &map_no);
	*m = load_map(map_no);

	fscanf(f, "%d %d %d %d %d", &player.x, &player.y, &player.hp,
			&player.str, &player.sigil);

	fscanf(f, "%d %d", &vp->x, &vp->y);

	vp->width = COLS;
	vp->height = LINES;


	fclose(f);
}

void save_everything_to_file(map* m, viewport* vp)
{
	FILE *f = fopen("carcass", "w");	
	
	fprintf(f, "%d\n", m->no);

	fprintf(f, "%d %d %d %d %d\n", player.x, player.y, player.hp, 
			player.str, player.sigil);

	fprintf(f, "%d %d\n", vp->x, vp->y);

	fclose(f);

}

