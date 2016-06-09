/*
** my_getnbr.c for  in /home/puente_t/rendu/Piscine_C_J07/lib/my
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Tue Oct  6 12:07:46 2015 Timothée Puentes
** Last update Fri Oct 30 11:58:24 2015 Timothée Puentes
*/

#include "my.h"

int	nbr_is_neg(char *str)
{
  int	c;
  int	signe;

  signe = 0;
  c = 0;
  while (str[c] > '9' || str[c] < '0')
    {
      if (str[c] == '-')
	signe++;
      c++;
    }
  if (signe % 2 != 0)
    return (1);
  return (0);
}

int	my_getnbrn(char *str, int n)
{
  int	c;
  int	nbr;

  c = 0;
  while (str[c] == '-' || str[c] == '+')
    c++;
  while (((str[c] <= '9' || str[c] >= '0') && str[c] != '\0') && c < n)
    {
      nbr = (nbr * 10 + (str[c] - '0'));
      c++;
    }
  if (nbr_is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}

int	my_getnbr(char *str)
{
  int	c;
  int	nbr;

  c = 0;
  while (str[c] == '-' || str[c] == '+')
    c++;
  while ((str[c] <= '9' || str[c] >= '0') && str[c] != '\0')
    {
      nbr = (nbr * 10 + (str[c] - '0'));
      c++;
    }
  if (nbr_is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
