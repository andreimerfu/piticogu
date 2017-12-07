#ifndef lvl_H_INCLUDED
#define lvl_H_INCLUDED
#include "SDL/SDL.h"
typedef struct lvl lvl;

typedef struct lvl_vtbl lvl_vtbl;

struct lvl_vtbl {
	void(*handle_events)(lvl const *s);
	/*void(*logic)(lvl *s);
	void(*render)(lvl const *s);*/
};

struct lvl {
	lvl_vtbl * vptr;
	SDL_Surface * s_lvl;
	SDL_Rect box;
	int i_direction;
	int i_state;
	int ix, iy;
	int can_move;
	SDL_Rect rcSrc;
	int r;
};

void lvl_construct(lvl *s, char * file);

void lvl_handle_events(lvl *s);
/*void lvl_logic(lvl *s);
void lvl_render(lvl const *s);
*/

#endif
