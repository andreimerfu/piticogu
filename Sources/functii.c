#include "Globale.h"
#include "functii.h"
void readp_ints (pct *p_puncte, int num, const char* file_name);

int init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return 0;
	}

	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SPRITE_SIZE, SDL_SWSURFACE /*|SDL_FULLSCREEN*/);

	if (screen == NULL)
	{
		return 0;
	}


	SDL_WM_SetCaption("Piticot", "SDL");

	return 1;
}

int check_collision(SDL_Rect A, SDL_Rect B)
{
	if (A.x >= B.x + B.w)
	{
		return 0;
	}

	if (A.x + A.w <= B.x)
	{
		return 0;
	}

	if (A.y >= B.y + B.h)
	{
		return 0;
	}

	if (A.y + A.h <= B.y)
	{
		return 0;
	}

	return 1;
}

SDL_Surface * load_image(char *file)
{
	SDL_Surface * load = NULL; SDL_Surface * opt = NULL;

	load = SDL_LoadBMP(file);

	if (load != NULL)
	{
		opt = SDL_DisplayFormat(load);

		SDL_FreeSurface(load);

		if (opt != NULL)
		{
			SDL_SetColorKey(opt, SDL_SRCCOLORKEY, SDL_MapRGB(opt->format, 0xFF, 0, 0xFF));

		}
	}

	return opt;
}

void apply_surface(int x, int y, SDL_Surface * src, SDL_Surface * dst, SDL_Rect * clip)
{
	SDL_Rect offset;
	offset.x = x; offset.y = y;

	SDL_BlitSurface(src, clip, dst, &offset);
}

void next_state(int newstate)
{
	if (nextStat != STAT_EXIT)
	{
		nextStat = newstate;
	}
}
void change_state()
{ int next_start, next;
	if (nextStat != STAT_NULL)
	{
		switch (nextStat)
		{
		case STAT_GAME:
		{
			joc_construct(&j);
			c.vptr = j.vptr;
			tt = &j;
			//currentState = new Game();
			break;
		}

		case STAT_MENU:
		{
			menu_construct(&m);
			c.vptr = m.vptr;
			tt = &m;
			//currentState = new Menu();
			break;
		}

		case STAT_REGULI:
		{
			reguli_construct(&r);
			c.vptr = r.vptr;
			tt = &r;

			//currentState = new Help();
			break;
		}

		}

		statID = nextStat;

		nextStat = STAT_NULL;

		
		next_start = SDL_GetTicks();
		next = next_start;
		while (next < 2000)
		{
			next = SDL_GetTicks() - next_start;
			apply_surface(rand() % 820 - 50, rand() % 620 - 50, s_dark_block, screen, NULL);
			SDL_Flip(screen);
		}
	}
}
int load_files()
{
	s_dark_block = load_image("bleu50.png");
	s_bleu = load_image("bleu8.png");
	return 1;
}

void readp_ints (pct *p_puncte, int num, const char* file_name)
{ int i = 0, value;
  FILE* fp = fopen (file_name, "r");
  if (fp == NULL) {
	  // assume that Error is some error function that handles the error, maybe
		// printing out the passed error string and calling exit(1);
		printf("Unable to open file. %s",file_name); 
		return;
	}
   while (!feof (fp) && i++ <= num )
   {
	   fscanf (fp, "%d", &value); 
       p_puncte[i].no = value;
	   fscanf (fp, "%d", &value);
       p_puncte[i].x = value;
       fscanf (fp, "%d", &value);
       p_puncte[i].y = value;
   }
  fclose (fp);        
}

void incarca_vars(const char* file_name){
int value;
	FILE* fp = fopen (file_name, "r");
  if (fp == NULL) {
	  // assume that Error is some error function that handles the error, maybe
		// printing out the passed error string and calling exit(1);
		printf("Unable to open file. %s",file_name);
		return;
	}
while (!feof (fp) )
   {
	   fscanf (fp, "%d", &value); 
	   p1.nr = value;
	   fscanf (fp, "%d", &value);
       p2.nr = value;
	   fscanf (fp, "%d", &value);
       care_muta = value;
    }
  fclose (fp);   
  joc_incarcat++;
}

void salvare_vars(const char* file_name){
FILE* fp = fopen (file_name, "w");
  if (fp == NULL) {
	  // assume that Error is some error function that handles the error, maybe
		// printing out the passed error string and calling exit(1);
		printf("Unable to write to file %s",file_name);
  }
  fprintf(fp,"%d %d %d %d %d",p1.ix,p1.iy,p2.ix,p2.iy,care_muta);
  fclose (fp);  
}

