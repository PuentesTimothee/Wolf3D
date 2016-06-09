/*
** my_strupcase.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_08
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 15:18:29 2015 Timothée Puentes
** Last update Wed Oct  7 08:42:49 2015 Timothée Puentes
*/

char	*my_strupcase(char *str)
{
  int	c;

  c = 0;
  while (*(str + c) != '\0')
    {
      if (str[c] > 96 && str[c] < 123)
        str[c] = str[c] - 32;
      c++;
    }
  return (str);
}
