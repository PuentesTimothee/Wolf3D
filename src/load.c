/*
** load.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 11:21:04 2015 puente_t
** Last update Thu Dec 24 14:30:02 2015 puente_t
*/

#include <stdio.h>
#include <stdlib.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

void			place_element(char data, char **map, int x, int y)
{
  if (data == '1')
    map[y][x] = 'X';
  else if (data == 'f')
    map[y][x] = 'f';
  else if (data == '2')
    map[y][x] = 'x';
  else
    map[y][x] = '.';
}

void			free_array(char **array, int h)
{
  int			c;

  c = 0;
  while (c < h)
    {
      bunny_free(array[c]);
      c++;
    }
  bunny_free(array);
}

static char		**malloc_map()
{
  int			c;
  char			**array;

  c = 0;
  if ((array = bunny_malloc(100 * sizeof(char*))) == NULL)
    return (NULL);
  while (c < 100)
    if ((array[c++] = bunny_malloc(100 * sizeof(char))) == NULL)
      return (NULL);
  return (array);
}

static char		**arrayh(t_bunny_ini *ini,
				 t_map *map,
				 t_level *lev)
{
  char			**array;
  const char		*s;
  int			y;
  int			x;

  if (map->status == -1)
    array = malloc_map();
  else
    array = MAP;
  MAP = array;
  y = -1;
  while (++y < map->y)
    {
      x = -1;
      while (++x < map->x)
	{
	  s = bunny_ini_get_field(ini, SCOPE, "map", y * map->x + x);
	  place_element(s[0], array, x, y);
	}
      array[y][x] = 0;
    }
  return (array);
}

t_map		*load_map(t_bunny_ini *ini, t_pl_pos *pl_pos, t_level *lev, t_map *map)
{
  const char	*c;

  if (map == NULL)
    {
      if ((map = bunny_malloc(sizeof(t_map))) == NULL)
	return (NULL);
      map->status = -1;
    }
  if (map->status == 0)
    return (map);
  if ((c = bunny_ini_get_field(ini, SCOPE, "width", 0)) == NULL)
    return (NULL);
  if ((map->x = fdf_atoi(c)) <= 1 || map->x >= 100)
    return (NULL);
  if ((c = bunny_ini_get_field(ini, SCOPE, "height", 0)) == NULL)
    return (NULL);
  if ((map->y = fdf_atoi(c)) <= 1 || map->y >= 100)
    return (NULL);
  if ((c = bunny_ini_get_field(ini, SCOPE, "map", map->x * map->y - 1)) == NULL)
    return (NULL);
  if ((map->data = arrayh(ini, map, lev)) == NULL)
    return (NULL);
  if (init_player(ini, pl_pos, map, lev) == NULL)
    return (NULL);
  return (map);
}
