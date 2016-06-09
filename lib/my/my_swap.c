/*
** my_swap.c for  in /home/puente_t/rendu/Piscine_C_J04
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Thu Oct  1 09:31:00 2015 Timothée Puentes
** Last update Fri Oct 30 12:12:38 2015 Timothée Puentes
*/

#include "my.h"

void	my_swap(char *a, char *b)
{
  char	c;

  c = *b;
  *b = *a;
  *a = c;
}
