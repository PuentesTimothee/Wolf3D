/*
** my_str_isalpha.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_11
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 16:37:20 2015 Timothée Puentes
** Last update Sun Nov  1 19:58:45 2015 axel vienne
*/

int	my_str_isalpha(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] < 65 || str[c] > 122)
        return (0);
      if (str[c] > 90 && str[c] < 97)
	return (0);
      c++;
    }
  return (1);
}
