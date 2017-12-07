#include "menu.h"
#include "functii.h"
#include "Globale.h"
void menu_handle_events(menu const *s) {
	int x, y;
	SDL_Rect mouse;/* = { x, y, 5, 5 };*/
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT)
			{
				

				SDL_GetMouseState(&x, &y);

				mouse.x=x;
                mouse.y=y;
				mouse.h=5;
				mouse.w=5;

				if (check_collision(s->reguli, mouse) == 1)
				{
					next_state(STAT_REGULI);
				}
				if (check_collision(s->joaca, mouse) == 1)
				{
					next_state(STAT_GAME);
				}

				if (check_collision(s->exit, mouse) == 1)
				{
					next_state(STAT_EXIT);
				}

				/*if (check_collision(s->level, mouse) == true)
				{
					next_state(STATE_LEVEL_SELECT);
				}*/

			}

			if (event.type == SDL_QUIT)
			{
				next_state(STAT_EXIT);
			}

			/*if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_s)
			{
				if (Mix_PlayingMusic() == 1)
				{
					Mix_HaltMusic();
				}

				else
				{
					Mix_PlayMusic(music, -1);
				}
			}*/
		}
	}
}

void menu_logic(menu *s) {
		s->titleA++;
		s->titleA++;
		s->titleA++;

		if (s->titleA > 250)
		{
			s->titleA = 250;
		}
		SDL_SetAlpha(s->s_menu, SDL_SRCALPHA, s->titleA);
		/*effect speciale fade*/
}

void menu_render(menu const *s) {
	apply_surface(0, 0, s_bleu, screen, NULL);
	apply_surface(0, 0, s->s_menu, screen, NULL);

	SDL_Flip(screen);
}

static menu_vtbl the_menu_vtbl = { // used to be static 
	menu_handle_events,
	menu_logic,
	menu_render
};
void menu_construct(menu *s) {
	s->vptr = &the_menu_vtbl;
	s->s_menu = load_image("menu.bmp");
	s->titleA = 1;
	s->reguli.x = 210; s->reguli.y = 310; s->reguli.w = 630 - 210; s->reguli.h = 390 - 310;
	s->joaca.x = 210; s->joaca.y = 390; s->joaca.w = 630 - 210; s->joaca.h = 470 - 310;
	s->conf.x = 210; s->exit.y = 470; s->exit.w = 630 - 210; s->exit.h = 550 - 470;
	s->exit.x = 210; s->exit.y = 550; s->exit.w = 630 - 210; s->exit.h = 640 - 550;
	
}


