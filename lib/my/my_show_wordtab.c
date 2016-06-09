/*
** my_show_wordtab.c for  in /home/puente_t/rendu/Piscine_C_J08/ex_03
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Wed Oct  7 11:20:34 2015 Timothée Puentes
** Last update Fri Oct 30 12:07:21 2015 Timothée Puentes
*/

#include "my.h"

void	my_show_wordtab(char **tab)
{
  int	c;

  c = 0;
  while (tab[c] != '\0')
    {
      my_putstr(tab[c]);
      my_putchar(10);
      c++;
    }
}
