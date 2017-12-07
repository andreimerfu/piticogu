#ifndef ZAR_H_INCLUDED
#define ZAR_H_INCLUDED
#include "SDL/SDL.h"
typedef struct zar zar;

typedef struct zar_vtbl zar_vtbl;

struct zar_vtbl {
	void(*handle_events)(zar const *s);
	/*void(*logic)(zar *s);
	void(*render)(zar const *s);*/
};

struct zar {
	zar_vtbl * vptr;
	SDL_Surface * s_zar;
	SDL_Rect box;
	int i_direction;
	int i_state;
	int ix, iy;
	int can_move;
	SDL_Rect rcSrc;
	int r;
};

void zar_construct(zar *s, char * file);

void zar_handle_events(zar *s);
/*void zar_logic(zar *s);
void zar_render(zar const *s);
*/

#endif
