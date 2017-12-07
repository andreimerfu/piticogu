#include "statutjoc.h"

void statutjoc_handle_events(statutjoc const *s) {
	/* compute and return something not used*/;
}

void statutjoc_logic(statutjoc const *s) {
	/* compute and return something not used*/;
}

void statutjoc_render(statutjoc const *s) {
	/* compute and return something not used*/;
}

static statutjoc_vtbl the_statutjoc_vtbl = { // used to be static 
	statutjoc_handle_events,
	statutjoc_logic,
	statutjoc_render
}; 
void statutjoc_construct(statutjoc *s) {
	s->vptr = &the_statutjoc_vtbl;
}  
