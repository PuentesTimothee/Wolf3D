/*
** my_printf.c for  in /home/puente_t/rendu/PSU_2015_my_printf/lib/my
**
** Made by Puentes Timothee
** Login   <puente_t@epitech.net>
**
** Started on  Fri Nov  6 10:32:32 2015 Puentes Timothee
** Last update Sat Nov 14 17:45:50 2015 Timothée Puentes
*/

#include <unistd.h>
#include "my.h"

int		find_rank(char s)
{
  char		cmp[13] = "idsSuboxXcpnm";
  int		c;

  c = 0;
  while (cmp[c] != '\0')
    {
      if (s == cmp[c])
	{
	  if (c == 0)
	    return (c);
	  return (c - 1);
	}
      c++;
    }
  return (-1);
}

int		start_check(char *s, int c, va_list arg, int printed)
{
  int		(*print[12])(va_list, int);
  int		rank;

  while (s[c + 1] == ' ' && s[c + 1] != '\0')
    c++;
  print[0] = print_int;
  print[1] = print_str;
  print[2] = print_str_unp;
  print[3] = print_uint;
  print[4] = print_uint_bi;
  print[5] = print_uint_oct;
  print[6] = print_uint_hexa_l;
  print[7] = print_uint_hexa_c;
  print[8] = print_char;
  print[9] = print_void;
  print[10] = print_assign;
  print[11] = print_error;
  if (c + 1 > my_strlen(s))
    return (printed);
  else if ((rank = find_rank(s[c + 1])) >= 0)
    printed = printed + print[rank](arg, printed);
  return (printed);
}

int		my_putstr_printf(char *s, int c)
{
  int		n;

  if (s == NULL)
    {
      my_putstr("(null)");
      return (6);
    }
  n = 0;
  while (s[c + n] != '%' && (c + n) < my_strlen(s))
    n++;
  if (n > 0)
    write(1, &s[c], n);
  c = c + n;
  return (c);
}

int	pcase(char *s, int c, int *printed)
{
  while (s[c + 1] == ' ')
    c++;
  if (s[c + 1] == '%' || s[c + 1] == '\0')
    {
      my_putchar('%');
      *printed = *printed + 1;
      return (c + 2);
    }
  else if (find_rank(s[c + 1]) >= 0)
    return (c + 2);
  my_putchar('%');
  my_putchar(s[c]);
  *printed = *printed + 2;
  return (c + 1);
}

int		my_printf(char *s, ...)
{
  int		c;
  va_list	arg;
  int		printed;
  int		c_b;

  if (s == NULL)
    return (my_putstr("(null)\n"));
  c = 0;
  c_b = c;
  va_start(arg, s);
  printed = 0;
  while (c < my_strlen(s))
    {
      c = my_putstr_printf(s, c);
      printed = printed + (c - c_b);
      if (c >= my_strlen(s))
	return (printed);
      else if (s[c] == '%')
	printed = start_check(s, c, arg, printed);
      c = pcase(s, c, &printed);
      c_b = c;
    }
  va_end(arg);
  return (printed);
}
