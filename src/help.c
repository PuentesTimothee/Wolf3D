/*
** main.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 09:26:52 2015 puente_t
** Last update Thu Dec 24 13:36:13 2015 puente_t
*/

#include <stdio.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

static void		write_menu(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  t_color		color;

  color.full = WHITE;
  pos.x = 50;
  pos.y = 500;
  tekwrite(pix, pos, color, HELP_FIRST);
  pos.y += 100;
  pos.x += 20;
  tekwrite(pix, pos, color, HELP_SECOND);
  pos.y += 100;
  pos.x += 20;
  tekwrite(pix, pos, color, HELP_THIRD);
  pos.y += 100;
  pos.x += 20;
  tekwrite(pix, pos, color, HELP_LAST);
  pos.y += 50;
  tekwrite(pix, pos, color, HELP_LAST2);
}

static int			in_menu(t_level *level)
{
  bunny_my_blit(NULL, level->pix, level->text);
  write_menu(level->pix);
  return (0);
}

t_bunny_response	help(void *_level)
{
  t_level		*level;
  t_bunny_position	p;

  level = _level;
  p.x = 0;
  p.y = 0;
  if (in_menu(level) == 1)
    return (EXIT_ON_ERROR);
  bunny_blit(&level->win->buffer, &level->pix->clipable, &p);
  bunny_display(level->win);
  return (GO_ON);
}

int			help_menu(t_level *level)
{
  bunny_set_loop_main_function(help);
  if (bunny_loop(level->win, 150, level) == EXIT_ON_ERROR)
    return (1);
  bunny_set_loop_main_function(menu);
  return (0);
}
