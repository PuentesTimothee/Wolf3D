/*
** my_str_to_wordtab.c for  in /home/puente_t/rendu/Piscine_C_J08/ex_04
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Oct  7 12:02:39 2015 Timothée Puentes
** Last update Fri Nov  6 13:24:43 2015 Timothée Puentes
*/

#include <stdlib.h>
#include "my.h"

void	copy_array(char *dest, char *src, int place)
{
  int	c;
  int	lenght;

  c = place;
  while ((src[c] > 64 && src[c] < 91) || (src[c] > 96 && src[c] < 123))
    c++;
  lenght = c - place;
  my_strncpy(dest, src + place, lenght);
}

char	**my_str_to_wordtab(char *str)
{
  return (NULL);
}
