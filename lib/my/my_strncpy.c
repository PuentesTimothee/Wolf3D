/*
** my_strncpy.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_03
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Oct  5 10:41:16 2015 Timothée Puentes
** Last update Thu Nov 26 12:24:54 2015 Timothee Puentes
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	c;

  c = 0;
  while (src[c] != '\0' && n > c)
    {
      dest[c] = src[c];
      c++;
    }
  dest[c] = '\0';
  return (dest);
}
