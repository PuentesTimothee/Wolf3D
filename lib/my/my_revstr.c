/*
** my_revstr.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_04
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 11:09:26 2015 Timothée Puentes
** Last update Sun Nov  1 19:54:15 2015 axel vienne
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	c;
  int	size;

  size = 0;
  c = 0;
  while (*(str  + size) != '\0')
    size++;
  size--;
  while (*(str + c * 2) != '\0')
    {
      my_swap(str + c, str + size - c);
      c++;
    }
  return (str);
}
