/*
** loader.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Wed Dec 16 11:16:44 2015 puente_t
** Last update Mon Dec 21 18:45:12 2015 puente_t
*/

#include <stdio.h>
#include <lapin.h>
#include <unistd.h>
#include <fcntl.h>
#include "wolf3d.h"

void			stretch(t_bunny_pixelarray *pix,
				const t_bunny_pixelarray *ori)
{
  t_bunny_position	o;
  t_bunny_position	act;
  t_bunny_position	p;
  t_bunny_position	c;
  unsigned int		*buff1;
  unsigned int		*buff2;

  buff1 = ori->pixels;
  buff2 = pix->pixels;
  o.x = ori->clipable.clip_width;
  p.x = pix->clipable.clip_width;
  o.y = ori->clipable.clip_height;
  p.y = pix->clipable.clip_height;
  c.y = -1;
  while (++c.y < p.y)
    {
      c.x = -1;
      while (++c.x < p.x)
	{
	  act.x = c.x * o.x / p.x + c.y * o.y / p.y * o.x;
	  act.y = c.x + c.y * p.x;
	  buff2[act.y] = buff1[act.x];
	}
    }
}

static t_bunny_pixelarray	*arrayh(int pic,
					int my,
					int mx,
					t_bunny_pixelarray *pix)
{
  t_bunny_position		p;
  unsigned char			arg[4];
  int				c;
  t_color			act;
  unsigned int			*buff;

  buff = pix->pixels;
  p.y = my - 1;
  while (p.y >= 0)
    {
      p.x = 0;
      while (p.x < mx)
	{
	  read(pic, arg, 4);
	  act.argb[0] = arg[2];
	  act.argb[1] = arg[1];
	  act.argb[2] = arg[0];
	  act.argb[3] = arg[3];
	  c = p.x + (pix->clipable.clip_width * p.y);
	  buff[c] = act.full;
	  p.x++;
	}
      p.y--;
    }
  return (pix);
}

t_bunny_pixelarray		*load_bitmap(const char *file)
{
  t_bunny_pixelarray		*pix;
  t_bitheader			header;
  int				fd;

  if ((fd = open(file, O_RDONLY)) < 0)
    return (NULL);
  if (read(fd, &header, sizeof(t_bitheader)) != sizeof(t_bitheader))
    return (NULL);
  pix = bunny_new_pixelarray(header.width, header.height);
  pix = arrayh(fd, header.height, header.width, pix);
  close(fd);
  return (pix);
}
