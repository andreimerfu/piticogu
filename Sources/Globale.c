#include "SDL/SDL.h"
#include "Globale.h"

//Globale
int LEVEL_HEIGHT = 0;
int LEVEL_WIDTH = 0;

int PLAYER_X_SPEED = 0;

//Suprafete
SDL_Surface * screen = NULL;
SDL_Surface * s_dark_block = NULL;
SDL_Surface * s_bleu = NULL;

//Game states
int statID = STAT_NULL;
int nextStat = STAT_NULL;
statutjoc c,*tt;
menu m;
titlu t;
reguli r;
joc j;
SDL_Event event;
pct *p_arr;
int care_muta;
int joc_incarcat;
pitic p1,p2;
int pxl3=0;
int dx,dy, e2,start_mers,x0,sx,sy;
/*SDL_Rect rcSrc, rcSrc2, rcSprite, rcSprite2;*/

