#ifndef JOC_H_INCLUDED
#define JOC_H_INCLUDED
#include "SDL/SDL.h"
#include "pitic.h"
#include "zar.h"
#include "lvl.h"
typedef struct joc joc;

typedef struct joc_vtbl joc_vtbl;

struct joc_vtbl {
	void(*handle_events)(joc const *s);
	void(*logic)(joc *s);
	void(*render)(joc const *s);
};

struct joc {
	joc_vtbl *vptr;
	SDL_Surface * s_joc/*,*sprite,*sprite2*/;
	int titleA;
	/*pitic p1,p2;*/
	zar z1, z2, z3, z4, z5, z6, z7, z8, z9;
	int zr, r;
	lvl lv5, lv10,lv14,lv18,lv24,lv28,lv33,lv39,lv43,lv47,lv52,lv55,lv58,lv60,lv64,lv65;
};

void joc_construct(joc *s);

void joc_handle_events(joc const *s);
void joc_logic(joc *s);
void joc_render(joc const *s);

#endif

