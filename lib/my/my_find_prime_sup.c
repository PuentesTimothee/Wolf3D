/*
** my_find_prime_sup.c for  in /home/puente_t/rendu/Piscine_C_J05
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Fri Oct  2 16:39:24 2015 Timothée Puentes
** Last update Fri Oct 30 11:57:59 2015 Timothée Puentes
*/

#include "my.h"

int	loop_prime(int nb)
{
  int	is_prime_bool;

  is_prime_bool = my_is_prime(nb);
  if (is_prime_bool == 1)
    return (nb);
  nb++;
  loop_prime(nb);
  return (nb);
}

int	my_find_prime_sup(int nb)
{
  int	nb_sup;

  nb_sup = loop_prime(nb);
  return (nb_sup);
}
