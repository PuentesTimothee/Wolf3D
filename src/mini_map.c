/*
** mini_map.c for  in /home/puente_t/Documents/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Tue Dec 15 11:28:51 2015 puente_t
** Last update Wed Dec 23 11:30:39 2015 puente_t
*/

#include <math.h>
#include <lapin.h>
#include "wolf3d.h"

void			print_tile(t_bunny_pixelarray *pix,
				   t_bunny_position start,
				   t_color color,
				   t_map *map)
{
  t_bunny_position	pos;
  int			maxx;
  int			maxy;
  t_color		black;

  black.full = BLACK;
  pos.y = start.y * MAP_SIZE / map->y;
  maxx =  (start.x + 1) * MAP_SIZE / map->x + WIN_Y - MAP_SIZE;
  maxy =  (start.y + 1) * MAP_SIZE / map->y;
  while (pos.y < maxy)
    {
      pos.x = start.x * MAP_SIZE / map->x + WIN_X - MAP_SIZE;
      while (pos.x < maxx)
	{
	  if (pos.x == maxx - 1 || pos.y == maxy - 1)
	    tekpixel(pix, &pos, &black);
	  else
	    tekpixel(pix, &pos, &color);
	  pos.x++;
	}
      pos.y++;
    }
}

void			print_map2(t_map *map, t_bunny_pixelarray *pix)
{
  t_bunny_position	pos[2];
  t_color		color[2];

  pos[0].y = 0;
  while (pos[0].y < map->y)
    {
      pos[0].x = 0;
      while (pos[0].x < map->x)
	{
	  if (MINI_MAP == 'X')
	    color[0].full = MAP_WALL;
	  else if (MINI_MAP == 'x')
	    color[0].full = MAP_H_WALL;
	  else if (map->data[pos[0].y][pos[0].x] == 'f')
	    color[0].full = RED;
	  else
	    color[0].full = MAP_GROUND;
	  print_tile(pix, pos[0], color[0], map);
	  pos[0].x++;
	}
      pos[0].y++;
    }
}

int			write_nbr(t_bunny_pixelarray *pix,
				  t_pl_pos *pl_pos,
				  t_map *map)
{
  t_bunny_position	start[2];
  t_color		color[2];

  color[0].full = BLACK;
  color[1].full = BLACK;
  start[0].y = MAP_SIZE + 32;
  start[0].x = WIN_X - MAP_SIZE - 1;
  start[1].y = MAP_SIZE;
  start[1].x = start[0].x + 1;
  while (++start[0].x < WIN_X)
    {
      tekline(pix, start, color);
      start[1].x++;
    }
  color[0].full = ((pl_pos->timer >= 5) ? (WHITE) : (RED));
  start[0].x = WIN_X - MAP_SIZE + 5;
  start[0].y = MAP_SIZE + 5;
  my_revatoi(pl_pos->timer, map, pix);
  return (0);
}

int			print_map(t_pl_pos *pl_pos, t_map *map, t_bunny_pixelarray *pix)
{
  t_bunny_position	pos[2];
  t_color		color[3];

  color[0].full = RED;
  color[1].full = BLACK;
  pos[1].x = WIN_X - MAP_SIZE - 1;
  pos[1].y = MAP_SIZE;
  pos[0].x = WIN_X - MAP_SIZE - 1;
  pos[0].y = 0;
  tekline(pix, pos, &color[0]);
  pos[0].x = WIN_X;
  pos[0].y = MAP_SIZE;
  tekline(pix, pos, &color[0]);
  print_map2(map, pix);
  color[0].full = PLAYER_MAP;
  pos[0].x = WIN_X - MAP_SIZE + PL_X / (double)64 * MAP_SIZE / map->x;
  pos[0].y = PL_Y / (double)64 * MAP_SIZE / map->y;
  color[1].full = PLAYER_MAP;
  pos[1].x = pos[0].x + cos(GAZE) * MAP_SIZE / 20;
  pos[1].y = pos[0].y + sin(GAZE) * MAP_SIZE / 20;
  tekline(pix, &pos[0], &color[0]);
  if (write_nbr(pix, pl_pos, map) == 1)
    return (1);
  return (0);
}
