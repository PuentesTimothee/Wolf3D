/*
** menu_useful.c for  in /home/puente_t/rendu/gfx_wolf3d/src
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Dec 21 10:19:49 2015 puente_t
** Last update Mon Jan  4 14:30:22 2016 puente_t
*/

#include <time.h>
#include <math.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

int				fdf_atoi(const char *str)
{
  int				c;
  int				result;
  int				size;
  int				neg;

  neg = 0;
  c = 0;
  result = 0;
  size = 0;
  if (str[0] == 0)
    return (0);
  while ((str[size] == '-' && size == 0) || IS_N(str[size]))
      size++;
  if (str[0] == '-')
    neg = 1;
  while (size - c - 1 >= neg)
    {
      result = result + (my_power_it(10, c) * (str[size - c - 1] - '0'));
      c++;
    }
  if (str[0] == '-')
    result = result * -1;
  return (result);
}

void				bunny_my_fill(t_bunny_pixelarray *pix, unsigned int color)
{
  unsigned int			*buff;
  int				c;

  buff = pix->pixels;
  c = 0;
  while (c < WIN_X * WIN_Y)
    {
      color = BLACK;
      if (c <= (WIN_X * WIN_Y))
	buff[c] = color;
      c++;
    }
}

int				bunny_my_fill_wolf(t_bunny_pixelarray *pix)
{
  static t_bunny_pixelarray	*sky = NULL;

  if (sky == NULL)
    if ((sky = bunny_load_pixelarray("misc/ground.png")) == NULL)
      return (1);
  bunny_my_blit(NULL, pix, sky);
  return (0);
}

int				menu_select(int ret, t_level *level)
{
  if (ret == -5)
    level->aa = ((level->aa == 0) ? (1) : (0));
  else if (ret == -4)
    level->mouse = ((level->mouse == 0) ? (1) : (0));
  else if (ret == -3)
    return (-7);
  else if (ret == -2)
    help_menu(level);
  else if (ret == -1)
    if ((ret = main_game(level)) == 1)
      return (-6);
  return (ret);
}
