/*
** my_str_isnum.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_12
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Oct  5 16:42:00 2015 Timothée Puentes
** Last update Thu Nov 19 11:17:39 2015 Timothée Puentes
*/

int	my_str_isnum(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] >= '0' && str[c] <= '9')
        {
          return (0);
        }
      c++;
    }
  return (1);
}
