/*
** my_putchar.c for  in /home/puente_t/rendu/Piscine_C_J07/lib/my
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Tue Oct  6 09:10:45 2015 Timothée Puentes
** Last update Sun Nov  1 16:44:28 2015 Timothée Puentes
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putchar_error(char c)
{
  write (2, &c, 1);
}
