#ifndef CREATURE_H
#define CREATURE_H

#include "creature.h"

// Directions a creature can move
typedef enum {LEFT, RIGHT, UP, DOWN} direction;

typedef struct {
	int x;
	int y;
	int hp;
	int str;
	int sigil;
} creature;
	

#endif
