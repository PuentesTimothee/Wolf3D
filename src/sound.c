/*
** sound.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Wed Dec 23 14:22:32 2015 puente_t
** Last update Thu Jun  9 21:03:53 2016 Timothée Puentes
*/

#include <time.h>
#include <lapin.h>
#include "wolf3d.h"

int			walking(int is)
{
  static t_bunny_music	*music;
  static int		type = 1;
  static int		start = 0;

  if (type == 0 && time(NULL) - start > 1)
    {
      bunny_sound_stop(&music->sound);
      bunny_delete_sound(&music->sound);
      type = 1;
    }
  if (is == 1 && type == 1)
    if ((music = bunny_load_music("misc/walk.ogg")) != NULL)
      {
	bunny_sound_play(&music->sound);
	type = 0;
	start = time(NULL);
      }
  return (0);
}
