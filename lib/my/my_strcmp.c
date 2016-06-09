/*
** my_strcmp.c for  in /home/puente_t/rendu/Piscine_C_J06/ex_06
**
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
**
** Started on  Mon Oct  5 13:26:54 2015 Timothée Puentes
** Last update Wed Nov 25 19:09:44 2015 Timothee Puentes
*/

int	my_strcmp(char *s1, char *s2)
{
  int	c;
  char	ascii_s1;
  char	ascii_s2;

  c = 0;
  while (*(s1 + c) != '\0' && *(s2 + c) != '\0')
    {
      ascii_s1 = s1[c];
      if (ascii_s1 > 96 && ascii_s1 < 123)
	ascii_s1 = ascii_s1 - 32;
      ascii_s2 = s2[c];
      if (ascii_s2 > 96 && ascii_s2 < 123)
	ascii_s2 = ascii_s2 - 32;
      if (ascii_s1 != ascii_s2)
	return (ascii_s1 - ascii_s2);
      c++;
    }
  if (*(s1 + c) == '\0' && *(s2 + c) != '\0')
    return (1);
  else if (*(s2 + c) == '\0' && *(s1 + c) != '\0')
    return (-1);
  return (0);
}
