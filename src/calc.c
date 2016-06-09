/*
** calc.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 22:58:01 2015 puente_t
** Last update Sun Dec 27 10:21:19 2015 puente_t
*/

#include <time.h>
#include <stdio.h>
#include <math.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

int				print_cut(t_bunny_pixelarray *pix,
					  int p_x,
					  t_cut ret)
{
  t_bunny_pixelarray		*wall;
  t_bunny_position		pos;
  t_bunny_position		p;
  t_bunny_position		posmax;
  t_color			color;

  pos.x = p_x;
  posmax.x = WIN_Y / 2 + WIN_Y / (2 * ret.k / (double)(64));
  posmax.y = WIN_Y / 2 - WIN_Y / (2 * ret.k / (double)(64));
  pos.y = posmax.y;
  p.x = ret.cut + ((time(NULL) % 2 == 0 && ret.block == 2) ? (80) : (0));
  if ((wall = choose_wall(ret)) == NULL)
    return (1);
  while (++pos.y <= posmax.x)
    {
      p.y = (pos.y - posmax.y) *  WALL_WIDTH / (posmax.x - posmax.y);
      color = getpixel_shadowed(wall, &p, ret.k);
      tekpixel_(pix, &pos, color);
    }
  return (0);
}

t_cut			calc_k_x(t_pl_pos *pl_pos, double vx, double vy, t_map *map)
{
  t_bunny_position	p;
  t_bunny_position	tmp;
  int			k;
  t_cut			ret;

  ret.block = 0;
  k = 0;
  p.x = pl_pos->x - pl_pos->x % 64;
  while (p.x < map->x << 6 && p.x >= 0 && ret.block == 0)
    {
      k = (p.x - pl_pos->x) / vx;
      p.y = pl_pos->y + k * vy;
      tmp.y = p.y >> 6;
      tmp.x = ((vx <= 0) ? ((p.x >> 6) - 1) : (p.x >> 6));
      if (k > 0)
	if (tmp.x < map->x && tmp.x >= 0 && tmp.y < map->y && tmp.y >= 0)
	  if (TILE_IS == 'X' || TILE_IS == 'x')
	    ret.block = ((TILE_IS == 'X') ? (1) : (2));
      p.x += ((vx >= 0) ? (64) : (-64));
    }
  ret.k = k;
  ret.cut = p.y % 64;
  return (ret);
}

t_cut			calc_k_y(t_pl_pos *pl_pos, double vx, double vy, t_map *map)
{
  t_bunny_position	p;
  t_bunny_position	tmp;
  int			k;
  t_cut			ret;

  ret.block = 0;
  k = 0;
  p.y = pl_pos->y - pl_pos->y % 64;
  while (p.y < map->y << 6 && p.y >= 0 && ret.block == 0)
    {
      k = (p.y - pl_pos->y) / vy;
      p.x = pl_pos->x + k * vx;
      tmp.x = p.x >> 6;
      tmp.y = ((vy <= 0) ? ((p.y >> 6) - 1) : (p.y >> 6));
      if (k > 0)
	if (tmp.x < map->x && tmp.x >= 0 && tmp.y < map->y && tmp.y >= 0)
	  if (TILE_IS == 'X' || TILE_IS == 'x')
	    ret.block = ((TILE_IS == 'X') ? (1) : (2));
      p.y += ((vy >= 0) ? (64) : (-64));
    }
  ret.k = k;
  ret.cut = p.x % 64;
  return (ret);
}

t_cut			calc_plan(double py, t_pl_pos *pl_pos, t_map *map)
{
  double		vx;
  double		vy;
  t_cut			ret_x;
  t_cut			ret_y;
  double		lenghtx;
  double		lenghty;

  py = (WIN_X / 2 - py) / (WIN_X);
  vx = FOV * cos(pl_pos->gaze) - py * sin(pl_pos->gaze);
  vy = FOV * sin(pl_pos->gaze) + py * cos(pl_pos->gaze);
  ret_x = calc_k_x(pl_pos, vx, vy, map);
  ret_y = calc_k_y(pl_pos, vx, vy, map);
  lenghtx = vecnorm(pl_pos, ret_x.k * vx + PL_X, ret_x.k * vy + PL_Y);
  lenghty = vecnorm(pl_pos, ret_y.k * vx + PL_X, ret_y.k * vy + PL_Y);
  if (lenghtx <= lenghty)
    return (ret_x);
  else
    return (ret_y);
}

int			print_screen(t_pl_pos *pl_pos, t_map *map, t_bunny_pixelarray *pix)
{
  double		p_x;
  t_cut			ret;
  t_cut			last;

  p_x = 0;
  last.k = 0;
  last.block = 0;
  last.cut = 0;
  while (p_x < WIN_X)
    {
      ret = calc_plan(p_x, pl_pos, map);
      if (ret.k >= 3000 || ret.k <= -3000 )
	ret = last;
      last = ret;
      print_cut(pix, p_x, ret);
      p_x++;
    }
  return (0);
}
