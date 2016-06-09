/*
** my_square_root.c for  in /home/puente_t/rendu/Piscine_C_J05
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Fri Oct  2 13:11:42 2015 Timothée Puentes
** Last update Thu Nov  5 12:57:42 2015 puente_t
*/

int	my_square_root(int nb)
{
  int	result;
  int	c;

  c = 0;
  result = 0;
  while (result < nb)
    {
      c++;
      result = c * c;
    }
  if (result == nb)
    return (c);
  else
    return (0);
}
