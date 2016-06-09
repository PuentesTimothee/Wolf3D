/*
** test-LibLapin.c for  in /home/puente_t/Test
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Oct 15 12:55:32 2015 Timothée Puentes
** Last update Fri Jan  8 10:40:18 2016 puente_t
*/

#include <lapin.h>
#include "tekk.h"
#include "my.h"

void			tekpixell(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  t_color color)
{
  unsigned int		*buff;
  int			c;

  c = pos[0].x + (pix->clipable.clip_width * pos[0].y);
  buff = pix->pixels;
  if (pos->y <= pix->clipable.clip_height && pos->y >= 0)
    if (pos->x >= 0 && pos->x <= pix->clipable.clip_width)
      buff[c] = color.full;
}

static t_color			color_line(t_bunny_position *pos,
				   t_bunny_position p,
				   t_color *color)
{
  t_color		new;
  double		pe;
  double		diffx;
  double		diffy;
  double		diffx_p;
  double		diffy_p;

  diffx = pos[1].x - pos[0].x;
  diffy = pos[1].y - pos[0].y;
  diffx_p = p.x - pos[0].x;
  diffy_p = p.y - pos[0].y;
  if (diffx != 0 && diffx != 0)
    pe = ((diffx_p / diffx) + (diffy_p / diffy)) / 2;
  if (diffy == 0 && diffx != 0)
    pe = (diffx_p / diffx);
  if (diffy != 0 && diffx == 0)
    pe = (diffy_p / diffy);
  new.argb[0] = color[0].argb[0] * (1 - pe) + color[1].argb[0] * pe;
  new.argb[1] = color[0].argb[1] * (1 - pe) + color[1].argb[1] * pe;
  new.argb[2] = color[0].argb[2] * (1 - pe) + color[1].argb[2] * pe;
  new.argb[3] = color[0].argb[3] * (1 - pe) + color[1].argb[3] * pe;
  return (new);
}

void			tekline(t_bunny_pixelarray *pix,
				t_bunny_position *pos,
				t_color *color)
{
  double		m;
  t_pos_d		diff;
  int			b;
  t_bunny_position	p;

  p = pos[0];
  diff.x = (double)(pos[1].x - pos[0].x);
  diff.y = (double)(pos[1].y - pos[0].y);
  m = (diff.y) / (diff.x);
  b = pos[0].y - (pos[0].x * m);
  while (p.x != pos[1].x && diff.x != 0)
    {
      ((diff.x >= 0) ? (p.x++) : (p.x--));
      tekpixell(pix, &p, color_line(pos, p, color));
      while ((int)(p.x * m) + b != p.y && diff.y != 0)
	{
	  (((int)(p.x * m) + b - p.y >= 0) ? (p.y++) : (p.y--));
	 tekpixell(pix, &p, color_line(pos, p, color));
 	}
    }
  while (diff.x == 0 && p.y != pos[1].y)
    {
      ((pos[1].y - p.y >= 0) ? (p.y++) : (p.y--));
      tekpixell(pix, &p, color_line(pos, p, color));
    }
}
