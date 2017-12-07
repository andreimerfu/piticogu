#include "titlu.h"
#include "Globale.h"
#include "functii.h"
void titlu_handle_events(titlu const *s) {
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYUP)
		{
			next_state(STAT_MENU);
		}

		if (event.type == SDL_QUIT)
		{
			next_state(STAT_EXIT);
		}
	}
}

void titlu_logic(titlu *s) {
	{
		s->titleA++;
		s->titleA++;
		s->titleA++;

		if (s->titleA > 250)
		{
			s->titleA = 250;
		}

		SDL_SetAlpha(s->title, SDL_SRCALPHA, s->titleA);
	}
	
}

void titlu_render(titlu const *s) {
	apply_surface(0, 0, s_bleu, screen, NULL);
	apply_surface(0, 0, s->title, screen, NULL);

	SDL_Flip(screen);
}
static titlu_vtbl the_titlu_vtbl = { // used to be static 
	titlu_handle_events,
	titlu_logic,
	titlu_render
};
void titlu_construct(titlu *s) {
	s->vptr = &the_titlu_vtbl;
	s->title = load_image("titlu.bmp");
	apply_surface(0, 0, s_bleu, screen, NULL);
	s->time = SDL_GetTicks();
	s->titleA = 0;
}
