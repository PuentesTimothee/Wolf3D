/*
** my_strlowercase.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_09
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 15:50:47 2015 Timothée Puentes
** Last update Fri Oct  9 19:37:19 2015 Timothée Puentes
*/

char	*my_strlowercase(char *str)
{
  int	c;

  c = 0;
  while (str[c] != '\0')
    {
      if (str[c] > 64 && str[c] < 91)
        str[c] = str[c] + 32;
      c++;
    }
  return (str);
}
