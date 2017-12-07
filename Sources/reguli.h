#ifndef REGULI_H_INCLUDED
#define REGULI_H_INCLUDED
#include "SDL/SDL.h"
typedef struct reguli reguli;

typedef struct reguli_vtbl reguli_vtbl;

struct reguli_vtbl {
	void(*handle_events)(reguli const *s);
	void(*logic)(reguli *s);
	void(*render)(reguli const *s);
};

struct reguli {
	reguli_vtbl *vptr;
	SDL_Surface * s_reguli;
	int alfa;
};

void reguli_construct(reguli *s);

void reguli_handle_events(reguli const *s);
void reguli_logic(reguli *s);
void reguli_render(reguli const *s);

#endif

