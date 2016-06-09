/*
** my_atoi.c for  in /home/timothee/rendu/CPE_2020_Pushswap
**
** Made by Puentes
** Login   <timothee@epitech.net>
**
** Started on  Tue Nov  3 14:48:09 2015 Puentes
** Last update Mon Nov 23 13:32:12 2015 Timothee Puentes
*/

#include "my.h"

unsigned int	my_uatoi(char *str)
{
  int		c;
  unsigned int	result;
  int		size;

  c = 0;
  result = 0;
  size = my_strlen(str);
  while (size - c - 1 >= 0)
    {
      result = result + (my_power_it(10, c) * (str[size - c - 1] - '0'));
      c++;
    }
  return (result);
}

int	my_atoi(char *str)
{
  int	c;
  int	result;
  int	size;
  int	neg;

  neg = 0;
  c = 0;
  result = 0;
  size = my_strlen(str);
  if (str[0] == '-')
    neg = 1;
  while (size - c - 1 >= neg)
    {
      result = result + (my_power_it(10, c) * (str[size - c - 1] - '0'));
      c++;
    }
  if (str[0] == '-')
    result = result * -1;
  return (result);
}
