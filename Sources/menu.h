#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "SDL/SDL.h"
typedef struct menu menu;

typedef struct menu_vtbl menu_vtbl;

struct menu_vtbl {
	void(*handle_events)(menu const *s);
	void(*logic)(menu *s);
	void(*render)(menu const *s);
};

struct menu {
	menu_vtbl * vptr;
	SDL_Surface * s_menu;
	int titleA;
	SDL_Rect joaca, exit, conf, reguli ;
};

void menu_construct(menu *s);

void menu_handle_events(menu const *s);
void menu_logic(menu *s);
void menu_render(menu const *s);

#endif

