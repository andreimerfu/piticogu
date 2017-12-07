#ifndef FUNCTII_H
#define FUNCTII_H

#include "SDL/SDL.h"

SDL_Surface * load_image(char *file);

void apply_surface(int x, int y, SDL_Surface * src, SDL_Surface * dst, SDL_Rect *clip);
int init();
int load_files();
void clean();
void next_state(int newstate);
int check_collision(SDL_Rect A, SDL_Rect B);
void change_state();
void incarca_vars(const char* file_name);
void salvare_vars(const char* file_name);

#endif