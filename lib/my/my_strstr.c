/*
** my_strstr.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_05
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 11:45:47 2015 Timothée Puentes
** Last update Sun Nov  1 20:02:40 2015 axel vienne
*/

#include "my.h"

char	corresponding_test(char *str1, char *str2)
{
  int	c;

  c = 0;
  while (str1[c] == str2[c])
    {
      c++;
    }
  if (str2[c] == '\0')
    return (1);
  else
    return (0);
}

char	*my_strstr(char *str, char *to_find)
{
  int	c;
  char	correspond;
  char	*pointer;

  c = 0;
  correspond = 0;
  while (str[c] != '\0')
    {
      if (str[c] == to_find[0])
	correspond = corresponding_test(str + c, to_find);
      if (correspond == 1)
	{
	  pointer = str + c;
	  return (pointer);
	}
      c++;
    }
  return (0);
}
