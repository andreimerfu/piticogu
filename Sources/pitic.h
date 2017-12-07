#ifndef PITIC_H_INCLUDED
#define PITIC_H_INCLUDED
#include "SDL/SDL.h"
typedef struct pitic pitic;

typedef struct pitic_vtbl pitic_vtbl;

struct pitic_vtbl {
	void(*handle_events)(pitic *s);
	/*void(*logic)(pitic *s);
	void(*render)(pitic const *s);*/
};

struct pitic {
	pitic_vtbl * vptr;
	SDL_Surface * s_pitic;
	SDL_Rect box;
	int i_direction;
	int i_state;
	int nr;
	int ix, iy;
	int can_move;
	SDL_Rect rcSrc;
};

void pitic_construct(pitic *s, char * file);

void pitic_handle_events(pitic const *s);
/*void pitic_logic(pitic *s);
void pitic_render(pitic const *s);
*/
void set_position(int x, int y, pitic *p);
void muta_X(pitic *p);  /*+X*/
void muta__X(pitic *p); /*-X*/
void muta_Y(pitic *p);  /*+Y*/
void muta__Y(pitic *p); /*-Y*/
void linie(/*int *x0, int *y0, int *x1, int *y1, int *merge,*/ pitic *p);
#endif
