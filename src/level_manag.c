/*
** level_manag.c for  in /home/puente_t/rendu/gfx_wolf3d/src
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Wed Dec 16 14:41:40 2015 puente_t
** Last update Thu Dec 24 12:01:51 2015 puente_t
*/

#include <time.h>
#include <lapin.h>
#include <stdio.h>
#include "wolf3d.h"

int			get_status(t_pl_pos *pl_pos, t_map *map, t_bunny_pixelarray *pix)
{
  char			pos;
  static int		last_time = 0;

  if (last_time == 0)
      last_time = time(NULL);
  if (pl_pos->status == END)
    degrade(pix, BLACK, "victory !!!");
  else if (pl_pos->status == DEAD)
    degrade(pix, RED, "Too late ...");
  pos = MAP[P_Y][P_X];
  if (pos == 'f')
    pl_pos->status = END;
  else if (pos == 'e' || pl_pos->timer <= 0)
    pl_pos->status = DEAD;
  else
    pl_pos->status = 0;
  if (time(NULL) - last_time >= 1)
    {
      pl_pos->timer -= time(NULL) - last_time;
      last_time = time(NULL);
    }
  return (pl_pos->status);
}

static t_color		color_line(int x,
				   int max,
				   t_color *color)
{
  t_color		new;
  double		pe;

  pe = (double)x / (double)max;
  new.argb[0] = color[1].argb[0] * pe + color[0].argb[0] * (1 - pe);
  new.argb[1] = color[1].argb[1] * pe + color[0].argb[1] * (1 - pe);
  new.argb[2] = color[1].argb[2] * pe + color[0].argb[2] * (1 - pe);
  new.argb[3] = color[1].argb[3] * pe + color[0].argb[3] * (1 - pe);
  return (new);
}

int			degrade_write(t_bunny_pixelarray *pix, unsigned int color, char *str)
{
  t_bunny_position	mid;
  t_color		col;
  t_color		co[2];

  co[0].full = color;
  co[1].full = ~color;
  mid.x = WIN_X / 2 - 120;
  mid.y = WIN_Y / 2;
  while (mid.y < WIN_Y / 2 + 7)
    {
      col = color_line(mid.y - WIN_Y / 2, 7, co);
      tekwrite(pix, mid, col, str);
      mid.x++;
      mid.y++;
    }
  return (0);
}

int			degrade(t_bunny_pixelarray *pix, unsigned int color, char *str)
{
  t_color		col;
  t_color		co[2];
  unsigned int		*buff;
  int			c;

  buff = pix->pixels;
  c = 0;
  co[0].full = color;
  co[1].full = ~color;
  while (c < WIN_X * WIN_Y)
    {
      col.full = buff[c];
      col.argb[0] = (col.argb[0] * 59 + co[0].argb[0]) / 60;
      col.argb[1] = (col.argb[1] * 59 + co[0].argb[1]) / 60;
      col.argb[2] = (col.argb[2] * 59 + co[0].argb[2]) / 60;
      col.argb[3] = (col.argb[3] * 59 + co[0].argb[3]) / 60;
      buff[c] = col.full;
      c++;
    }
  degrade_write(pix, color, str);
  return (0);
}
