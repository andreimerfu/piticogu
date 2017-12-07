#include "joc.h"
#include "Globale.h"
#include "functii.h"
#include "pitic.h"
//#include "SDL_mixer.h"

void joc_handle_events(joc *s) {
	//int r;		
	//int x, y;
	SDL_Rect mouse;
	if (SDL_PollEvent(&event))
	{
		pitic_handle_events(&p1);
		pitic_handle_events2(&p2);
		if (event.type == SDL_QUIT)
		{
			next_state(STAT_EXIT);
			//save_levels();
		}

		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
		{
			next_state(STAT_MENU);
			//save_levels();
		}
 		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_SPACE)
		{
			srand((unsigned)time(NULL));
			s->zr = rand() % 4+2;
			s->zr = s->zr * 9;
			srand((unsigned)time(NULL));
			s->r = rand() % 6 + 1;
		}
	}
	
}

void joc_logic(joc *s) {
	{
		if (p1.can_move)
			linie(&p1);
		if (p2.can_move)
			linie(&p2);
		if (s->zr != 0)
		s->zr--;
		else
			s->zr = 0;
		s->titleA++;
		s->titleA++;
		s->titleA++;

		if (s->titleA > 250)
		{
			s->titleA = 250;
		}

		SDL_SetAlpha(s->s_joc, SDL_SRCALPHA, s->titleA);
	}
	
}

void joc_render(joc const *s) {
	int i,j;
	pitic_handle_events(&p1);
	pitic_handle_events2(&p2);
	apply_surface(0, 0, s->s_joc, screen, NULL);
	apply_surface(p1.ix, p1.iy, p1.s_pitic, screen, &p1.rcSrc);
	apply_surface(p2.ix, p2.iy, p2.s_pitic, screen, &p2.rcSrc);
	for (i = 360; i < 390;i++)
	for (j = 570; j < 600;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
		apply_surface(s->lv5.ix, s->lv5.iy, s->lv5.s_lvl, screen, NULL);

	for (i = 655; i < 685; i++)
	for (j = 535; j < 565; j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv10.ix, s->lv10.iy, s->lv10.s_lvl, screen, NULL);
	}
	for (i = 725; i < 755;i++)
	for (j = 325; j < 355;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv14.ix, s->lv14.iy, s->lv14.s_lvl, screen, NULL);
	}
	for (i = 688; i < 718; i++)
	for (j = 160; j < 190; j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv18.ix, s->lv18.iy, s->lv18.s_lvl, screen, NULL);
	}
	for (i = 415; i < 445;i++)
	for (j = 60; j < 90; j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv24.ix, s->lv24.iy, s->lv24.s_lvl, screen, NULL);
	}
	for (i = 195; i < 225;i++)
	for (j = 90; j < 120;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv28.ix, s->lv28.iy, s->lv28.s_lvl, screen, NULL);
	}
	for (i = 75; i < 105;i++)
	for (j = 310; j < 340;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv33.ix, s->lv33.iy, s->lv33.s_lvl, screen, NULL);
	}
	for (i = 300; i < 330;i++)
	for (j = 490; j < 520;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv39.ix, s->lv39.iy, s->lv39.s_lvl, screen, NULL);
	}
	for (i = 535; i < 565;i++)
	for (j = 465; j < 495;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv43.ix, s->lv43.iy, s->lv43.s_lvl, screen, NULL);
	}
	for (i = 635; i < 665;i++)
	for (j = 300; j < 330;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv47.ix, s->lv47.iy, s->lv47.s_lvl, screen, NULL);
	}
	for (i = 435; i < 465;i++)
	for (j = 180; j < 210;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv52.ix, s->lv52.iy, s->lv52.s_lvl, screen, NULL);
	}
	for (i = 150; i < 180;i++)
	for (j = 320; j < 350;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv58.ix, s->lv58.iy, s->lv58.s_lvl, screen, NULL);
	}
	for (i = 315; i < 345;i++)
	for (j = 340; j < 370;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv60.ix, s->lv60.iy, s->lv60.s_lvl, screen, NULL);
	}
	for (i = 525; i < 555;i++)
	for (j = 370; j < 400;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv64.ix, s->lv64.iy, s->lv64.s_lvl, screen, NULL);
	}
	for (i = 485; i < 525;i++)
	for (j = 280; j < 320;j++)
	if ((p1.ix == i && p1.iy == j) || (p2.ix == i && p2.iy == j))
	{
		apply_surface(s->lv65.ix, s->lv65.iy, s->lv65.s_lvl, screen, NULL);
	}
	//Afiseaza imaginea cu lvl 

	if (s->zr == 0)
	{
		if (s->r == 1)
			apply_surface(s->z1.ix, s->z1.iy, s->z1.s_zar, screen, NULL);
		if (s->r == 2)
			apply_surface(s->z2.ix, s->z2.iy, s->z2.s_zar, screen, NULL);
		if (s->r == 3)
			apply_surface(s->z3.ix, s->z3.iy, s->z3.s_zar, screen, NULL);
		if (s->r == 4)
			apply_surface(s->z4.ix, s->z4.iy, s->z4.s_zar, screen, NULL);
		if (s->r == 5)
			apply_surface(s->z5.ix, s->z5.iy, s->z5.s_zar, screen, NULL);
		if (s->r == 6)
			apply_surface(s->z6.ix, s->z6.iy, s->z6.s_zar, screen, NULL);
	}
	else {
	
	if(s->zr % 9 == 1)
	apply_surface(s->z1.ix, s->z1.iy, s->z1.s_zar, screen, NULL);

	if(s->zr%9==2)
	apply_surface(s->z2.ix, s->z2.iy, s->z2.s_zar, screen, NULL);
	if (s->zr%9==3)
	apply_surface(s->z3.ix, s->z3.iy, s->z3.s_zar, screen, NULL);
	if (s->zr%9==4)
	apply_surface(s->z4.ix, s->z4.iy, s->z4.s_zar, screen, NULL);
	if (s->zr%9==5)
	apply_surface(s->z5.ix, s->z5.iy, s->z5.s_zar, screen, NULL);
	if (s->zr%9==6)
	apply_surface(s->z6.ix, s->z6.iy, s->z6.s_zar, screen, NULL);
	if (s->zr%9==7)
	apply_surface(s->z7.ix, s->z7.iy, s->z7.s_zar, screen, NULL);
	if (s->zr%9==8)
	apply_surface(s->z8.ix, s->z8.iy, s->z8.s_zar, screen, NULL);
	if (s->zr%9==0)
	apply_surface(s->z9.ix, s->z9.iy, s->z9.s_zar, screen, NULL);
	}
	
		SDL_Flip(screen);
	
}
static joc_vtbl the_joc_vtbl = { // used to be static 
	joc_handle_events,
	joc_logic,
	joc_render
};
void joc_construct(joc *s) {
	s->vptr = &the_joc_vtbl;
	s->s_joc = load_image("piticotr.bmp");
	
	apply_surface(0, 0, s->s_joc, screen, NULL);

	pitic_construct(&p1,"sprite.bmp");
	pitic_construct2(&p2, "sprite2.bmp");
	zar_construct(&s->z1, "z1.bmp");
	zar_construct(&s->z2, "z2.bmp");
	zar_construct(&s->z3, "z3.bmp");
	zar_construct(&s->z4, "z4.bmp");
	zar_construct(&s->z5, "z5.bmp");
	zar_construct(&s->z6, "z6.bmp");
	zar_construct(&s->z7, "z7.bmp");
	zar_construct(&s->z8, "z8.bmp");
	zar_construct(&s->z9, "z9.bmp");
	lvl_construct(&s->lv5, "lv5.bmp");
	lvl_construct(&s->lv10, "lv10.bmp");
	lvl_construct(&s->lv14, "lv14.bmp");
	lvl_construct(&s->lv18, "lv18.bmp");
	lvl_construct(&s->lv24, "lv24.bmp");
	lvl_construct(&s->lv28, "lv28.bmp");
	lvl_construct(&s->lv33, "lv33.bmp");
	lvl_construct(&s->lv39, "lv39.bmp");
	lvl_construct(&s->lv43, "lv43.bmp");
	lvl_construct(&s->lv47, "lv47.bmp");
	lvl_construct(&s->lv52, "lv52.bmp");
	lvl_construct(&s->lv55, "lv55.bmp");
	lvl_construct(&s->lv58, "lv58.bmp");
	lvl_construct(&s->lv60, "lv60.bmp");
	lvl_construct(&s->lv64, "lv64.bmp");
	lvl_construct(&s->lv65, "lv65.bmp");
	s->titleA = 0;
	SDL_EnableKeyRepeat(70, 70);
}
