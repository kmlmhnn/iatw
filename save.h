#ifndef SAVE_H
#define SAVE_H

#include "map.h"
#include "display.h"

map* load_map(char *filename);
void unload_map(map*);
void load_everything_from_file(map** m, viewport* vp);
void save_everything_to_file(map* m, viewport* vp);

#endif
