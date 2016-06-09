/*
** my_put_nbr.c for  in /home/puente_t/rendu/Piscine_C_J03
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Wed Sep 30 14:47:49 2015 Timothée Puentes
** Last update Thu Nov  5 08:30:57 2015 puente_t
*/

#include "my.h"

int	my_put_unbr(unsigned int nb)
{
  int	lenght;
  int	s;
  char	number;

  lenght = get_intlenght(nb, 10);
  s = lenght;
  if (nb < 0)
    {
      nb = -1 * nb;
      my_putchar(45);
    }
  while (nb >= 10)
    {
      number = nb / my_power_it(10, lenght - 1);
      my_putchar(number + 48);
      nb = nb % my_power_it(10, lenght - 1);
      lenght = lenght - 1;
    }
  my_putchar(nb + 48);
  return (s);
}
