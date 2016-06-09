/*
** my_power_rec.c for  in /home/puente_t/rendu/Piscine_C_J05
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Fri Oct  2 12:26:33 2015 Timothée Puentes
** Last update Thu Nov  5 11:25:44 2015 puente_t
*/

int		my_power_it(int nb, int power)
{
  int		c;
  int		result;

  c = 0;
  result = 1;
  while (c != power)
    {
      result = result * nb;
      c++;
    }
  return (result);
}

unsigned long	my_power_uit(int nb, int power)
{
  int		c;
  unsigned long	result;

  c = 0;
  result = 1;
  while (c != power)
    {
      result = result * nb;
      c++;
    }
  return (result);
}

int		loop_power(int nb, int power, int c)
{
  if (c == power)
    return (nb);
  c++;
  nb = loop_power(nb, power, c);
  return (nb);
}

int		my_power_rec(int nb, int power)
{
  int		c;
  int		result;

  result = 1;
  c = 0;
  result = loop_power(nb , power, c);
  return (result);
}
