/*
** my_str_isupper.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_14
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 16:47:39 2015 Timothée Puentes
** Last update Fri Oct  9 19:36:05 2015 Timothée Puentes
*/

int	my_str_isupper(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 65 || str[c] > 90)
        {
          return (0);
        }
      c++;
    }
  return (1);
}
