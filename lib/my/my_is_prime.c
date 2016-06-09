/*
** my_is_prime.c for  in /home/puente_t/rendu/Piscine_C_J05
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Fri Oct  2 13:45:14 2015 Timothée Puentes
** Last update Thu Nov  5 12:58:14 2015 puente_t
*/

int	my_is_prime(int nb)
{
  int	c;

  c = 0;
  if (nb == 0 || nb == 1)
    return (0);
  while (c < nb)
    {
      c++;
      if (nb % c == 0)
	return (0);
    }
  return (1);
}
