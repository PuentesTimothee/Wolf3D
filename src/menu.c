/*
** main.c for  in /home/puente_t/rendu/gfx_wolf3d
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Mon Nov 30 09:26:52 2015 puente_t
** Last update Mon Jan  4 16:46:07 2016 puente_t
*/

#include <stdio.h>
#include <lapin.h>
#include "wolf3d.h"
#include "my.h"

static void		write_menu(t_bunny_pixelarray *pix, int cur, t_level *level)
{
  t_bunny_position	pos;
  t_color		color;

  pos.x = 100;
  pos.y = WIN_Y / 2 + 100;
  color.full = ((cur == 0) ? (RED) : (WHITE));
  tekwrite(pix, pos, color, "Campagne");
  pos.y += 100;
  pos.x += 20;
  color.full = ((cur == 1) ? (RED) : (WHITE));
  tekwrite(pix, pos, color, "HELP");
  pos.y += 100;
  pos.x += 20;
  color.full = ((cur == 2) ? (RED) : (WHITE));
  tekwrite(pix, pos, color, "QUIT");
  pos.y = WIN_Y - 100;
  pos.x = WIN_X / 5;
  color.full = ((cur == 3) ? (RED) : (WHITE));
  tekwrite(pix, pos, color, "mouse control is ");
  pos.x = WIN_X / 2 + 100;
  tekwrite(pix, pos, color, ((level->mouse == 0) ? ("ON") : ("OFF")));
  pos.y = WIN_Y - 50;
  pos.x = WIN_X / 5;
  color.full = ((cur == 4) ? (RED) : (WHITE));
  tekwrite(pix, pos, color, ((level->aa == 1) ? ("AA ON") : ("AA OFF")));
}

static int			in_menu(t_level *level)
{
  static int			cur = 0;

  if (level->text == NULL)
    if ((level->text = bunny_load_pixelarray("misc/logo.png")) == NULL)
      return (1);
  if (cur < 0)
    cur = 0;
  bunny_my_blit(NULL, level->pix, level->text);
  write_menu(level->pix, cur, level);
  if ((cur = move_cur(cur)) < 0)
    return (cur);
  return (1);
}

t_bunny_response	menu(void *_win)
{
  t_level		*level;
  t_bunny_position	p;
  int			ret;

  level = _win;
  p.x = 0;
  p.y = 0;
  ret = in_menu(level);
  if (ret < -5 || ret > 1)
    return (EXIT_ON_ERROR);
  if (ret <= 0)
    ret = menu_select(ret, level);
  if (ret == -7)
    return (EXIT_ON_SUCCESS);
  if (ret == -6)
    return (EXIT_ON_ERROR);
  bunny_blit(&level->win->buffer, &level->pix->clipable, &p);
  bunny_display(level->win);
  return (GO_ON);
}

t_bunny_response	exit_esc(t_bunny_event_state state,
				 t_bunny_keysym key,
				 void *_win)
{
  t_bunny_window	*win;

  win = _win;
  _win = win;
  if (key == BKS_ESCAPE && state == GO_DOWN)
    return (EXIT_ESC);
  return (GO_ON);
}

int			main(void)
{
  t_level		lev;

  lev.level[0] = 'C';
  lev.level[1] = '0';
  lev.level[2] = 0;
  if ((lev.pix = bunny_new_pixelarray(WIN_Y, WIN_X)) == NULL)
    return (EXIT_ON_ERROR);
  lev.win = bunny_start(WIN_Y, WIN_X, false, "Wolf3D");
  bunny_set_loop_main_function(menu);
  bunny_set_move_response(mouse);
  bunny_set_key_response(exit_esc);
  lev.text = NULL;
  lev.mouse = 1;
  lev.aa = 0;
  if (bunny_loop(lev.win, 150, &lev) == EXIT_ON_ERROR)
    return (1);
  if (lev.win != NULL)
    bunny_stop(lev.win);
  return (0);
}
