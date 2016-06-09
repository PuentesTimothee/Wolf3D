/*
** my_str_isprintable.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_15
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 16:55:00 2015 Timothée Puentes
** Last update Fri Oct  9 19:35:19 2015 Timothée Puentes
*/

int	my_str_isprintable(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 32 || str[c] > 126)
        {
          return (0);
        }
      c++;
    }
  return (1);
}
