#include "lvl.h"
#include "functii.h"
#include "Globale.h"
#include "joc.h"
void lvl_handle_events(lvl *s) {
	
}

static lvl_vtbl the_lvl_vtbl = { // used to be static 
	lvl_handle_events/*,
	lvl_logic,
	lvl_render*/
};
void lvl_construct(lvl *s, char * file) {
	s->vptr = &the_lvl_vtbl;
	s->s_lvl = load_image(file); //sprite, lvl bmp image
	/* set animation frame */
	s->ix = 360;
	s->iy = 630;
}

