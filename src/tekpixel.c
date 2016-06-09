/*
** test-LibLapin.c for  in /home/puente_t/Test
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Oct 15 12:55:32 2015 Timothée Puentes
** Last update Sun Dec 27 11:53:51 2015 puente_t
*/

#include <math.h>
#include <lapin.h>
#include "wolf3d.h"

double		vecnorm(t_pl_pos *coord0,
			int x, int y)
{
  int		diffx;
  int		diffy;
  double	res;

  diffy = y - coord0->y;
  diffx = x - coord0->x;
  res = sqrt(diffy * diffy + diffx * diffx);
  return (res);
}

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color)
{
  unsigned int		*buff;
  int			c;

  c = pos[0].x + (pix->clipable.clip_width * pos[0].y);
  buff = pix->pixels;
  if (pos->y <= pix->clipable.clip_height && pos->y >= 0)
    if (pos->x >= 0 && pos->x <= pix->clipable.clip_width)
      buff[c] = color->full;
}

void			tekpixel_(t_bunny_pixelarray *pix,
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

t_color			getpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos)
{
  unsigned int		*buff;
  int			c;
  t_color		color;

  color.full = BLACK;
  c = pos[0].x + (pix->clipable.clip_width * pos[0].y);
  buff = pix->pixels;
  if (pos->y <= pix->clipable.clip_height && pos->y >= 0)
    if (pos->x >= 0 && pos->x <= pix->clipable.clip_width)
      color.full = buff[c];
  return (color);
}

void			bunny_my_blit(t_bunny_position *po,
				      t_bunny_pixelarray *dest,
				      t_bunny_pixelarray *ori)
{
  t_bunny_position	pos;
  t_bunny_position	p;
  unsigned int		*buff;
  int			c;

  buff = dest->pixels;
  pos.y = ((po != NULL) ? (po->y) : (0));
  p.y = 0;
  while (pos.y < WIN_Y && p.y < ori->clipable.clip_height)
    {
      p.x = 0;
      pos.x = ((po != NULL) ? (po->x) : (0));
      while (pos.x < WIN_X && p.y < ori->clipable.clip_width)
	{
	  c = WIN_X * pos.y + pos.x;
	  buff[c] = getpixel(ori, &p).full;
	  pos.x++;
	  p.x++;
	}
      pos.y++;
      p.y++;
    }
}
