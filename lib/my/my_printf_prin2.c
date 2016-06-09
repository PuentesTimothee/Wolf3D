/*
** my_printf_prin2.c for  in /home/puente_t/rendu/PSU_2015_my_printf/lib/my
**
** Made by Puentes Timothee
** Login   <puente_t@epitech.net>
**
** Started on  Fri Nov  6 10:33:05 2015 Puentes Timothee
** Last update Thu Nov 12 10:47:48 2015 Timothée Puentes
*/

#include "my.h"

int		print_uint(va_list arg, int printed)
{
  unsigned int	res;
  unsigned int	lenght;

  res = va_arg(arg, unsigned int);
  lenght = get_ulonglenght((long)res, 10);
  printed = lenght;
  my_putnbr_printf(res, lenght, "0123456789");
  return (printed);
}

int		print_uint_bi(va_list arg, int printed)
{
  unsigned int	res;
  unsigned int	lenght;

  res = va_arg(arg, unsigned int);
  lenght = get_ulonglenght((long)res, 2);
  printed = lenght;
  my_putnbr_printf(res, lenght, "01");
  return (printed);
}

int		print_uint_oct(va_list arg, int printed)
{
  unsigned int	res;
  unsigned int	lenght;

  res = va_arg(arg, unsigned int);
  lenght = get_ulonglenght((long)res, 8);
  printed = lenght;
  my_putnbr_printf(res, lenght, "01234567");
  return (printed);
}

int		print_uint_hexa_c(va_list arg, int printed)
{
  unsigned int	res;
  unsigned int	lenght;

  res = va_arg(arg, unsigned int);
  lenght = get_ulonglenght((long)res, 16);
  printed = lenght;
  my_putnbr_printf(res, lenght, "0123456789ABCDEF");
  return (printed);
}

int		print_uint_hexa_l(va_list arg, int printed)
{
  unsigned int	res;
  int		lenght;

  res = va_arg(arg, unsigned int);
  lenght = get_ulonglenght((long)res, 16);
  printed = lenght;
  my_putnbr_printf(res, lenght, "0123456789abcdef");
  return (printed);
}
