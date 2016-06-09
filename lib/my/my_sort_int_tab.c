/*
** my_sort_int_tab.c for  in /home/puente_t/rendu/Piscine_C_J07/lib/my
** 
** Made by Timothée Puentes
** Login   <puente_t@epitech.net>
** 
** Started on  Tue Oct  6 13:07:42 2015 Timothée Puentes
** Last update Fri Oct  9 19:16:48 2015 Timothée Puentes
*/

void	move_array_to_the_right(int *tab, int size, int place_to_free)
{
  int	c;

  c = size;
  while (c > place_to_free)
    {
      tab[c] = tab[c - 1];
      c--;
    }
}

void	place_int(int value, int *tab, int size)
{
  int	c;

  c = 0;
  while (c < size)
    {
      if (value <= tab[c])
	{
	  move_array_to_the_right(tab, size, c);
	  tab[c] = value;
	  return ;
	}
      c++;
    }
  tab[c] = value;
}

void	my_sort_int_tab(int *tab, int size)
{
  int	temporary_tab[size];
  int	c;

  c = 0;
  while (c <= size)
    {
      temporary_tab[c] = 2147483647;
      c++;
    }
  c = 0;
  while (c <= size)
    {
      place_int(tab[c], temporary_tab, size);
      c++;
    }
  c = 0;
  while (c <= size)
    {
      tab[c] = temporary_tab[c];
      c++;
    }
}
