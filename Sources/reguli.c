#include "reguli.h"
#include "Globale.h"
#include "functii.h"
void reguli_handle_events(reguli const *s) {
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYUP)
		{
			next_state(STAT_GAME);
		}

		if (event.type == SDL_QUIT)
		{
			next_state(STAT_EXIT);
		}

		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
		{
			next_state(STAT_MENU);
		}
	}
}

void reguli_logic(reguli *s) {
	s->alfa++;
	s->alfa++;
	s->alfa++;

	if (s->alfa > 250)
	{
		s->alfa = 250;
	}

	SDL_SetAlpha(s->s_reguli, SDL_SRCALPHA, s->alfa);
}

void reguli_render(reguli const *s) {
	apply_surface(0, 0, s_bleu, screen, NULL);
	apply_surface(0, 0, s->s_reguli, screen, NULL);

	SDL_Flip(screen);
}
static reguli_vtbl the_reguli_vtbl = { // used to be static 
	reguli_handle_events,
	reguli_logic,
	reguli_render
};
void reguli_construct(reguli *s) {
	s->vptr = &the_reguli_vtbl;
	s->s_reguli=load_image("reguli.bmp");
	//apply_surface(0, 0, s_bleu, screen, NULL);
	s->alfa = 0;
}
