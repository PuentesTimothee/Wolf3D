/*
** my_str_islower.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_13
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 16:44:31 2015 Timothée Puentes
** Last update Fri Oct  9 19:33:28 2015 Timothée Puentes
*/

int	my_str_islower(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 97 || str[c] > 122)
        {
          return (0);
        }
      c++;
    }
  return (1);
}
