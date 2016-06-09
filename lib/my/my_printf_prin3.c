/*
** my_printf_prin3.c for  in /home/puente_t/rendu/PSU_2015_my_printf/lib/my
**
** Made by Puentes Timothee
** Login   <puente_t@epitech.net>
**
** Started on  Fri Nov  6 10:33:19 2015 Puentes Timothee
** Last update Thu Nov 19 11:20:06 2015 Timothée Puentes
*/

#include <unistd.h>
#include "my.h"

int		print_error(va_list arg, int printed)
{
  return (printed);
}

int		print_void(va_list arg, int printed)
{
  void		*ptr;
  int		lenght;

  ptr = va_arg(arg, void*);
  if (ptr == NULL)
    {
      my_putstr("(null)");
      printed += 5;
    }
  else
    {
      lenght = get_ulonglenght((unsigned long)(ptr), 16);
      printed = lenght + 2;
      my_putstr("0x");
      my_putulong_printf((unsigned long)(ptr), lenght, "0123456789ABCDEF");
    }
  return (printed);
}

int		print_assign(va_list arg, int printed)
{
  int		*a;

  a = va_arg(arg, int*);
  *a = printed;
  return (0);
}
