/*
** my_strcapitalize.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_10
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Oct  5 15:56:06 2015 Timothée Puentes
** Last update Fri Nov  6 10:39:57 2015 Puentes Timothee
*/

char	*my_strcapitalize(char *str)
{
  int	c;

  c = 0;
  if (str[c] > 96 && str[c] < 123)
    str[c] = str[c] - 32;
  c++;
  while (str[c] != '\0')
    {
      if (str[c - 1] < 65 || str[c - 1] > 122)
	  if (str[c] > 96 && str[c] < 123)
	    str[c] = str[c] - 32;
      if (str[c - 1] > 90 && str[c - 1] < 97)
	{
	  if (str[c] > 96 && str[c] < 123)
	    str[c] = str[c] - 32;
	}
      else
	{
	  if (str[c] > 64 && str[c] < 91)
	    str[c] = str[c] + 32;
	}
      c++;
    }
  return (str);
}
