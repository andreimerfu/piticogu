#ifndef GLOBALE_H
#define GLOBALE_H

#include "SDL/SDL.h"
#include "statutjoc.h"
#include "titlu.h"
#include "menu.h"
#include "reguli.h"
#include "joc.h"

typedef struct pct pct;
struct pct{
	int no;
	int x, y;
};

extern int NEXT_LEVEL;
extern statutjoc c,*tt; /* statut curent */;
extern menu m;
extern titlu t;
extern reguli r;
extern joc j;
extern pct *p_arr;
extern int care_muta,joc_incarcat;
extern pitic p1,p2;
extern int pxl3;
extern int dx,dy,/*err*/ e2,start_mers,x0,/*y0*/sx,sy;
/*extern SDL_Rect rcSrc, rcSrc2, rcSprite, rcSprite2;*/

//Player saving speed
extern int PLAYER_X_SPEED;

extern int LEVEL_HEIGHT;
extern int LEVEL_WIDTH;

//Suprafete
extern SDL_Surface * screen;
extern SDL_Surface * s_dark_block;
extern SDL_Surface * s_bleu;
//Event
extern SDL_Event event;

// statut joc
extern int statID;
extern int nextStat;
// pozitie ,jucator
int x;

int poz1 = 1; 
int poz2 = 1;
int jucator = 0;
int nimereala;
enum StatutJoc
{
	STAT_NULL, STAT_INTRO, STAT_MENU, STAT_GAME, STAT_EXIT, STAT_REGULI, STAT_GOXY }; 


const int TYPE_BLOCK = 0;
const int TYPE_START_PLAYER = 1;
const int TYPE_START_SHADOW = 2;
const int TYPE_EXIT = 3;  
const int TYPE_SHADOW_BLOCK = 4;
const int TYPE_SPIKES = 5;

//Global constants
const int SCREEN_WIDTH = 854;
const int SCREEN_HEIGHT = 685;
const int SPRITE_SIZE = 32;
const int SCREEN_BPP = 32;

const int g_FPS = 90;



#endif