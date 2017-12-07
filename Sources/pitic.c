#include "pitic.h"
#include "functii.h"
#include "Globale.h"
void pitic_handle_events(pitic *s) {
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_RIGHT:
			s->ix += 5;
			muta_X(s);
			break;
		case SDLK_LEFT: 
			s->ix -= 5;
			muta__X(s);
			break;
		case SDLK_UP: 
			s->iy -= 5;
			muta__Y(s);
			break;
		case SDLK_DOWN: 
			s->iy += 5;
			muta_Y(s);
			break;
		case SDLK_SPACE: 

			break;
		}
	}
	if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT){
       
		if (statID == STAT_GAME){
			int x, y;
			SDL_GetMouseState(&x, &y);
			/*SDL_Rect mouse = { x, y, 5, 5 };*/
			p1.box.x = x;
			p1.box.y = y;
			p1.can_move = 1;
			start_mers = 1;
		}
	}
	
}
void pitic_handle_events2(pitic *s) {
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_d:
			s->ix += 5;
			muta_X(s);
			break;
		case SDLK_a:
			s->ix -= 5;
			muta__X(s);
			break;
		case SDLK_w:
			s->iy -= 5;
			muta__Y(s);
			break;
		case SDLK_s:
			s->iy += 5;
			muta_Y(s);
			break;
		case SDLK_SPACE:

			break;
		}
	}
		if (event.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_RIGHT)
		{

			if (statID == STAT_GAME){
				int x, y;
				SDL_GetMouseState(&x, &y);
				/*SDL_Rect mouse = { x, y, 5, 5 };*/
				p2.box.x = x;
				p2.box.y = y;
				p2.can_move = 1;
				start_mers = 1;
			}
		}
	
}

static pitic_vtbl the_pitic_vtbl = { // used to be static 
	pitic_handle_events/*,
	pitic_logic,
	pitic_render*/
};
void pitic_construct(pitic *s, char * file) {
	s->vptr = &the_pitic_vtbl;
	s->s_pitic = load_image(file); //sprite, pitic bmp image
	/* set animation frame */
	s->rcSrc.x = 128;
	s->rcSrc.y = 0;
	s->rcSrc.w = SPRITE_SIZE;
	s->rcSrc.h = SPRITE_SIZE;
	s->rcSrc.h = SPRITE_SIZE;
	s->can_move = 0;
	/*s->ix = 75;
	s->iy = 555;*/
}

void pitic_construct2(pitic *s, char * file) {
	s->vptr = &the_pitic_vtbl;
	s->s_pitic = load_image(file); //sprite, pitic bmp image
	/* set animation frame */
	s->rcSrc.x = 128;
	s->rcSrc.y = 0;
	s->rcSrc.w = SPRITE_SIZE;
	s->rcSrc.h = SPRITE_SIZE;
	s->rcSrc.h = SPRITE_SIZE;
	s->can_move = 0;
	/*s->ix = 75;
	s->iy = 535;*/
}

void set_position(int x, int y, pitic *p)
{
	p->box.x = x;
	p->box.y = y;
}
void muta_X(pitic *p){  /*dreapta*/
	if (p->rcSrc.x == 64)
		p->rcSrc.x = 96;
	else
		p->rcSrc.x = 64;
/*	p->box.x += ix; */
	/*rcSprite.x += 5; viteza*/
}
void muta__X(pitic *p){ /*stanga*/
	if (p->rcSrc.x == 192)
		p->rcSrc.x = 224;
	else
		p->rcSrc.x = 192;
	/*p->box.x -= ix;*/
	/*rcSprite.x -= 5;*/
}
void muta_Y(pitic *p){ /*jos pe axa Y sens pozitiv*/
	if (p->rcSrc.x == 128)
		p->rcSrc.x = 160;
	else
		p->rcSrc.x = 128;
	/*rcSprite.y += 5;*/
}
void muta__Y(pitic *p){ /*sus pe axa Y sens negativ*/
	if (p->rcSrc.x == 0)
		p->rcSrc.x = 32;
	else
		p->rcSrc.x = 0;
	/*rcSprite.y -= 5;*/
}
/*void gotoxy(int x,int y, pitic *p){
Bresenham's line algorithm */
/*void linie(/*int *x0, int *y0, int *x1, int *y1, int *merge, pitic *p) {
    if (start_mers && p->can_move){
		x0=p->ix;
		y0=p->iy;
		dx = abs(p->box.x-p->ix); 
		sx = p->ix<p->box.x ? 1 : -1;
		dy = abs(p->box.y-p->iy); 
		sy = p->iy<p->box.y ? 1 : -1; 
		err = (dx>dy ? dx : -dy)/2;
		start_mers=0;
	}
	
	pxl3++;
	if (p->can_move)
		{
			if (pxl3 % 5 == 0){
				p->ix=x0;
				p->iy=y0;
				if (dx > dy)
					if (p->box.x>p->ix) 
						muta_X(p);
					else 
						muta__X(p);
				else
					if (p->box.y>p->iy) 
						muta_Y(p);
					else 
						muta__Y(p);
					}
			if (x0==p->box.x && y0==p->box.y){
				pxl3=0; 
				p->can_move=0;
				p->ix=x0;
				p->iy=y0;
			}
			e2 = err;
			if (e2 >-dx) { err -= dy; x0 += sx; }
			if (e2 < dy) { err += dx; y0 += sy; }
	}*/
		void linie(/*int *x0, int *y0, int *x1, int *y1, int *merge,*/ pitic *p) {
			if (start_mers){
				x0 = p->ix;
				y0 = p->iy;
				dx = abs(p->box.x - p->ix);
				sx = p->ix<p->box.x ? 1 : -1;
				dy = abs(p->box.y - p->iy);
				sy = p->iy<p->box.y ? 1 : -1;
				err = (dx>dy ? dx : -dy) / 2;
				start_mers = 0;
			}
			pxl3++;
			while ((pxl3 % 5) && (p->can_move)) {
				pxl3++;
				if (x0 == p->box.x && y0 == p->box.y){
					pxl3 = 0;
					p->can_move = 0;
					p->ix = x0;
					p->iy = y0;
					break;
				}
				e2 = err;
				if (e2 >-dx) { err -= dy; x0 += sx; }
				if (e2 < dy) { err += dx; y0 += sy; }
			}
			p->ix = x0;
			p->iy = y0;
			if (dx > dy)
			if (p->box.x>p->ix)
				muta_X(p);
			else
				muta__X(p);
			else
			if (p->box.y>p->iy)
				muta_Y(p);
			else
				muta__Y(p);
		}

