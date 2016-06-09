/*
** texture.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Tue Dec 22 12:46:22 2015 puente_t
** Last update Sun Dec 27 13:08:15 2015 puente_t
*/

#include <lapin.h>
#include "wolf3d.h"

t_color			getpixel_shadowed(t_bunny_pixelarray *pix, t_bunny_position *p, int k)
{
  t_bunny_position		c;
  t_color			color;

  color = getpixel(pix, p);
  c.y = -1;
  while (++c.y < 3)
    {
      c.x = color.argb[c.y] - k * 2 / 3;
      color.argb[c.y] = ((c.x >= 0) ? (c.x) : (0));
    }
  return (color);
}

char			my_revatoi(int nb, t_map *map,
				   t_bunny_pixelarray *pix)
{
  t_color		color;
  t_bunny_position	pos;

  pos.x = WIN_X - MAP_SIZE + 5;
  pos.y = MAP_SIZE + 5;
  color.full = WHITE;
  if (nb < 5)
    color.full = RED;
  tekwritec(pix, pos, color, nb / 1000 + '0');
  nb %= 1000;
  pos.x += 22;
  tekwritec(pix, pos, color, nb / 100 + '0');
  nb %= 100;
  pos.x += 22;
  tekwritec(pix, pos, color, nb / 10 + '0');
  nb %= 10;
  pos.x += 22;
  tekwritec(pix, pos, color, nb + '0');
  pos.x += 22;
  return (0);
}

t_bunny_pixelarray		*choose_wall(t_cut ret)
{
  static t_bunny_pixelarray	*wall1 = NULL;
  static t_bunny_pixelarray	*wall2 = NULL;

  if (wall1 == NULL)
    if ((wall1 = bunny_load_pixelarray("misc/wallb.png")) == NULL)
      return (NULL);
  if (wall2 == NULL)
    if ((wall2 = bunny_load_pixelarray("misc/wall2.png")) == NULL)
      return (NULL);
  if (ret.block == 1)
    return (wall1);
  else if (ret.block == 2)
    return (wall2);
  return (NULL);
}
