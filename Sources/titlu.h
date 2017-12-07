#ifndef TITLU_H_INCLUDED
#define TITLU_H_INCLUDED
#include "SDL/SDL.h"
typedef struct titlu titlu;

typedef struct titlu_vtbl titlu_vtbl;

struct titlu_vtbl {
	void(*handle_events)(titlu const *s);
	void(*logic)(titlu *s);
	void(*render)(titlu const *s);
};

struct titlu {
	titlu_vtbl *vptr;
	SDL_Surface * title;
	int time;
	int titleA;
};

void titlu_construct(titlu *s);

void titlu_handle_events(titlu const *s);
void titlu_logic(titlu *s);
void titlu_render(titlu const *s);

#endif

