#include "zar.h"
#include "functii.h"
#include "Globale.h"
#include "joc.h"
void zar_handle_events(zar *s) {
	
}

static zar_vtbl the_zar_vtbl = { // used to be static 
	zar_handle_events/*,
	zar_logic,
	zar_render*/
};
void zar_construct(zar *s, char * file) {
	s->vptr = &the_zar_vtbl;
	s->s_zar = load_image(file); //sprite, zar bmp image
	/* set animation frame */
	s->ix = 740;
	s->iy = 560;
}

