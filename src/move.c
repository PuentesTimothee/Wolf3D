/*
** move.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Thu Dec  3 10:44:30 2015 puente_t
** Last update Tue Feb 16 20:25:57 2016 Timothée Puentes
*/

#include <time.h>
#include <math.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

int			move_cur(int cur)
{
  const bool			*keys;
  static int			last_time = 0;

  if (last_time == 0)
      last_time = time(NULL);
  keys = bunny_get_keyboard();
  if (keys[BKS_DOWN] == 1 && time(NULL) - last_time >= 1)
    {
      if ((cur += 1) == 5)
	cur = 0;
      last_time = time(NULL);
    }
 else if (keys[BKS_UP] == 1 && time(NULL) - last_time >= 1)
   {
     if ((cur -= 1) == -1)
      cur = 4;
     last_time = time(NULL);
   }
  if (keys[BKS_SPACE] == 1 && time(NULL) - last_time >= 1)
    {
      cur = -cur - 1;
      last_time = time(NULL);
    }
  return (cur);
}

void				move_destroy(t_pl_pos *pl_pos, const bool *keys, t_map *map)
{
  t_pl_pos			new;

  if (keys[BKS_E] == 0)
    return ;
  new.x = (int)(PL_X + cos(GAZE) * 36) >> 6;
  new.y = (int)(PL_Y + sin(GAZE) * 36) >> 6;
  if (new.x < map->x && new.x > 0 && new.y < map->y && new.y > 0)
    if (MAP[new.y][new.x] == 'x')
      MAP[new.y][new.x] = '_';
}

void				move_pos(t_pl_pos *pl_pos, const bool *keys, t_map *map)
{
  t_pl_pos			new;
  t_pl_pos			r_new;

  new.x = PL_X;
  new.y = PL_Y;
  if (keys[BKS_UP] == 1 || keys[BKS_Z] == 1)
    {
      new.x += cos(GAZE) * ((keys[BKS_LSHIFT] != 1) ? (MOVE) : (SPRINT));
      new.y += sin(GAZE) * ((keys[BKS_LSHIFT] != 1) ? (MOVE) : (SPRINT));
    }
  else if (keys[BKS_DOWN] == 1 || keys[BKS_S] == 1 )
    {
      new.x -= cos(GAZE) * ((keys[BKS_LSHIFT] != 1) ? (MOVE) : (SPRINT));
      new.y -= sin(GAZE) * ((keys[BKS_LSHIFT] != 1) ? (MOVE) : (SPRINT));
    }
  r_new.x = new.x >> 6;
  r_new.y = new.y >> 6;
  if (r_new.x < map->x && new.x > 0 && MAP[P_Y][r_new.x] != 'X')
    if (MAP[P_Y][r_new.x] != 'x')
      pl_pos->x = new.x;
  if (r_new.y < map->y && new.y > 0 && MAP[r_new.y][P_X] != 'X')
    if (MAP[r_new.y][P_X] != 'x')
      pl_pos->y = new.y;
  if (keys[BKS_UP] == 1 || keys[BKS_DOWN] == 1)
    walking(((PL_Y == r_new.y) || (PL_X == r_new.x) ? (1) : (0)));
}

void				move_gaze(t_pl_pos *pl_pos, const bool *keys, t_level *level)
{
  t_pl_pos			new;
  double			dep;
  const t_bunny_position	*mouse;

  mouse = bunny_get_mouse_position();
  dep = ((keys[BKS_LSHIFT] != 1) ? (0.05) : (0.10));
  new.gaze = GAZE;
  if (keys[BKS_LEFT] == 1 || keys[BKS_Q] == 1 )
    new.gaze = GAZE + dep;
  else if (keys[BKS_RIGHT] == 1 || keys[BKS_D] == 1 )
    new.gaze = GAZE - dep;
  if (level->mouse == 0)
    new.gaze += (WIN_X / 2 - mouse->x) / (double)20000;
  GAZE = ((new.gaze > 2 * M_PI) ? (new.gaze - 2 * M_PI) : (new.gaze));
  GAZE = ((GAZE < 0) ? (GAZE + 2 * M_PI) : (GAZE));
}

t_pl_pos			*move(t_pl_pos *pl_pos, t_map *map, t_level *level)
{
  const bool			*keys;

  keys = bunny_get_keyboard();
  move_gaze(pl_pos, keys, level);
  move_pos(pl_pos, keys, map);
  move_destroy(pl_pos, keys, map);
  if (keys[BKS_M] == 1 && map->mini_map <= WIN_Y)
    map->mini_map += 5;
  else if (keys[BKS_M] == 0 && map->mini_map > WIN_X / 5)
    map->mini_map -= 5;
  return (pl_pos);
}
