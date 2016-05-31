#ifndef MAP_H
#define MAP_H

typedef struct {
	int* data;	// 1d array of map data
	int width;
	int height;

	// Top left of the viewport will be placed in (vp_x, vp_y)
	// when this map is first loaded.
	// These values can be -ve when the topleft of the viewport lies outside
	// the map.
	// Since vp_x and vp_y are specified wrt the top left
	// of the map. ie, the top left of the map is taken as the Origin.
	int vp_x;
	int vp_y;

	// The player is placed here when the map loads.
	// Must be > 0, since they too are specified wrt the topleft of the map.
	int player_x;
	int player_y;
} map;



#endif
