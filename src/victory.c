/*
** victory.c for  in /home/puente_t/rendu/Script/misc
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Tue Dec 15 12:30:10 2015 puente_t
** Last update Thu Jun  9 21:00:47 2016 Timothée Puentes
*/

#include <time.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

int			victory()
{
  static int		start = 0;
  static t_bunny_music	*music;

  if (start == 0)
    {
      if ((music = bunny_load_music("misc/fanfare.ogg")) != NULL)
	bunny_sound_play(&music->sound);
      start = time(NULL);
    }
  if (time(NULL) - start >= VICTORY_DELAY)
    {
      bunny_sound_stop(&music->sound);
      bunny_delete_sound(&music->sound);
      start = 0;
      return (1);
    }
  return (0);
}

int			death()
{
  static int		start = 0;
  static t_bunny_music	*music;

  if (start == 0)
    {
      if ((music = bunny_load_music("misc/death.ogg")) != NULL)
	bunny_sound_play(&music->sound);
      start = time(NULL);
    }
  if (time(NULL) - start >= DEATH_DELAY)
    {
      if (music != NULL)
	{
	  bunny_sound_stop(&music->sound);
	  bunny_delete_sound(&music->sound);
	}
      start = 0;
      return (1);
    }
  return (0);
}

void			restart_map(t_map *map)
{
  t_bunny_position	p;

  p.y = 0;
  while (p.y < map->y)
    {
      p.x = 0;
      while (p.x < map->x)
	{
	  if (MAP[p.y][p.x] == '_')
	    MAP[p.y][p.x] = 'x';
	  p.x++;
	}
      p.y++;
    }
}

int			death_victory(t_pl_pos *pl_pos, t_map *map)
{
  if (pl_pos->status == END)
    {
      if (victory() == 0)
	return (0);
      map->status = 1;

      return (1);
    }
  else if (pl_pos->status == DEAD)
    {
      if (death() == 1)
	{
	  pl_pos->x = pl_pos->o_x;
	  pl_pos->y = pl_pos->o_y;
	  pl_pos->timer = pl_pos->mtime;
	  pl_pos->status = 0;
	  pl_pos->gaze = 0;
	  restart_map(map);
 	}
      return (0);
    }
  return (0);
}
