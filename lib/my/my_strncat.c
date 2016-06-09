/*
** my_strncat.c for  in /home/puente_t/rendu/Piscine_C_J07/ex_03
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Tue Oct  6 11:04:25 2015 Timothée Puentes
** Last update Fri Oct  9 19:38:15 2015 Timothée Puentes
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	c;
  char	*end_dest;

  end_dest = dest + nb;
  c = 0;
  while (src[c] != '\0')
    {
      end_dest[c] = src[c];
      c++;
    }
  while (dest[c] != '\0')
    {
      end_dest[c] = '\0';
      c++;
    }
  end_dest[c] = '\0';
  return (dest);
}
