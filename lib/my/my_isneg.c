/*
** my_isneg.c for  in /home/puente_t/rendu/Piscine_C_J03
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Wed Sep 30 10:12:15 2015 Timothée Puentes
** Last update Fri Oct 30 12:00:14 2015 Timothée Puentes
*/

#include "my.h"

int	my_isneg(int nb)
{
  if (nb < 0)
      my_putchar('N');
  else
      my_putchar('P');
  return (0);
}
