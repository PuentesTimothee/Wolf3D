/*
** antialias.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Sun Dec 27 10:32:53 2015 puente_t
** Last update Sun Dec 27 22:26:14 2015 puente_t
*/

#include <lapin.h>
#include "wolf3d.h"

static t_color		getpixel_c(t_bunny_pixelarray *pix,
				   int px, int py)
{
  unsigned int		*buff;
  int			c;
  t_color		color;

  color.full = BLACK;
  c = px + (pix->clipable.clip_width * py);
  buff = pix->pixels;
  if (py <= pix->clipable.clip_height && py >= 0)
    if (px >= 0 && px <= pix->clipable.clip_width)
      color.full = buff[c];
  return (color);
}

static t_color		color_half(t_color ori, t_color add, int c)
{
  c++;
  ori.argb[0] = (ori.argb[0] * c + add.argb[0] * 2) / (c + 2);
  ori.argb[1] = (ori.argb[1] * c + add.argb[1] * 2) / (c + 2);
  ori.argb[2] = (ori.argb[2] * c + add.argb[2] * 2) / (c + 2);
  ori.argb[3] = (ori.argb[3] * c + add.argb[3] * 2) / (c + 2);
  return (ori);
}

static t_color		get_color_aa(t_bunny_pixelarray *pix,
				     t_bunny_position p)
{
  t_color		color;
  int			nb;

  nb = -1;
  color.full = 0;
  color = color_half(color, getpixel_c(pix, p.x - 1, p.y), ++nb);
  color = color_half(color, getpixel_c(pix, p.x, p.y - 1), ++nb);
  color = color_half(color, getpixel_c(pix, p.x + 1, p.y), ++nb);
  color = color_half(color, getpixel_c(pix, p.x, p.y + 1), ++nb);
  color = color_half(color, getpixel_c(pix, p.x - 1, p.y - 1), ++nb);
  color = color_half(color, getpixel_c(pix, p.x + 1, p.y - 1), ++nb);
  color = color_half(color, getpixel_c(pix, p.x + 1, p.y + 1), ++nb);
  color = color_half(color, getpixel_c(pix, p.x - 1, p.y + 1), ++nb);
  color = color_half(color, getpixel_c(pix, p.x, p.y), ++nb);
  return (color);
}

int			antialias(t_bunny_pixelarray *pix)
{
  t_bunny_pixelarray	*new;
  t_bunny_position	p;
  t_color		color;

  if ((new = bunny_new_pixelarray(WIN_Y, WIN_X)) == NULL)
      return (1);
  p.y = 0;
  while (p.y < WIN_Y)
    {
      p.x = 0;
      while (p.x < WIN_X)
	{
	  color = get_color_aa(pix, p);
	  tekpixel(new, &p, &color);
 	  p.x++;
	}
      p.y++;
    }
  bunny_my_blit(NULL, pix, new);
  bunny_delete_clipable(&new->clipable);
  return (0);
}
