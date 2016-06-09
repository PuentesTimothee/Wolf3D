/*
** my_strlen.c for  in /home/puente_t/rendu/Piscine_C_J04
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Oct  1 12:54:07 2015 Timothée Puentes
** Last update Fri Nov 27 14:58:24 2015 puente_t
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	n;

  if (str == NULL)
    return (0);
  n = 0;
  while (str[n] != '\0')
    n++;
  return (n);
}
