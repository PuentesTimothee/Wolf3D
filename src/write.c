/*
** write.c for  in /home/puente_t/rendu/Info_Test/Write
**
** Made by puente_t
** Login   <puente_t@epitech.net>
**
** Started on  Fri Dec 18 11:21:26 2015 puente_t
** Last update Thu Jun  9 21:02:41 2016 Timothée Puentes
*/

#include <math.h>
#include <time.h>
#include <stdio.h>
#include <lapin.h>
#include "write.h"
#include "wolf3d.h"

static int		get_rank(char c)
{
   if (c >= 'a' && c <= 'z')
     return (c - 'a');
   else if (c >= 'A' && c <= 'Z')
     return (c - 'A');
   else if (c >= '0' && c <= '9')
     return (c - '0' + BFT_0);
   else if (c == '!')
     return (BFT_EXCLAMATION);
   return (-1);
}

void			tekwrite(t_bunny_pixelarray *pix,
				 t_bunny_position start,
				 t_color colo,
				 char *str)
{
  int			c;
  t_color		color[2];
  t_bunny_position	pos[2];
  int			i;
  int			rank;

  color[0] = colo;
  color[1] = colo;
  i = -1;
  while (str[++i] != 0)
    {
      c = 0;
      rank = get_rank(str[i]);
      while (rank != -1 && c < gl_vector_font[rank].nb_edge)
	{
	  pos[0].x = gl_vector_font[rank].edge[c].x0 + start.x + i * 22;
	  pos[0].y = gl_vector_font[rank].edge[c].y0 + start.y;
	  pos[1].x = gl_vector_font[rank].edge[c].x1 + start.x + i * 22;
          pos[1].y = gl_vector_font[rank].edge[c].y1 + start.y;
	  tekline(pix, &pos[0], &color[0]);
	  c++;
	}
    }
}

void			tekwritec(t_bunny_pixelarray *pix,
				  t_bunny_position start,
				  t_color colo,
				  char str)
{
  int			c;
  t_color		color[2];
  t_bunny_position	pos[2];
  int			rank;

  color[0] = colo;
  color[1] = colo;
  c = 0;
  rank = get_rank(str);
  while (rank != -1 && c < gl_vector_font[rank].nb_edge)
    {
      pos[0].x = gl_vector_font[rank].edge[c].x0 + start.x;
      pos[0].y = gl_vector_font[rank].edge[c].y0 + start.y;
      pos[1].x = gl_vector_font[rank].edge[c].x1 + start.x;
      pos[1].y = gl_vector_font[rank].edge[c].y1 + start.y;
      tekline(pix, &pos[0], &color[0]);
      c++;
    }
}

void			tekwrite_s(t_bunny_pixelarray *pix,
				   t_bunny_position start,
				   unsigned int colo,
				   char *str)
{
  int			c;
  t_color		color[2];
  t_bunny_position	pos[2];
  int			i;
  int			rank;

  color[0].full = colo;
  color[1].full = colo;
  i = -1;
  while (str[++i] != 0)
    {
      c = -1;
      rank = get_rank(str[i]);
      while (rank != -1 && ++c < gl_vector_font[rank].nb_edge)
	{
          pos[0].x = gl_vector_font[rank].edge[c].x0 + start.x + i * 22 + 2;
	  pos[1].x = gl_vector_font[rank].edge[c].x1 + start.x + i * 22 + 2;
          pos[1].y = gl_vector_font[rank].edge[c].y1 + start.y + 2;
	  pos[0].y = gl_vector_font[rank].edge[c].y0 + start.y + 2;
	  tekline(pix, &pos[0], &color[0]);
	}
    }
}
