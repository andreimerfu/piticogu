#ifndef STATUTJOC_H_INCLUDED
#define STATUTJOC_H_INCLUDED

typedef struct statutjoc statutjoc;

typedef struct statutjoc_vtbl statutjoc_vtbl;

struct statutjoc_vtbl {
	void(*handle_events)(statutjoc const *s);
	void(*logic)(statutjoc const *s);
	void(*render)(statutjoc const *s);
};

struct statutjoc {
	statutjoc_vtbl *vptr;
};

void statutjoc_construct(statutjoc *s);

void statutjoc_handle_events(statutjoc const *s);
void statutjoc_logic(statutjoc const *s);
void statutjoc_render(statutjoc const *s);

#endif

