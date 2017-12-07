#include "SDL/SDL.h"
#include "Globale.h"
#include "functii.h"
#include "statutjoc.h"
#include <time.h>


int main(int argc, char * args[])
{
	
	Uint32 FPS_s,FPS,delta;
	if (init() == 0)
	{
		return 1;
	}

	if (load_files() == 0)
	{
		return 1;
	}

	(pct *)p_arr = malloc(65 * sizeof(pct)); /* array of pointers of struct pct size */
	readp_ints (p_arr, 65, "numere.dat");
	/* câti pitici in joc, pozitia piticilor, care_muta, pitic_computer */
	
	incarca_vars("savegame.dat");
	p1.ix=p_arr[p1.nr].x;
	p1.iy=p_arr[p1.nr].y;
	p2.ix=p_arr[p2.nr].x;
	p2.iy=p_arr[p2.nr].y-15;
	statID = STAT_INTRO;
	
	statutjoc_construct(&c);
	titlu_construct(&t);
	//menu_construct(&m);
	//currentState->
	c.vptr = (statutjoc_vtbl *)t.vptr;
	tt = (statutjoc *)&t;
	//////LEVEL EDITOR//////// 
	/*stateID = STATE_LEVEL_EDITOR;
	currentState = new LevelEditor();*/

	//delta.start();
	delta = SDL_GetTicks();

	srand((unsigned int)time(NULL));
	
	
	/*Mix_Music *sound;
	int channel;
	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16SYS;
	int audio_channels = 2;
	int audio_buffers = 4096;
	sound = Mix_LoadMUS("meniu.wav");



	Mix_PlayMusic(sound, -1);*/


	while (statID != STAT_EXIT)
	{
		FPS_s=SDL_GetTicks();



		c.vptr->handle_events(tt);

		c.vptr->logic(tt);

		//delta.start();
		delta = SDL_GetTicks();

		c.vptr->render(tt);

		change_state();
		FPS = SDL_GetTicks()-FPS_s;

		if (FPS < (1000 / g_FPS))
		{

			SDL_Delay((1000 / g_FPS) - FPS);
		}

	}
    free(p_arr);
//	clean();
	return 0;
}