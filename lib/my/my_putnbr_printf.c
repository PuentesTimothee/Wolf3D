/*
** my_putnbr_printf.c for  in /home/puente_t/rendu/PSU_2015_my_printf/lib/my
**
** Made by Puentes Timothee
** Login   <puente_t@epitech.net>
**
** Started on  Fri Nov  6 10:32:42 2015 Puentes Timothee
** Last update Mon Nov 16 10:36:10 2015 Timothée Puentes
*/

#include "my.h"

int		get_ulonglenght(unsigned long nb, int base)
{
  int		c;

  c = 0;
  if (nb < 0)
    nb = -nb;
  while (nb >= 1)
    {
      nb = nb / base;
      c++;
    }
  return (c);
}

int		my_putnbr_printf(unsigned int nb, int lenght, char *b)
{
  int		number;
  int		base;
  int		s;

  s = lenght;
  base = my_strlen(b);
  if (nb < 0)
    {
      nb = -1 * nb;
      my_putchar(45);
    }
  while (lenght > 1)
    {
      number = nb / my_power_it(base, lenght - 1);
      my_putchar(b[number]);
      nb = nb % my_power_it(base, lenght - 1);
      lenght--;
    }
  my_putchar(b[nb]);
  return (s);
}

int		my_putulong_printf(unsigned long  nb, int lenght, char *b)
{
  int		number;
  int		base;
  int		s;

  s = lenght;
  base = my_strlen(b);
  while (lenght > 1)
    {
      number = nb / my_power_uit(base, lenght - 1);
      my_putchar(b[number]);
      nb = nb % my_power_uit(base, lenght - 1);
      lenght--;
    }
  my_putchar(b[nb]);
  return (s);
}
