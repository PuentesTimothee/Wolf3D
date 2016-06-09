/*
** init.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 10:20:55 2015 puente_t
** Last update Sat Dec 26 12:02:19 2015 puente_t
*/

#include <stdlib.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

t_pl_pos	*init_player(t_bunny_ini *ini,
			     t_pl_pos *pl_pos,
			     t_map *map,
			     t_level *lev)
{
  const char	*c;

  if ((c = bunny_ini_get_field(ini, SCOPE, "start", 0)) == NULL)
    return (NULL);
  pl_pos->y = fdf_atoi(c);
  if ((c = bunny_ini_get_field(ini, SCOPE, "start", 1)) == NULL)
    return (NULL);
  pl_pos->x = fdf_atoi(c);
  if ((c = bunny_ini_get_field(ini, SCOPE, "start", 2)) == NULL)
    return (NULL);
  pl_pos->timer = fdf_atoi(c);
  if ((c = bunny_ini_get_field(ini, SCOPE, "start", 3)) == NULL)
    return (NULL);
  pl_pos->gaze = fdf_atoi(c) / (double)100;
  pl_pos->mtime = pl_pos->timer;
  pl_pos->o_x = pl_pos->x;
  pl_pos->o_y = pl_pos->y;
  pl_pos->status = 0;
  map->mini_map = WIN_X / 5;
  map->status = 0;
  return (pl_pos);
}
