/*
** main.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 09:26:52 2015 puente_t
** Last update Fri Feb  5 16:47:29 2016 Timothée Puentes
*/

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

int			start_calc(t_bunny_ini *ini, t_bunny_pixelarray *pix, t_level *level)
{
  static t_map		*map = NULL;
  static t_pl_pos	*pl_pos = NULL;

  if (pl_pos == NULL)
    if ((pl_pos = bunny_malloc(sizeof(t_pl_pos))) == NULL)
      return (-1);
  if ((map = load_map(ini, pl_pos, level, map)) == NULL)
    return (my_printf("Allocation failure, Exiting ...\n") - 100);
  get_status(pl_pos, map, pix);
  if (pl_pos->status == DEAD || pl_pos->status == END)
    return (death_victory(pl_pos, map));
  if (bunny_my_fill_wolf(pix) == 1)
    return (-1);
  print_screen(pl_pos, map, pix);
  if (print_map(pl_pos, map, pix) == 1)
    return (1);
  if (level->aa == 1)
    if (antialias(pix) == 1)
      return (1);
  move(pl_pos, map, level);
  return (0);
}

t_bunny_response	mainloop(void *_win)
{
  t_level		*level;
  t_bunny_pixelarray	*pix;
  t_bunny_position	p;
  t_bunny_ini		*map;
  int			ret;

  level = _win;
  p.x = 0;
  p.y = 0;
  pix = level->pix;
  if ((map = bunny_load_ini("misc/map.ini")) == NULL)
    return (EXIT_ON_ERROR);
  if ((ret = start_calc(map, pix, level)) < 0)
    return (EXIT_ON_ERROR);
  bunny_blit(&level->win->buffer, &pix->clipable, &p);
  bunny_display(level->win);
  if (ret == 1)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

int			main_game(t_level *lev)
{
  int			ret;

  bunny_set_loop_main_function(mainloop);
  lev->level[1] = '0';
  while (lev->level[1]++ != '5')
    {
      ret = bunny_loop(lev->win, 255, lev);
      if (ret == EXIT_ON_ERROR)
	return (1);
      if (ret == EXIT_ESC)
	break;
    }
  bunny_set_loop_main_function(menu);
  return (0);
}

t_bunny_response		mouse(const t_bunny_position *relative,
				      void *dat)
{
  static t_bunny_position	pos = {WIN_X / 2 ,WIN_Y / 2};
  t_level			*lev;

  lev = dat;
  dat = lev;
  pos.x += relative->x;
  pos.y += relative->y;
  return (GO_ON);
}

int			level_game(t_level *lev)
{
  int			ret;

  lev->level[1] = '0';
  bunny_set_loop_main_function(mainloop);
  ret = bunny_loop(lev->win, 255, lev);
  if (ret == EXIT_ON_ERROR)
    return (1);
  bunny_set_loop_main_function(menu);
  return (0);
}
