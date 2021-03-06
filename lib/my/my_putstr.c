/*
** my_putstr.c for  in /home/puente_t/rendu/Piscine_C_J04
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Thu Oct  1 10:49:06 2015 Timothée Puentes
** Last update Tue Nov 17 11:27:17 2015 Timothée Puentes
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	l;

  if (str == NULL)
    {
      write(1, "(null)", 5);
      return (6);
    }
  l = my_strlen(str);
  write(1, str, l);
  return (l);
}

void	my_putstr_error(char *str)
{
  if (str == NULL)
    {
      write(2, "(null)", 5);
      return ;
    }
  write(2, str, my_strlen(str));
}

void	my_putstrn(char *str)
{
  if (str == NULL)
    {
      write(1, "(null)", 5);
      return ;
    }
  write(1, str, my_strlen(str));
  my_putchar('\n');
}
