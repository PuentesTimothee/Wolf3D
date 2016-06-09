/*
** my_strcpy.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_02
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Oct  5 09:04:13 2015 Timothée Puentes
** Last update Thu Nov 26 12:22:08 2015 Timothee Puentes
*/

char	*my_strcpy(char *dest, char *src)
{
  int	c;

  c = 0;
  while (src[c] != '\0')
    {
      dest[c] = src[c];
      c++;
    }
  dest[c] = '\0';
  return (dest);
}
