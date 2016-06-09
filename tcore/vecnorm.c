/*
** vecnorm.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 09:53:56 2015 puente_t
** Last update Mon Dec 14 11:31:11 2015 puente_t
*/

#include <math.h>
#include <lapin.h>

double		vecnorm(t_bunny_position *coord0,
			t_bunny_position *coord1)
{
  double	diffx;
  double	diffy;
  double	res;

  diffy = coord1->y - coord0->y;
  diffx = coord1->x - coord0->x;
  res = sqrt(pow(diffy, 2) + pow(diffx, 2));
  return (res);
}
