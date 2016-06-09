/*
** my_strncmp.c for $ in /home/puente_t/rendu/Piscine_C_J06/ex_07
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Mon Oct  5 15:17:00 2015 Timothée Puentes
** Last update Fri Oct  9 19:39:58 2015 Timothée Puentes
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	c;
  char	ascii_s1;
  char	ascii_s2;

  c = 0;
  while (s1[c] != '\0' && s2[c] != '\0' && c <= n)
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
  return (0);
}
