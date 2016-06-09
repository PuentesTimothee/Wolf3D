/*
** my_strdup.c for  in /home/puente_t/rendu/Piscine_C_J08/ex_01
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Oct  7 09:14:42 2015 Timothée Puentes
** Last update Tue Dec 22 14:51:06 2015 puente_t
*/

#include <lapin.h>
#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  char	*dest;
  int	lenght;

  lenght = my_strlen(src) + 1;
  if ((dest = bunny_malloc(lenght)) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
