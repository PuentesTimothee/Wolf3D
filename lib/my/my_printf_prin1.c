/*
** my_printf_prin1.c for my_printf in /home/timothee/rendu/PSU_2015_my_printf/lib/my
**
** Made by puente_t
** Login   <timothee@epitech.net>
**
** Started on  Wed Nov  4 13:51:47 2015 puente_t
** Last update Tue Nov 17 12:19:18 2015 Timothée Puentes
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	print_str(va_list arg, int printed)
{
  char	*str;

  str = va_arg(arg, char*);
  printed = my_putstr(str);
  return (printed);
}

int	print_str_unp(va_list arg, int printed)
{
  char	*str;
  int	c;
  int	n;

  printed = 0;
  str = va_arg(arg, char*);
  if (str == NULL)
    return (my_putstr("(null)"));
  c = 0;
  n = 0;
  while (c < sizeof(str))
    {
      while (IS_NUM(str[c + n]) && (c + n) < sizeof(str))
	n++;
      if (n > 0)
	write(1, &str[c], n);
      c = c + n;
      printed += n;
      if (c >= sizeof(str) || str[c] == '\0')
	return (printed);
      my_putchar('\\');
      printed += 1 + my_putnbr_printf((int)(str[c]), 3, "01234567");
      c++;
    }
  return (printed);
}

int	print_int(va_list arg, int printed)
{
  printed = my_put_nbr(va_arg(arg, int));
  return (printed);
}

int	print_char(va_list arg, int printed)
{
  my_putchar(va_arg(arg, int));
  return (1);
}
