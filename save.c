
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

map* load_map(char *filename)
{
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

	fclose(f);

	return m;
}

void unload_map(map* m)
{
	free(m->data);
	free(m);
}





