#ifndef SAVE_H
#define SAVE_H

#include "map.h"

map* load_map(char *filename);
void unload_map(map*);

#endif
