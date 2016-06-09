/*
** test-LibLapin.c for  in /home/puente_t/Test
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Oct 15 12:55:32 2015 Timothée Puentes
** Last update Mon Dec 14 16:53:30 2015 puente_t
*/

#include <lapin.h>

void			tekpixel(t_bunny_pixelarray *pix,
				 t_bunny_position *pos,
				 t_color *color)
{
  unsigned int		*buff;
  int		       	c;

  c = pos[0].x + (pix->clipable.clip_width * pos[0].y);
  buff = pix->pixels;
  if (c >= 0 && c <= (pix->clipable.clip_height * pix->clipable.clip_width))
    buff[c] = color->full;
}
