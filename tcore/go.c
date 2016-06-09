/*
** go.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 10:00:00 2015 puente_t
** Last update Mon Dec 14 19:05:29 2015 puente_t
*/

#include <math.h>
#include <lapin.h>

void		go(t_bunny_position *curpos,
		   double angle,
		   t_bunny_position *newpos,
		   int move)
{
  newpos->x = curpos->x;
  newpos->y = curpos->y;
  newpos->x += cos(angle) * move;
  newpos->y += sin(angle) * move;
}
