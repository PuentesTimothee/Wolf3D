/*
** my_strcat.c for  in /home/puente_t/rendu/Piscine_C_J07/ex_02
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Tue Oct  6 10:53:38 2015 Timothée Puentes
** Last update Fri Nov 27 15:30:29 2015 puente_t
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	c;
  char	*end_dest;

  c = 0;
  while (dest[c] != '\0')
    c++;
  end_dest = dest + c;
  c = 0;
  while (src[c] !='\0')
    {
      end_dest[c] = src[c];
      c++;
    }
  end_dest[c] = '\0';
  return (dest);
}
